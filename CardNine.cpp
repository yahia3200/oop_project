#include "CardNine.h"

CardNine::CardNine(const CellPosition& pos) : Card(pos) 
{
	cardNumber = 9; 
}


void CardNine::ReadCardParameters(Grid* pGrid)
{

	//Getting pointer to the input && output Interfaces from the Grid
	Input* pIn =pGrid->GetInput();
	Output* pOut=pGrid->GetOutput();

	//Ptinting message to gide the user 
	// get cell clicked and stored it in a paramewte CellTomove (object from  CellPosition )
	pOut->PrintMessage("New CardNine: Click to the cell to move to it  ");
	CellTomove = pIn->GetCellClicked();

}


Card* CardNine::GetCard(CellPosition& pos)
{
	Card* cptr = new CardNine(pos);
	((CardNine*)cptr)->CellTomove = CellTomove;
	return cptr;
}

void CardNine::Load(istream& InputFile)
{
	int pos;
	InputFile >> pos;
	CellTomove = CellPosition(pos);
}

void CardNine::Save(ofstream& OutFile, int t)
{
	if (t == 2)
	{
		OutFile << cardNumber << " " << position.GetCellNum() << " " << CellTomove.GetCellNum() << "\n";
	}

}

void CardNine::Apply(Grid* pGrid, Player* pPlayer)
{
	//Calling Apply() of the base class Card to print the message that I reached this card number
	Card::Apply(pGrid ,pPlayer);

	//Update player cell with the new clicked position 
	pGrid->UpdatePlayerCell(pPlayer, CellTomove);
}

CardNine::~CardNine()
{

}