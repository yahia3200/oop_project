#pragma once
#include "Card.h"

// [ CardOne ] Summary:
// Its Apply() Function: Increments the value of the passing player’s wallet by a value
// Its Parameters: The Wallet Value to Increase --> put it as a "data member" and read it in ReadCardParameters()

class CardTwo : public Card
{
	// CardTwo Parameters:
	int walletAmount;

public :
	CardTwo(const CellPosition& cpos);

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardTwo which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardTwo on the passed Player
													  // by inCrement the player's wallet by the walletAmount data member
	virtual Card* GetCard(CellPosition& pos);

	virtual void Save(ofstream& OutFile, int t);

	virtual void Load(istream& InputFile);

	virtual ~CardTwo(); 
};

