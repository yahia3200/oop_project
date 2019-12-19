#include "CardThree.h"
#include "Ladder.h"

CardThree::CardThree(const CellPosition& cpos):Card(cpos)
{
	cardNumber = 3;
	Cardpos = cpos;
}



void CardThree::Apply(Grid* pGrid, Player* pPlayer)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	int x, y;

	pOut->PrintMessage("Go To Next Ladder. click to continue");
	pIn->GetPointClicked(x, y);
	Ladder* Lptr = pGrid->GetNextLadder(position); //Getting the position of endCell of Next Ladder
	pGrid->UpdatePlayerCell(pPlayer, Lptr->GetEndPosition()); //Updating The Player's Cell
	pOut->ClearStatusBar();
}


CardThree::~CardThree()
{
}

Card* CardThree::GetCard(CellPosition& pos)
{
	Card* ptr = new CardThree(pos);
	return ptr;
}
