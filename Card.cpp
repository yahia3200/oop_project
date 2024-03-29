#include "Card.h"
#include <fstream>

int Card::CardCounter = 0;
Card::Card(const CellPosition & pos) : GameObject(pos)
{
	CardCounter++; // Increment Cards Number When Creating A Card
}

void Card::SetCardNumber(int cnum)
{
	if (cnum <= 1 && cnum >= 14)
		cardNumber = cnum;
	else
		cardNumber = -1;
}

int Card::GetCardNumber()
{
	return cardNumber;
}


void Card::Draw(Output* pOut) const
{
	///DONE: call the appropriate Ouput function that draws a cell containing the "cardNumber" in "position"
	pOut->DrawCell(position, cardNumber);
}

void Card::ReadCardParameters(Grid * pGrid)
{
	// we should not make it pure virtual because some Cards doesn't have parameters
	// and if we make it pure virtual, that will make those Cards abstract classes
}

void Card::Apply(Grid* pGrid, Player* pPlayer) 
{
	// As written below the "Roll Dice" action in the document ==> Check the Project Document
	// "If a player reaches a card of any other type", the following message should be printed then wait mouse click

	pGrid->PrintErrorMessage("You have reached card " + to_string(cardNumber) + ". Click to continue ...");
}


void Card::Save(ofstream& OutFile, int t)
{
	if (t == 2)
	{
		OutFile << cardNumber << " " << position.GetCellNum() << '\n';
	}
}

void Card::SaveCardsNumber(ofstream& OutPut)
{
	OutPut << CardCounter << '\n';
}

void Card::Load(istream& InputFile)
{
}

void Card::DecrementCardCounter()
{
	CardCounter--;
}

Card::~Card()
{
	CardCounter--; // Decrement Cards Number When A Card Is Deleted 
}
