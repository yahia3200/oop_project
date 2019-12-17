#include "CardSix.h"

CardSix::CardSix(const CellPosition& cpos):Card(cpos)
{
	cardNumber = 6;
	Cardpos = cpos;
}

void CardSix::ReadCardParameters(Grid* pGrid)
{
}

void CardSix::Apply(Grid* pGrid, Player* pPlayer)
{
	pPlayer->Move(pGrid, - pPlayer->GetRolledDiceNUm());
}

CardSix::~CardSix()
{
}
