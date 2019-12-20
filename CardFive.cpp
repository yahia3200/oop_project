#include "CardFive.h"
#include <iostream>
using namespace std;

CardFive::CardFive(const CellPosition& cpos):Card(cpos)
{
	cardNumber = 5;
}

void CardFive::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);

	pPlayer->SetturnCount(pPlayer->GetTurnCount() - 1);

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
