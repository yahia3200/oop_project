#include "CardEight.h"
#include "Player.h"
CardEight::CardEight(const CellPosition& cpos):Card(cpos)
{
	//setting card num with 8
	cardNumber = 8;
}

void CardEight::ReadCardParameters(Grid* pGrid)
{
	//no parameter to read
}

void CardEight::Apply(Grid* pGrid, Player* pPlayer)
{
	//Calling Apply() of the base class Card to print the message that I reached this card number

	Card::Apply(pGrid, pPlayer);
	//prevent player from rolling 

	//pPlayer = pGrid->GetCurrentPlayer();
	//int turnnum = pPlayer->GetTurnCount();
	//while (pPlayer->GetTurnCount()==turnnum+1)

	//{
	//pPlayer->SetturnCount(turnnum + 1);
	//pPlayer->setpreventplayer(true);
	//pPlayer->SetturnCount(turnnum + 1);
//}
//pPlayer->setpreventplayer(false);
}

	
	
	
}
void CardEight::Save(ofstream& OutFile, int t)
{

}
CardEight::~CardEight()
{
}
