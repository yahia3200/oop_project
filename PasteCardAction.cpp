#include "PasteCardAction.h"
#include "Input.h"
#include "Output.h"
#include"Card.h"
PasteCardAction::PasteCardAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer

}

PasteCardAction::~PasteCardAction()
{
	
}

void PasteCardAction::ReadActionParameters()
{
	//getting pointer to output && input class
	Grid *pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	//getting position of the clicked cell
	//settig the Game object with the card cpied||cutted
	pOut->PrintMessage("Click On The Cell To Paste The Card On It..");
	position = pIn->GetCellClicked();
	cardnum = pGrid->GetClipboard()->GetCardNumber();
    pOut->ClearStatusBar();

}

void PasteCardAction::Execute()
{
	
	//getting pointer to Grid
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	//calling read action parameters

	ReadActionParameters();

	//Paste the card to clicked After check  
	//Draw the card in the clicked cell
	if (pGrid->GetClipboard() != NULL)
	{
		//pGrid->GetClipboard()->SetCardposition(position, pGrid->GetClipboard());
		bool valid = pGrid->AddObjectToCell(pGrid->GetClipboard());
		if (valid)
		{
			pOut->DrawCell(position, cardnum);
			pGrid->UpdateInterface();

		}
	}
}
