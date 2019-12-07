#pragma once
#include "Card.h"
class CardThree :
	public Card
{
	//Card Description : Moves the player forward to the start of the next ladder. (If no ladders ahead, do nothing)

public:
	CardThree(const CellPosition& cpos);  //Constructor
	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardThree on the passed Player
													  // by inCrement the player's wallet by the walletAmount data member
	virtual ~CardThree(); //Virtual Destructor 
};

