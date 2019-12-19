#include "CardFive.h"

CardFive::CardFive(const CellPosition& cpos):Card(cpos)
{
	cardNumber = 5;
	Cardpos = cpos;
}

void CardFive::Apply(Grid* pGrid, Player* pPlayer)
{
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	int x, y;
	pOut->PrintMessage("you have reached card five. click to contiue ");
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
	pPlayer->Move(pGrid,pPlayer->GetRolledDiceNUm());
}

Card* CardFive::GetCard(CellPosition& pos)
{
	Card* cptr = new CardFive(pos);
	return cptr;
}


CardFive::~CardFive()
{
}
