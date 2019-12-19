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
	if (pGrid->GetClipboard() != NULL)
	{
		Card* pCard = NULL; // will point to the card object type
		switch (cardnum)
		{
		case 1:
			pCard = new CardOne(position);
			*((CardOne*)pCard) = *((CardOne*)pGrid->GetClipboard());

			break;
		case 2:
			pCard = new CardTwo(position);
			*((CardTwo*)pCard) = *((CardTwo*)pGrid->GetClipboard());

			break;
		case 3:
			pCard = new CardThree(position);
			*((CardThree*)pCard) = *((CardThree*)pGrid->GetClipboard());

			break;
		case 4:
			pCard = new CardFour(position);
			*((CardFour*)pCard) = *((CardFour*)pGrid->GetClipboard());

			break;
		case 5:
			pCard = new CardFive(position);
			*((CardFive*)pCard) = *((CardFive*)pGrid->GetClipboard());

			break;
		case 6:
			pCard = new CardSix(position);
			*((CardSix*)pCard) = *((CardSix*)pGrid->GetClipboard());

			break;
		case 7:
			pCard = new CardSeven(position);
			*((CardSeven*)pCard) = *((CardSeven*)pGrid->GetClipboard());

			break;
		case 8:
			pCard = new CardEight(position);
			*((CardEight*)pCard) = *((CardEight*)pGrid->GetClipboard());

			break;
		case 9:
			pCard = new CardNine(position);
			*((CardNine*)pCard) = *((CardNine*)pGrid->GetClipboard());

			break;
		case 10:
			pCard = new CardTen(position);
			*((CardTen*)pCard) = *((CardTen*)pGrid->GetClipboard());

			break;
		case 11:
			pCard = new CardEleven(position);
			*((CardEleven*)pCard) = *((CardEleven*)pGrid->GetClipboard());

			break;
		case 12:
			pCard = new CardTwelve(position);
			*((CardTwelve*)pCard) = *((CardTwelve*)pGrid->GetClipboard());

			break;
		case 13:
			pCard = new CardThirteen(position);
			*((CardThirteen*)pCard) = *((CardThirteen*)pGrid->GetClipboard());

			break;
		case 14:
			pCard = new CardFourteen(position);
			*((CardFourteen*)pCard) = *((CardFourteen*)pGrid->GetClipboard());

			break;

		}
		//paste the card to the clicked cell after cheaking
		bool valid = pGrid->AddObjectToCell(pCard);
		if (valid)
		{

			//Draw the card in the clicked cell
			pCard->Draw(pOut);
			
			*((CardNine*)pCard) = *((CardNine*)pGrid->GetClipboard());
			pOut->DrawCell(position, cardnum);

		}
		else
		{
			pOut->PrintMessage("Invalid Cell. click to continue ");
			int x, y;
			pIn->GetPointClicked(x, y);
			pOut->ClearStatusBar();
			delete pCard;
		}
			
	}
}