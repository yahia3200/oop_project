#pragma once
#include "Card.h"
class CardEight :
	public Card
{
public :
	CardEight(const CellPosition& cpos);
	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player
													  // by inCrement the player's wallet by the walletAmount data member
	virtual Card* GetCard(CellPosition& pos);

	virtual ~CardEight(); //Virtual Destructor 

};

