#pragma once
#include "Card.h"
class CardSix :
	public Card
{
	
public:
	CardSix(const CellPosition& cpos);
	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player
													  // Moves the player backward the same number of steps that he just rolled
	
	virtual ~CardSix(); //Virtual Destructor 
};



