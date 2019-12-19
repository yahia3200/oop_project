#include "CopyCardAction.h"
#include "Input.h"
#include "Output.h"

CopyCardAction::CopyCardAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer

}

CopyCardAction::~CopyCardAction()
{
	
}

void CopyCardAction::ReadActionParameters()
{
	//getting pointer to output && input class
	pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	//getting position of the cell clicked 

	pOut->PrintMessage("Click On The Card To Copy it..");
	position = pIn->GetCellClicked();

	//getting card in the clicked cell
	CpiedCardinfo = pGrid->Getcard(position);
	pOut->ClearStatusBar();

	

}

void CopyCardAction::Execute()
{
	ReadActionParameters();

	//copy the card clicked After check there is card in clicked 
	if (CpiedCardinfo != NULL)
		pGrid->SetClipboard(CpiedCardinfo);
	

}
