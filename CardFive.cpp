#include "CardFive.h"

CardFive::CardFive(const CellPosition& cpos):Card(cpos)
{
	cardNumber = 5;
	Cardpos = cpos;
}

void CardFive::ReadCardParameters(Grid* pGrid)
{
}

void CardFive::Apply(Grid* pGrid, Player* pPlayer)
{
	pPlayer->Move(pGrid,pPlayer->GetRolledDiceNUm());
}

void CardFive::Save(ofstream& OutFile, int t)
{
	if (t == 2)
	{
		OutFile << cardNumber << " " << Cardpos.GetCellNum() << '\n';
	}
}

CardFive::~CardFive()
{
}
