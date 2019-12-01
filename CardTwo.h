#pragma once
#include "Card.h"
class CardTwo :
	public Card
{
	//Increments the value of the passing player’s wallet by a value specified when creating the grid.
	int walletAmount;
public :
	CardTwo(const CellPosition& cpos);
	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardOne which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player
													  // by inCrement the player's wallet by the walletAmount data member
	virtual void Save(ofstream& OutFile, int t);
	virtual ~CardTwo(); //Virtual Destructor 
};

