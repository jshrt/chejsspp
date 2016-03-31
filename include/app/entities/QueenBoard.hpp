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
		 * Determines whether the new move is a capture of a regular slide.
		 * @param  oldPosition [description]
		 * @param  newPosition [description]
		 * @param  fullboard   [description]
		 * @return             [description]
		 * 
		 */
		inline int identifyMoveType(bool xSuitColor, long oldPosition, long newPosition)
		{

		};

		/**
		 * Judges the new move as valid or invalid.
		 * @param  long : the new board's configuration that represents the new move.
		 * @return bool : true upon valid.
		 *  
		 */
		inline bool isMoveValid(long move, long fullboard)
		{
			return true;
		};

	public:
		/**
		 * Constructor and destructor
		 * 
		 */
		QueenBoard(bool suitColor)
		:AbstractBoardEntity(suitColor)
		{

		};
		~QueenBoard()
		{

		};

		/**
		 * Alters the positions at this board.
		 * 
		 */
		inline void alterBoard(bool isInitLoad,	long fullboard, std::string& binaryString)
		{
			AbstractBoardEntity::alterBoard(isInitLoad, fullboard, binaryString);
		};
};

#endif // _QUEEN_BOARD_H_INCLUDED_