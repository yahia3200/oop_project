#include "CardEight.h"
#include "Player.h"

CardEight::CardEight(const CellPosition& cpos):Card(cpos)
{
	//setting card number 
	cardNumber = 8;
}

void CardEight::Apply(Grid* pGrid, Player* pPlayer)
{
	//Getting pointer to the input && output Interfaces from the Grid
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	//Calling Apply() of the base class Card to print the message that I reached this card number
	Card::Apply(pGrid, pPlayer);

	//prevent player from rolling next turn 
	pGrid->GetCurrentPlayer()->setpreventplayer(true);

	//print message to the user 
	pOut->PrintMessage("you are denied from playing this turn. Click to continue ");
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
}

Card* CardEight::GetCard(CellPosition& pos)
{
	Card* cptr = new CardEight(pos);
	return cptr;
}

CardEight::~CardEight()
{
}
