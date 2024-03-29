#include "CardNine.h"

CardNine::CardNine(const CellPosition& pos) : Card(pos) 
{
	//setting card number 
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
	pOut->ClearStatusBar();
	pOut->PrintMessage("Cell To Move: " + to_string(CellTomove.GetCellNum()) + " .Click To Continue");
	int x, y;
	pIn->GetPointClicked(x,y);
	pOut->ClearStatusBar();

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

	//Applying next game object if exist 
	Cell* pCell = pPlayer->GetCell();
	if (pCell->GetGameObject() != NULL)
		pCell->GetGameObject()->Apply(pGrid, pPlayer);
}

CardNine::~CardNine()
{

}