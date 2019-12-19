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
	//getting pointer to output && input class
	Grid *pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	//getting position of the clicked cell
	//settig the Game object with the card cpied||cutted

	pOut->PrintMessage("Click On The Cell To Paste The Card On It..");
	position = pIn->GetCellClicked();

	if (pGrid->GetClipboard() != NULL)
	{
		cardnum = pGrid->GetClipboard()->GetCardNumber();
	}
	
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

	
	//creat the card with the clicked position
	Card* cptr = pGrid->GetClipboard()->GetCard(position);
		//paste the card to the clicked cell after cheaking
		bool valid = pGrid->AddObjectToCell(cptr);
		if (valid)
		{

			//Draw the card in the clicked cell
			//pCard->Draw(pOut);
			pOut->DrawCell(position, cardnum);

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
