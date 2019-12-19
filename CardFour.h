#pragma once
#include "Card.h"
class CardFour : public Card

// [ CardFour ] Summary:
// Its Apply() Function: Moves the player forward to the start of the next Snake. (If no Snakes ahead, do nothing)
// Its Parameters: This Card Has No Parameters

{

public:
	CardFour(const CellPosition& cpos);

	virtual void Apply(Grid* pGrid, Player* pPlayer); 

	virtual Card* GetCard(CellPosition& pos);

	virtual ~CardFour();
};

