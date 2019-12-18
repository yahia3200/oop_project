#pragma once
#include "Card.h"
class CardThree :
	public Card
{
	//Card Description : Moves the player forward to the start of the next ladder. (If no ladders ahead, do nothing)

public:
	CardThree(const CellPosition& cpos);  //Constructor
	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardThree on the passed Player
	virtual ~CardThree(); //Virtual Destructor 
};

