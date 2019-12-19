#include "CardSix.h"

CardSix::CardSix(const CellPosition& cpos):Card(cpos)
{
	cardNumber = 6;
	Cardpos = cpos;
}

void CardSix::Apply(Grid* pGrid, Player* pPlayer)
{
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	int x, y;
	pOut->PrintMessage("you have reached card six. click to contiue ");
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
	pPlayer->Move(pGrid, - pPlayer->GetRolledDiceNUm());
}

Card* CardSix::GetCard(CellPosition& pos)
{
	Card* cptr = new CardSix(pos);
	return cptr;
}

CardSix::~CardSix()
{
}
