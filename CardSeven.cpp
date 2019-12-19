#include "CardSeven.h"

CardSeven::CardSeven(const CellPosition& cpos):Card(cpos)
{	
	// setting the inherited cardNumber data member with 7
	cardNumber = 7;
	Cardpos = cpos;
}

void CardSeven::Apply(Grid* pGrid, Player* pPlayer)
{
	//do 4 loops to return to the player who reached the card
	for (int i = 0; i < 3; i++)
	{
		pGrid->AdvanceCurrentPlayer();
	}
}


CardSeven::~CardSeven()
{
}
