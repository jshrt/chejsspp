#ifndef _QUEEN_BOARD_H_INCLUDED_
#define _QUEEN_BOARD_H_INCLUDED_

#include "entities/AbstractBoardEntity.hpp"

class QueenBoard : public AbstractBoardEntity
{
	/*
	 |****************************
	 |		Attributes
	 |
	 |****************************
	 */

	/*
	 |****************************
	 |		Methodes
	 |
	 |****************************
	 */
	protected:
		/**
		 * Returns the file or the rank on which the move is taking place.
		 * @param  old_position [description]
		 * @param  new_position [description]
		 * @return              long
		 * 
		 */
		inline long identifyMoveField(long old_position, long new_position)
		{
			long historyOfMove = old_position | new_position;

			std::cout << "historyOfMove" << std::endl;
			HelperFunctions::drawArrayBoardFromBitBoard(historyOfMove);

			/* is it file? */
			for (int i = 0; i < 8; ++i)
			{
				long temp_one = QueenBoard::files_array[i] | historyOfMove;
				long temp_two = temp_one ^QueenBoard::files_array[i];
			    if( temp_two == 0)
			   		return QueenBoard::files_array[i];
			}
			
			/* is it rank? */
			for (int i = 0; i < 8; ++i)
			{
				long temp_one = QueenBoard::ranks[i] | historyOfMove;
				long temp_two = temp_one^ QueenBoard::ranks[i];
				if( temp_two  == 0)
					return QueenBoard::ranks[i];
			}

			/* is it left diagonal? */
			for (int i = 0; i < 15; ++i)
			{
				long temp_one = QueenBoard::left_diagonals[i] | historyOfMove;
				long temp_two = temp_one ^QueenBoard::left_diagonals[i];
			    if( temp_two == 0)
			   		return QueenBoard::left_diagonals[i];
			}

			/* is it right diagonal? */
			for (int i = 0; i < 15; ++i)
			{
				long temp_one = QueenBoard::right_diagonals[i] | historyOfMove;
				long temp_two = temp_one^ QueenBoard::right_diagonals[i];
				if( temp_two  == 0)
					return QueenBoard::right_diagonals[i];
			}

			return -1;
		};

		/**
		 * Idenitifies the direction
		 * @param  old_position [description]
		 * @param  new_position [description]
		 * @return              [description]
		 * 
		 */
		inline long identifyMoveDirection(long old_position, long new_position)
		{
			return new_position - old_position;
		};

		inline std::string getMoveDirection(long old_position, long new_position)
		{
			std::string up        = "up";
			std::string down      = "down";
			std::string left      = "left";
			std::string right     = "right";
			std::string invalid   = "invalid";
			std::string upleft    = "up_left";
			std::string downleft  = "down_left";
			std::string upright   = "up_right";
			std::string downright = "down_right";

			long direction    = this->identifyMoveDirection(old_position, new_position);
			long rank_or_file = this->identifyMoveField(old_position, new_position);

			if(rank_or_file == -1) return invalid;

			for (int i = 0; i < 8; ++i)
			{
				if( (rank_or_file ^ QueenBoard::ranks[i]) == 0)
				{
					if(direction > 0)
					{
						return left;
					}
					else
					{
						return right;
					}
				}
			}

			for (int i = 0; i < 8; ++i)
			{
				if( (rank_or_file ^ QueenBoard::files_array[i]) == 0)
				{
					if(direction > 0)
					{
						return up;
					}
					else
					{
						return down;
					}
				}
			}

			for (int i = 0; i < 15; ++i)
			{
				if( (rank_or_file ^ QueenBoard::left_diagonals[i]) == 0)
				{
					if(direction > 0)
					{
						return upleft;
					}
					else
					{
						return downleft;
					}
				}
			}

			for (int i = 0; i < 15; ++i)
			{
				if( (rank_or_file ^ QueenBoard::right_diagonals[i]) == 0)
				{
					if(direction > 0)
					{
						return upright;
					}
					else
					{
						return downright;
					}
				}
			}
		};

		/**
		 * Determines whether the new move is a capture of a regular slide.
		 * @param  oldPosition [description]
		 * @param  newPosition [description]
		 * @param  fullboard   [description]
		 * @return             [description]
		 * 
		 */
		int identifyMoveType(bool xSuitColor, long oldPosition, long newPosition)
		{

		};

		/**
		 * Overridding the unimplemented identifyMoveType
		 * @param  old_position  [description]
		 * @param  newPosition   [description]
		 * @param  fullboard     [description]
		 * @param  moveDirection [description]
		 * @return               [description]
		 * 
		 */
		inline int identifyMoveType(long old_position, long new_position, long fullboard, long moveDirection)
		{

		};

		inline int getRankOf(long position)
		{
			for (int i = 0; i < 8; ++i)
				if( ((QueenBoard::ranks[i] & position) ^ position) == 0 ) return i;

			return -1;
		};

		inline int getFileOf(long position)
		{
			for (int i = 0; i < 8; ++i)
				if( ((QueenBoard::files_array[i] & position) ^ position) == 0 ) return i;

			return -1;
		};

		inline int getLeftDiagonalOf(long position)
		{
			for (int i = 0; i < 15; ++i)
				if( ((QueenBoard::left_diagonals[i] & position) ^ position) == 0 ) return i;

			return -1;
		};

