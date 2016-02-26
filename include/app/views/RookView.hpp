#ifndef _ROOK_VIEW_H_INCLUDED_
#define _ROOK_VIEW_H_INCLUDED_

#include "views/RookView.hpp"

class RookView : public PieceView
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
			return RookView::whiteSuitPath;
		}

		/**
		 * Returns the black suit's path's class attribute's of the derivetives.
		 * 
		 * @return std::string
		 */
		inline std::string getBlackSuitPath()
		{
			return RookView::blackSuitPath;
		}

	public: 
		/**
		 * Constructor and destructor
		 * 
		 */
		RookView(std::string path, int x, int y, int height, int width)
		:PieceView(suitColor, x, y, height, width)
		{

		};
		
		~RookView();

};

#endif // _ROOK_VIEW_H_INCLUDED_