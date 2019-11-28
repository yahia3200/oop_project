#include "CardThree.h"
#include "Ladder.h"
CardThree::CardThree(const CellPosition& cpos):Card(cpos)
{
}



void CardThree::Apply(Grid* pGrid, Player* pPlayer)
{
	Ladder* Lptr = pGrid->GetNextLadder(position); //Getting the position of endCell of Next Ladder
	pGrid->UpdatePlayerCell(pPlayer, Lptr->GetEndPosition()); //Updating The Player's Cell
	delete Lptr;
}

CardThree::~CardThree()
{
}
