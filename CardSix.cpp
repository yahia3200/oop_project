#include "CardSix.h"

CardSix::CardSix(const CellPosition& cpos):Card(cpos)
{
	cardNumber = 6;
}

void CardSix::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);

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
