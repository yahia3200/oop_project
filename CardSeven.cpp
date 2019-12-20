#include "CardSeven.h"

CardSeven::CardSeven(const CellPosition& cpos):Card(cpos)
{	
	//setting card num 
	cardNumber = 7;
}

void CardSeven::Apply(Grid* pGrid, Player* pPlayer)
{

	//Calling Apply() of the base class Card to print the message that I reached this card number
	Card::Apply(pGrid, pPlayer);

	//Advance player to reach the current player once again 
	for (int i = 0; i < 3; i++)
	{
		pGrid->AdvanceCurrentPlayer();
	}
	//print message to the user 
	Output* Out = pGrid->GetOutput();
	Out->PrintMessage("You Have Another Dice Roll...Click to Continue");
	int x, y;
	pGrid->GetInput()->GetPointClicked(x,y);
	Out->ClearStatusBar();
}

Card* CardSeven::GetCard(CellPosition& pos)
{
	Card* cptr = new CardSeven(pos);
	return cptr;
}


CardSeven::~CardSeven()
{
}
