#include "CardEight.h"
#include "Player.h"

CardEight::CardEight(const CellPosition& cpos):Card(cpos)
{
	//setting card num with 8
	cardNumber = 8;
	Cardpos = cpos;
}

void CardEight::Apply(Grid* pGrid, Player* pPlayer)
{
	//Calling Apply() of the base class Card to print the message that I reached this card number

	Card::Apply(pGrid, pPlayer);
	//prevent player from rolling 
	
	int turnnum = pPlayer->GetTurnCount();
	pGrid->GetCurrentPlayer()->setpreventplayer(true);
	
}

CardEight::~CardEight()
{
}
