#pragma once

#include "Card.h"

// [ CardTen ] Summary:
// Its Apply() Function: Gives the player the option to buy this cell and all cells containing a card with the same number.
// Its Parameters: Card price & Fees to pay by passing players --> put them as "data members" and read them in ReadCardParameters()

class CardEleven : public Card
{
	// CardEleven Parameters:
	static int price; // Price of card the player want to buy
	static int Fees; // Fees to pay by passing players
	static Player* ownerplayer; //the owner of the card(s)
	static bool IsExisted;  // a bool refers if this card is created 
	static bool IsSaved; // bool to save the card parameters only once
	static int CardElevenCounter;   // Number Of Cards In The Grid 
	friend class LoadAction;

public:
	CardEleven(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardOne which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardTen on the passed Player
													  // by either buying the cell if it's valid or force a fee
	virtual Card* GetCard(CellPosition& pos);

	static void setIsExisted(bool Existed);

	virtual void Save(ofstream& OutFile, int t);

	static void SetIsSaved(bool s);

	virtual void Load(istream& InputFile);

	static void DecrementCardElevenCounter();   // If a Card Dosen't exisit But Not Destructed (Used In Cut)

	virtual ~CardEleven(); // A Virtual Destructor
};

