#pragma once
#include "Card.h"
class CardEight : public Card

// [ CardEight ] Summary:
// Its Apply() Function: Prevents the player from rolling the next turn
// Its Parameters: This Card Has No Parameters

{
public :

	CardEight(const CellPosition& cpos);

	virtual void Apply(Grid* pGrid, Player* pPlayer); 

	virtual Card* GetCard(CellPosition& pos);

	virtual ~CardEight(); //Virtual Destructor 

};

