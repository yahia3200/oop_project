#include "PasteCardAction.h"
#include "Input.h"
#include "Output.h"
#include"Card.h"
#include "CardOne.h"
#include "CardTwo.h"
#include "CardThree.h"
#include "CardFour.h"
#include "CardFive.h"
#include "CardSix.h"
#include "CardSeven.h"
#include "CardEight.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"
#include "CardThirteen.h"
#include "CardFourteen.h"
#include <iostream>
using namespace std;
PasteCardAction::PasteCardAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer

}

PasteCardAction::~PasteCardAction()
{
	
}

void PasteCardAction::ReadActionParameters()
{	

	//getting pointer to output && input Interfaces from the Grid

	Grid *pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	//getting position of the clicked cell to paste in it 

	pOut->PrintMessage("Click On The Cell To Paste The Card On It..");

	position = pIn->GetCellClicked();

	//check if clicked copied or cutted cell is has a card (is not equal null)

	if (pGrid->GetClipboard() != NULL)
	{
		//getting card clicked number 

		cardnum = pGrid->GetClipboard()->GetCardNumber();
	}
	else
	{
		pOut->ClearStatusBar();

		pGrid->PrintErrorMessage("There is No Card To Paste ...");
	}
	//clear statusbar
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

	
	//creat pointer to card with the clicked position
	//using GetCard function that return pointer to the card
	//with same parameter of copied or cutted card 
	//with the new position 
	if (pGrid->GetClipboard() != NULL)
	{
		Card* cptr = pGrid->GetClipboard()->GetCard(position);

		//paste the card to the clicked cell after cheaking
		// it is valid to paste card in the clicked position 

		bool valid = pGrid->AddObjectToCell(cptr);
		if (valid)
		{
			//Draw the card in the clicked position

			cptr->Draw(pOut);
		}
		else
		{
			pOut->PrintMessage("Invalid Cell. click to continue ");
			int x, y;
			pIn->GetPointClicked(x, y);
			pOut->ClearStatusBar();
			delete cptr;
		}
	}
	}
