#pragma once
#include "Card.h"
class CardFive :
	public Card
{
	

public:
	CardFive(const CellPosition& cpos);
	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardFive on the passed Player
													  // Move forward the same number of steps that he just rolled
	virtual Card* GetCard(CellPosition& pos);

	virtual ~CardFive(); //Virtual Destructor 
};





