#pragma once
#include "Card.h"
class CardNine:public Card
{
	 CellPosition CellTomove;
public :
	CardNine(const CellPosition& pos);
	~CardNine(void);
	void ReadCardParameters(Grid* pGrid);
	void Apply(Grid* pGrid, Player* pPlayer);
};

