#include "views/BoardView.hpp"
#include "views/PawnView.hpp"
#include "views/KingView.hpp"
#include "views/BishopView.hpp"
#include "views/KnightView.hpp"
#include "views/QueenView.hpp"
#include "views/RookView.hpp"
#include "helpers/HelperFunctions.hpp"

/**
 * Draws the board, for debugging purposes.
 * 
 */
void BoardView::drawBoard()
{
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if(this->boardConfiguration[i][j].compare(" ") == 0)
			{
				std::cout << "  .  ";
			}
			else
			{
				std::cout << "  " << this->boardConfiguration[i][j] << " ";
			}
		}

		std::cout << std::endl;
	}
}

/**
 * Loads a provided configuration.
 * @param std::string**
 * 
 */
void BoardView::loadBoard(std::string** board)
{
	for (int i = 0; i < 64; ++i)
	{
		this->boardConfiguration[i/8][i%8] = board[i/8][i%8];
	}
}

/**
 * Constructor and destructor
 * 
 */
BoardView::BoardView(std::string** xboard)
:View("", 0, 0, 0, 0)
{
	this->pieces      = new PieceView**[8];
	this->activePiece = NULL;
	this->activePieceCoordinates = new int[2]{-1 , -1};
	this->myRect.h    = View::SCREEN_HEIGHT;
	this->myRect.w    = View::SCREEN_WIDTH;

	this->loadBoard(xboard);

	for (int i = 0; i < 8; ++i) {
	  this->pieces[i] = new PieceView*[8];
	}

	for (int i = 0; i < 8; ++i) {
	  for (int j = 0; j < 8; ++j) {
	    this->pieces[i][j] = NULL;
	  }
	}

	try
	{
		this->init();
	}
	catch(std::string e)
	{
		std::stringstream exception;

		exception << "BoardViewInitException: Exception caught during board initalization: " << std::endl;
		exception << "\t" << e << std::endl;

		throw exception.str();
	}
}

BoardView::~BoardView()
{
	for (int i = 0; i < 64; ++i)
	{
		if(NULL != this->pieces[i/8][i%8])
		{
			delete this->pieces[i/8][i%8];
		}
	}
}

/**
 * Initializes the squares.
 * 
 */
bool BoardView::initSquares()
{
	/* Black Square */
	try
	{
		this->squares[0] = new SquareView(false, 80, 80);	
	}
	catch(std::string e)
	{
		throw e;
	}

	/* White Square */
	try
	{
		this->squares[1] = new SquareView(true, 80, 80);	
	}
	catch(std::string e)
	{
		throw e;
	}

}

/**
 * Initializes the squares.
 * =========================
 *
 * This method will generate pieces according to a certain configuration passed over from the backend.
 * However, for now, it will be rendering pieces statically.
 * 
 */
bool BoardView::initPieces()
{
	try
	{
		std::string pieceName;

		for (int i = 0; i < 64; ++i)
		{
			pieceName = this->boardConfiguration[i/8][i%8];

			if(pieceName.compare("bP") == 0)
			{
				this->pieces[i/8][i%8] = new PawnView(false, pieceName, (i%8)*80, (i/8)*80, 80, 80);
			}
			else
			if(pieceName.compare("bR") == 0)
			{
				this->pieces[i/8][i%8] = new RookView(false, pieceName, (i%8)*80, (i/8)*80, 80, 80);
			}
			else
			if(pieceName.compare("bN") == 0)
			{
				this->pieces[i/8][i%8] = new KnightView(false, pieceName, (i%8)*80, (i/8)*80, 80, 80);
			}
			else
			if(pieceName.compare("bB") == 0)
			{
				this->pieces[i/8][i%8] = new BishopView(false, pieceName, (i%8)*80, (i/8)*80, 80, 80);
			}
			else
			if(pieceName.compare("bK") == 0)
			{
				this->pieces[i/8][i%8] = new KingView(false, pieceName, (i%8)*80, (i/8)*80, 80, 80);
			}
			else
			if(pieceName.compare("bQ") == 0)
			{
				this->pieces[i/8][i%8] = new QueenView(false, pieceName, (i%8)*80, (i/8)*80, 80, 80);
			}
			else
				/********** White pieces **********/
			if(pieceName.compare("wP") == 0)
			{
				this->pieces[i/8][i%8] = new PawnView(true, pieceName, (i%8)*80, (i/8)*80, 80, 80);
			}
			else
			if(pieceName.compare("wR") == 0)
			{
				this->pieces[i/8][i%8] = new RookView(true, pieceName, (i%8)*80, (i/8)*80, 80, 80);
			}
			else
			if(pieceName.compare("wN") == 0)
			{
				this->pieces[i/8][i%8] = new KnightView(true, pieceName, (i%8)*80, (i/8)*80, 80, 80);
			}
			else
			if(pieceName.compare("wB") == 0)
			{
				this->pieces[i/8][i%8] = new BishopView(true, pieceName, (i%8)*80, (i/8)*80, 80, 80);
			}
			else
			if(pieceName.compare("wK") == 0)
			{
				this->pieces[i/8][i%8] = new KingView(true, pieceName, (i%8)*80, (i/8)*80, 80, 80);
			}
			else
			if(pieceName.compare("wQ") == 0)
			{
				this->pieces[i/8][i%8] = new QueenView(true, pieceName, (i%8)*80, (i/8)*80, 80, 80);
			}
		}
	}
	catch(std::string e)
	{
		throw e;
	}
}

