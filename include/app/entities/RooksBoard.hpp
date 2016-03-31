#ifndef _ROOKS_BOARD_H_INCLUDED_
#define _ROOKS_BOARD_H_INCLUDED_

#include "entities/AbstractBoardEntity.hpp"

class RooksBoard : public AbstractBoardEntity
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
		RooksBoard(bool suitColor)
		:AbstractBoardEntity(suitColor)
		{

		};
		~RooksBoard()
		{

		};

		/**
		 * Alters the positions at this board.
		 * 
		 */
		inline void alterBoard(bool isInitLoad, long fullboard, std::string& binaryString)
		{
			AbstractBoardEntity::alterBoard(isInitLoad, fullboard, binaryString);
		};

};

#endif // _ROOKS_BOARD_H_INCLUDED_