#ifndef _KING_VIEW_H_INCLUDED_
#define _KING_VIEW_H_INCLUDED_

#include "views/PieceView.hpp"

class KingView : public PieceView
{
	/*
	 |****************************
	 |		Attributes
	 |
	 |****************************
	 */
	private:
		/**
		 * The white suit's path.
		 * 
		 */
		static const std::string whiteSuitPath;

		/**
		 * The black suit's path.
		 * 
		 */
		static const std::string blackSuitPath;

	/*
	 |****************************
	 |		Methodes
	 |
	 |****************************
	 */
	protected:
		/**
		 * Returns the white suit's path's class attribute's of the derivetives.
		 * 
		 * @return std::string
		 */
		inline std::string getWhiteSuitPath()
		{
			return KingView::whiteSuitPath;
		}

		/**
		 * Returns the black suit's path's class attribute's of the derivetives.
		 * 
		 * @return std::string
		 */
		inline std::string getBlackSuitPath()
		{
			return KingView::blackSuitPath;
		}

	public: 
		/**
		 * Constructor and destructor
		 * 
		 */
		KingView(bool suitColor, std::string name, int x, int y, int height, int width)
		:PieceView(suitColor, name, x, y, height, width)
		{
			if(suitColor)
			{
				this->filePath = this->getWhiteSuitPath();
			}
			else
			{
				this->filePath = this->getBlackSuitPath();
			}

		    if(!this->load())
		    {
		    	try{
			    	_ExceptionHandler::throw_exception("_KingViewInitException", "Could not load image :" + this->filePath);
				}
				catch(const std::exception& exception)
				{
					throw exception;
				}
		    }
		};

		~KingView();

};

#endif // _KING_VIEW_H_INCLUDED_