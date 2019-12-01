#pragma once
#include "Card.h"
class CardEight :
	public Card
{
public :
	CardEight(const CellPosition& cpos);
	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardOne which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player
													  // by inCrement the player's wallet by the walletAmount data member
	virtual void Save(ofstream& OutFile,int t);
	virtual ~CardEight(); //Virtual Destructor 

};

