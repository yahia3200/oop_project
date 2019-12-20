#include "CutCardAction.h"
#include "Input.h"
#include "Output.h"


CutCardAction::CutCardAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer

}

CutCardAction::~CutCardAction()
{

}

void CutCardAction::ReadActionParameters()
{
	//getting pointer to output && input class

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	//getting position of the cell clicked and get the cell

	pOut->PrintMessage("Click On The Source Cell..to Cut the Card");
	position = pIn->GetCellClicked();

	//getting card in the clicked cell
	CutCard = pGrid->Getclickedcard(position);
	pOut->ClearStatusBar();

	

}

void CutCardAction::Execute()
{
	//getting pointer to output && input class

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// call read parameter

	ReadActionParameters();

	//cut the card clicked After check there is card in clicked 

	if (CutCard != NULL)
	{
		pGrid->SetClipboard(CutCard);
		pGrid->RemoveObjectFromCell(position);
		pOut->DrawCell(position);
		Card::DecrementCardCounter();
	}
	else
	{
		int x, y;
		pGrid->PrintErrorMessage("There is No Card In The Clicked Cell...Click to Continue") ;
		pIn->GetPointClicked(x, y);
		pOut->ClearStatusBar();

	}
}