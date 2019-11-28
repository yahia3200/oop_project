#include "CopyCardAction.h"
#include "Input.h"
#include "Output.h"

CopyCardAction::CopyCardAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer

}

CopyCardAction::~CopyCardAction()
{
	//delete CpiedCardcell;
	//delete CpiedCardcell;
	//position = NULL;
	//CpiedCardcell = NULL;
	//CpiedCardinfo = NULL;
}

void CopyCardAction::ReadActionParameters()
{
	//getting pointer to output && input class
	pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	//getting position of the cell clicked 

	pOut->PrintMessage("Click On The Card To Copy it..");
	position =pIn->GetCellClicked();
	//CpiedCardcell = new Cell(position);
	
	pOut->ClearStatusBar();

	//check if there is a card and if there return its address 

	CpiedCardinfo = CpiedCardcell->HasCard();


}

void CopyCardAction::Execute()
{
	ReadActionParameters();
	//copy the card clicked After check there is card in clicked 
	if (CpiedCardinfo != NULL)
		pGrid->SetClipboard(CpiedCardinfo);
	else pGrid->GetOutput()->PrintMessage("Bitch");

}
