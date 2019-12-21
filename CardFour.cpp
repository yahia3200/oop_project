#include "CardFour.h"
#include "Snake.h"
CardFour::CardFour(const CellPosition& cpos):Card(cpos)
{
	cardNumber = 4;
}

void CardFour::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);

	Snake* Snakeptr = pGrid->GetNextSnake(position); //Getting the position of endCell of Next Snake

	pGrid->UpdatePlayerCell(pPlayer, Snakeptr->GetPosition()); //Updating The Player's Cell

	Snakeptr->Apply(pGrid, pPlayer);
}

Card* CardFour::GetCard(CellPosition& pos)
{
	Card* cptr = new CardFour(pos);
	return cptr;
}

CardFour::~CardFour()
{
}
