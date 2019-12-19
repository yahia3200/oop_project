#pragma once
#include "Card.h"

// [ CardThree ] Summary:
// Its Apply() Function: Moves the player forward to the start of the next ladder. (If no ladders ahead, do nothing)
// Its Parameters: This Card Has No Parameters

class CardThree : public Card
{

public:
	CardThree(const CellPosition& cpos);

	virtual void Apply(Grid* pGrid, Player* pPlayer); 

	virtual Card* GetCard(CellPosition& pos);

	virtual ~CardThree();

};