/**
 * Initializes the BoardView with all the needed component views.
 * @return boolean
 * 
 */
bool BoardView::init()
{
	try
	{
		this->initSquares();
	}
	catch(std::string e)
	{
		throw e;
	}

	try
	{
		this->initPieces();
	}
	catch(std::string e)
	{
		throw e;
	}
}

/**
 * Initializes the squares.
 * 
 */
void BoardView::renderSquares()
{
	bool color = true;

	for (int i = 0; i < 8; ++i, color=!color)
	{
		for (int j = 0; j < 8; ++j, color = !color)
		{
			if(color)
			{
				this->squares[1]->render(j*80, i*80);
			}
			else
			{
				this->squares[0]->render(j*80, i*80);
			}
		}
	}
}

/**
 * Removes the pieces.
 * 
 */
void BoardView::destructPieces()
{
	for (int i = 0; i < 64; ++i)
	{
		if(NULL != this->pieces[i/8][i%8])
		{
			delete this->pieces[i/8][i%8];

			this->pieces[i/8][i%8] = NULL;
		}
	}
}

/**
 * Updates thep pieces from the boardConfiguration
 * 
 */
void BoardView::updatePieces()
{
	/**
	 * If there is a piece that is moving, the renderer would be in "input-mode"
	 * So, we will be rendering the real time changes.
	 *
	 * Once there is no movement, the renderer would be in "output-mode", rendering the board's configuration.
	 */
	if(!this->isThereAMovingPiece())
	{
		this->destructPieces();

		try
		{
			this->initPieces();
		}
		catch(std::string e)
		{
			throw e;
		}
	}
}

/**
 * Initializes the squares.
 * 
 */
void BoardView::renderPieces()
{
	try
	{
		this->updatePieces();
	}
	catch(std::string e)
	{
		throw e;
	}

	for (int i = 0; i < 64; ++i)
	{
		if(this->pieces[i/8][i%8] != NULL)
		{
			this->pieces[i/8][i%8]->render();
		}
	}
}

/**
 * Renders the actual view to the screen.
 * 
 */
void BoardView::render()
{
	try
	{
		this->renderSquares();
		this->renderPieces();
	}
	catch(std::string e)
	{
		throw e;
	}
}

/**
 * Self-descriptive
 * @param PieceView*
 * 
 */
void BoardView::registerMovingPiece(PieceView* piece)
{
	this->activePiece = piece;
	this->activePieceCoordinates[0] = piece->getX();
	this->activePieceCoordinates[1] = piece->getY();
}

/**
 * Self-descriptive
 * @param PieceView*
 * 
 */
void BoardView::forgetMovingPiece()
{
	this->activePiece = NULL;
	this->activePieceCoordinates[0] = -1;
	this->activePieceCoordinates[1] = -1;
}

/**
 * Self-descriptive
 * @return [description]
 * 
 */
PieceView* BoardView::getMovingPiece()
{
	return this->activePiece;
}

/**
 * Self-descriptive.
 * @return boolean
 * 
 */
bool BoardView::isThereAMovingPiece()
{
	return this->activePiece != NULL;
}

/**
 * Gets the piece that is holding the square at (x, y) coordinates.
 * @return [description]
 * 
 */
