#pragma once
#include "Card.h"
class CardSix :
	public Card
{
	//Data Members (TODO)

public:
	CardSix(const CellPosition& cpos);
	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardOne which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player
													  // by inCrement the player's wallet by the walletAmount data member
	virtual ~CardSix(); //Virtual Destructor 
};



