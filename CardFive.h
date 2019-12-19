#pragma once
#include "Card.h"
class CardFive : public Card

// [ CardFive ] Summary:
// Its Apply() Function: Move forward the same number of steps that he just rolled
// Its Parameters: This Card Has No Parameters

{

public:
	CardFive(const CellPosition& cpos);

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	virtual Card* GetCard(CellPosition& pos);

	virtual ~CardFive();
};





