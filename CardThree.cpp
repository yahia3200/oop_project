#include "CardThree.h"
#include "Ladder.h"

CardThree::CardThree(const CellPosition& cpos):Card(cpos)
{
	cardNumber = 3;
}



void CardThree::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	
	Ladder* Lptr = pGrid->GetNextLadder(position); //Getting the position of endCell of Next Ladder

	pGrid->UpdatePlayerCell(pPlayer, Lptr->GetPosition()); //Updating The Player's Cell

	Lptr->Apply(pGrid,pPlayer);
}


Card* CardThree::GetCard(CellPosition& pos)
{
	Card* ptr = new CardThree(pos);
	return ptr;
}

CardThree::~CardThree()
{
}