		inline int getRightDiagonalOf(long position)
		{
			for (int i = 0; i < 15; ++i)
				if( ((QueenBoard::right_diagonals[i] & position) ^ position) == 0 ) return i;

			return -1;
		};

		/**
		 * [getBoardBetweenPositions description]
		 * @param  old_position [description]
		 * @param  new_position [description]
		 * @param  direction    [description]
		 * @return              [description]
		 * 
		 */
		inline long getBoardBetweenPositions(long old_position, long new_position, long fullboard, long field, std::string direction)
		{
			long board_old_and_new         = old_position | new_position;
			long fullboard_on_moving_field = HelperFunctions::applyMask_Keep(fullboard, field);

			long mask = 0L;

			if( direction.compare("up") == 0 || direction.compare("down") == 0)
			{
				int rank_one = this->getRankOf(old_position), 
					rank_two = this->getRankOf(new_position);

					if( rank_one != -1 && rank_two != -1)
					{
						for (int i = std::max(rank_one, rank_two); i < 8; ++i)
							mask += QueenBoard::ranks[i];

						for (int i = std::min(rank_one, rank_two); i >= 0; --i)
							mask += QueenBoard::ranks[i];
					}
			}
			else if( direction.compare("left") == 0 || direction.compare("right") == 0)
			{
				long file_one = this->getFileOf(old_position), 
					 file_two = this->getFileOf(new_position);


					if(file_one != -1 && file_two != -1)
					{
						for (int i = std::max(file_one, file_two); i < 8; ++i)
							mask += QueenBoard::files_array[i];

						for (int i = std::min(file_one, file_two); i >= 0; --i)
							mask += QueenBoard::files_array[i];
					}
			}
			else if( direction.compare("up_left") == 0 || direction.compare("down_left") == 0)
			{
				int rank_one = this->getRightDiagonalOf(old_position), 
					rank_two = this->getRightDiagonalOf(new_position);

					if( rank_one != -1 && rank_two != -1)
					{
						for (int i = std::max(rank_one, rank_two); i < 15; ++i)
							mask += QueenBoard::right_diagonals[i];

						for (int i = std::min(rank_one, rank_two); i >= 0; --i)
							mask += QueenBoard::right_diagonals[i];
					}
			}
			else if( direction.compare("up_right") == 0 || direction.compare("down_right") == 0)
			{
				long file_one = this->getLeftDiagonalOf(old_position), 
					 file_two = this->getLeftDiagonalOf(new_position);


					if(file_one != -1 && file_two != -1)
					{
						for (int i = std::max(file_one, file_two); i < 15; ++i)
							mask += QueenBoard::left_diagonals[i];

						for (int i = std::min(file_one, file_two); i >= 0; --i)
							mask += QueenBoard::left_diagonals[i];
					}
			}

			mask = HelperFunctions::applyMask_Keep(mask, field);

			fullboard_on_moving_field = fullboard_on_moving_field ^ old_position;
			fullboard_on_moving_field = (fullboard_on_moving_field | mask) ^ mask;

			return fullboard_on_moving_field;			
		};

		/**
		 * [isBoardEmptyBetweenOldAndNew description]
		 * @return [description]
		 * 
		 */
		inline bool isBoardEmptyBetweenOldAndNew(long old_position, long new_position, long fullboard, long move_direction, std::string direction)
		{
			if( direction.compare("invalid") == 0 ) return false;

			long what_in_between = this->getBoardBetweenPositions(old_position, new_position, fullboard, move_direction, direction);

			if( what_in_between == 0) return true;
			else return false;
		};

		/**
		 * Judges the new move as valid or invalid.
		 * @param  long : the new board's configuration that represents the new move.
		 * @return bool : true upon valid.
		 *
		 */
		inline bool isMoveValid(long move, long fullboard, long myFriendsBoard)
		{
			long oldPosition = this->extractOldPosition(move);
			long newPosition = this->extractNewMove(move);

			if(0 == newPosition) return false; // If there was no new move

			bool isBoardEmptyBetweenOldAndNew = this->isBoardEmptyBetweenOldAndNew( oldPosition, 
															newPosition, 
															fullboard, 
															this->identifyMoveField(oldPosition, newPosition),
															this->getMoveDirection(oldPosition, newPosition)
															);
			
			bool isNewPositionEmpty = this->isBoardIsEmptyAt(newPosition, fullboard);

			if(isBoardEmptyBetweenOldAndNew)
			{
				if(isNewPositionEmpty) return true;
				else
				{
					/* Save capture */
					if(this->isCaptureLegal(myFriendsBoard, newPosition))
					{
						AbstractBoardEntity::saveCaptureHistory(this->name, this->suitColor, newPosition);
						return true;
					}
					else
						return false;
				}
			}
			else
				return false;
		};

	public:
		/**
		 * Constructor and destructor
		 * 
		 */
		QueenBoard(bool suitColor, std::string name)
		:AbstractBoardEntity(suitColor, name)
		{

		};
		~QueenBoard()
		{

		};

		/**
		 * Alters the positions at this board.
		 * 
		 */
		inline void alterBoard(bool isInitLoad,	long fullboard, long myFriendsBoard, std::string& binaryString)
		{
			AbstractBoardEntity::alterBoard(isInitLoad, fullboard, myFriendsBoard, binaryString);
		};
};

#endif // _QUEEN_BOARD_H_INCLUDED_