#pragma once
#include "Card.h"
class CardNine:public Card
{

	CellPosition CellTomove;
public :
	CardNine(const CellPosition& pos);
	~CardNine(void);
	void ReadCardParameters(Grid* pGrid);
	

	virtual Card* GetCard(CellPosition& pos);

	virtual void Load(istream& InputFile);
	virtual void Save(ofstream& OutFile, int t);
	void Apply(Grid* pGrid, Player* pPlayer);
};