PieceView* BoardView::getPieceAt(int& x, int& y)
{
	for (int i = 0; i < 64; ++i)
	{
		int piece_x = (i%8) * 80;
		int piece_y = (i/8) * 80;

		if(HelperFunctions::checkCollision(x, y, piece_x, piece_y))
		{
			return this->pieces[i/8][i%8];
		}
	}
}

/**
 * Returns the exact coordinates of the square that collides with the provided coordinates.
 * @param  x int
 * @param  y int
 * @return   int* : array
 */
int* BoardView::getSquareAt(int& x, int& y)
{
	int* coordinates;

	for (int i = 0; i < 64; ++i)
	{
		int square_x = (i%8) * 80;
		int square_y = (i/8) * 80;

		if(HelperFunctions::checkCollision(x, y, square_x, square_y))
		{
			coordinates = new int[2]{square_x, square_y};
			return coordinates;
		}
	}
	
	coordinates = new int[2]{-1, -1};
	return coordinates;
}

/**
 * Puts the moving piece in the host square.
 * @param x int
 * @param y int
 * 
 */
void BoardView::bindMovingPieceToSquare(int& x, int& y)
{
	int old_i, old_j, new_i, new_j;

	old_i = this->activePieceCoordinates[1]/80;
	old_j = this->activePieceCoordinates[0]/80;

	new_i = y/80;
	new_j = x/80;

	PieceView* moving_piece = this->getMovingPiece();
	moving_piece->move(x, y);

	this->pieces[new_i][new_j] = moving_piece;
	this->pieces[old_i][old_j] = NULL;

	this->activePieceCoordinates[0] = x;
	this->activePieceCoordinates[1] = y;

	this->boardConfiguration[old_i][old_j] = " ";
	this->boardConfiguration[new_i][new_j] = moving_piece->getName();
}

/**
 * Binds the moving piece to its old position, in the screen and also in the boardCOnfiguration array.
 * 
 */
void BoardView::bindMovingPieceToPreviousPosition()
{
	PieceView* moving_piece = this->getMovingPiece();
	moving_piece->move(this->activePieceCoordinates[0], this->activePieceCoordinates[1]);
}

/**
 * Handles the click event.
 * @param e the SDL_Event object
 * 
 */
void BoardView::handleClickEvent(SDL_Event& e)
{
	int x, y;

    SDL_GetMouseState( &x, &y );

    if(e.type == SDL_MOUSEBUTTONDOWN)
	{
        PieceView* piecePtr = this->getPieceAt(x, y);

        if(piecePtr != NULL)
        {
	        this->registerMovingPiece(piecePtr);
        	piecePtr->move((x - 80)/2, (y - 80)/2);
        }
        else
        {
        	std::cout << "==================="<< std::endl << "Could not capture any piece at the clicked position." << std::endl << std::endl;
        }
	}

	if(e.type == SDL_MOUSEBUTTONUP)
	{
		if(this->isThereAMovingPiece())
		{
			std::cout << "There is a moving piece and it should now be released." << std::endl;

			int* coordinates = this->getSquareAt(x, y);

			if(coordinates[0] != -1 && coordinates[1] != -1)
			{
				std::cout << "Found a receipent square." << std::endl;
				this->bindMovingPieceToSquare(x, y);
			}
			else
			{
				std::cout << "Found no receipent square, moving the piece back to where it was." << std::endl;
				this->bindMovingPieceToPreviousPosition();
			}

			this->forgetMovingPiece();
			std::cout << "\t\t Piece is forgotten now." << std::endl;

			for (int i = 0; i < 8; ++i)
			{
				for (int j = 0; j < 8; ++j)
				{
					std::cout << this->boardConfiguration[i][j] << " ";
				}
				std::cout << std::endl;
				std::cout << " -  -  -  -  -  -  -  - " << std::endl;
			}
		}
		else
		{
			std::cout << "==================="<< std::endl << "There is no moving piece to forget." << std::endl;
		}
	}

    if(this->isThereAMovingPiece())
    {
    	PieceView* piecePtr = this->getMovingPiece();

    	std::cout << "There is moving piece" << std::endl;
    	piecePtr->move(x -40, y -40);
    }
}

/**
 * Handles the events related to this view, keyboard and mouse events.
 * @param e SDL_Event
 * 
 */
void BoardView::handleEvents(SDL_Event& e)
{
	this->handleClickEvent(e);
}