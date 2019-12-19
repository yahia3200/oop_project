#pragma once
#include "Card.h"

// [ CardNine ] Summary:
// Its Apply() Function: Instructs the player to go to a specific cell. This specific cell is specified during grid design
// Its Parameters: This Card Has No Parameters

class CardNine: public Card
{
	// CardNine Parameters:
	CellPosition CellTomove;

public :

	CardNine(const CellPosition& pos);

	void ReadCardParameters(Grid* pGrid);
	
	virtual Card* GetCard(CellPosition& pos);

	virtual void Load(istream& InputFile);

	virtual void Save(ofstream& OutFile, int t);

	void Apply(Grid* pGrid, Player* pPlayer);

	~CardNine(void);
};



