#pragma once
#include "Card.h"
class CardFour :
	public Card
{
	//Data Members (TODO)

public:
	CardFour(const CellPosition& cpos);
	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player
													  // by inCrement the player's wallet by the walletAmount data member
	virtual ~CardFour(); //Virtual Destructor 
};

