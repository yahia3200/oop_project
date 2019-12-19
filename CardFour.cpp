#include "CardFour.h"
#include "Snake.h"
CardFour::CardFour(const CellPosition& cpos):Card(cpos)
{
	cardNumber = 4;
	Cardpos = cpos;
}

void CardFour::Apply(Grid* pGrid, Player* pPlayer)
{
	Snake* Snakeptr = pGrid->GetNextSnake(position); //Getting the position of endCell of Next Snake
	pGrid->UpdatePlayerCell(pPlayer, Snakeptr->GetEndPosition()); //Updating The Player's Cell

}

CardFour::~CardFour()
{
}
