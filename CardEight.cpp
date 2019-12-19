#include "CardEight.h"
#include "Player.h"

CardEight::CardEight(const CellPosition& cpos):Card(cpos)
{
	cardNumber = 8;
}

void CardEight::Apply(Grid* pGrid, Player* pPlayer)
{
	//Calling Apply() of the base class Card to print the message that I reached this card number
	Card::Apply(pGrid, pPlayer);

	//prevent player from rolling next turn 
	pGrid->GetCurrentPlayer()->setpreventplayer(true);
}

Card* CardEight::GetCard(CellPosition& pos)
{
	Card* cptr = new CardEight(pos);
	return cptr;
}

CardEight::~CardEight()
{
}
