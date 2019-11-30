#include "CardThree.h"
#include "Ladder.h"

CardThree::CardThree(const CellPosition& cpos):Card(cpos)
{
	cardNumber = 3;
	Cardpos = cpos;
}



void CardThree::Apply(Grid* pGrid, Player* pPlayer)
{
	Ladder* Lptr = pGrid->GetNextLadder(position); //Getting the position of endCell of Next Ladder
	pGrid->UpdatePlayerCell(pPlayer, Lptr->GetEndPosition()); //Updating The Player's Cell
	delete Lptr;
}

void CardThree::Save(ofstream& OutFile, int t)
{
	if (t == 2)
	{
		OutFile << cardNumber << " " << Cardpos.GetCellNum() << '\n';
	}
}

CardThree::~CardThree()
{
}
