#include "CardSeven.h"

CardSeven::CardSeven(const CellPosition& cpos):Card(cpos)
{	
	cardNumber = 7;
}

void CardSeven::Apply(Grid* pGrid, Player* pPlayer)
{

	//Calling Apply() of the base class Card to print the message that I reached this card number
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
