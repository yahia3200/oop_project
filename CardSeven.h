#pragma once
#include "Card.h"

// [ CardSeven ] Summary:
// Its Apply() Function: Gives the player another dice roll
// Its Parameters: This Card Has No Parameters

class CardSeven : public Card
{

public:
	CardSeven(const CellPosition& cpos);

	virtual void Apply(Grid* pGrid, Player* pPlayer); 

	virtual Card* GetCard(CellPosition& pos);

	virtual ~CardSeven();  
};

