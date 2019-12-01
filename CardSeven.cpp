#include "CardSeven.h"

CardSeven::CardSeven(const CellPosition& cpos):Card(cpos)
{	
	// setting the inherited cardNumber data member with 7
	cardNumber = 7;
}

void CardSeven::ReadCardParameters(Grid* pGrid)
{
}

void CardSeven::Apply(Grid* pGrid, Player* pPlayer)
{
	//get a variable that refers to the player's number 
	for (int i = 0; i < 3; i++)
	{
		pGrid->AdvanceCurrentPlayer();
	}
}

void CardSeven::Save(ofstream& OutFile, int t)
{

}

CardSeven::~CardSeven()
{
}
