#include "CardSeven.h"

CardSeven::CardSeven(const CellPosition& cpos):Card(cpos)
{	
	cardNumber = 7;
}

void CardSeven::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);

	//do 4 loops to return to the player who reached the card
	for (int i = 0; i < 3; i++)
	{
		pGrid->AdvanceCurrentPlayer();
	}

	Output* Out = pGrid->GetOutput();
	Out->PrintMessage("You Have Another Dice Roll");
}

Card* CardSeven::GetCard(CellPosition& pos)
{
	Card* cptr = new CardSeven(pos);
	return cptr;
}


CardSeven::~CardSeven()
{
}
