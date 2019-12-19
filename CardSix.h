#pragma once
#include "Card.h"
class CardSix : public Card

// [ CardSix ] Summary:
// Its Apply() Function: Moves the player backward the same number of steps that he just rolled
// Its Parameters: This Card Has No Parameters

{

public:
	CardSix(const CellPosition& cpos);

	virtual void Apply(Grid* pGrid, Player* pPlayer); 

	virtual Card* GetCard(CellPosition& pos);

	virtual ~CardSix();
};



