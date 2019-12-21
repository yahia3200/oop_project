#include "AddCardAction.h"

#include "Input.h"
#include "Output.h"
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
AddCardAction::AddCardAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddCardAction::~AddCardAction()
{
}

void AddCardAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	//Read the "cardNumber" parameter and set its data member
	pOut->PrintMessage("Enter Card Number : ");
	cardNumber = pIn->GetInteger(pOut);
	//Read the "cardPosition" parameter (its cell position) and set its data member
	pOut->PrintMessage("Click On Cell : ");
	cardPosition = pIn->GetCellClicked();
	//Validation 
	while (cardNumber < 1 || cardNumber > 14)
	{
		pOut->PrintMessage("Invalid Input. Please enter a number between 1 and 14 : ");
		cardNumber = pIn->GetInteger(pOut);
	}
	// Clear status bar
	pOut->ClearStatusBar();

}

void AddCardAction::Execute()
{
	//Reading The Card parameters
	ReadActionParameters();
	//Switch case on cardNumber data member and create the appropriate card object type
	if (cardPosition.GetCellNum() == 99 || cardPosition.GetCellNum() == 1)
	{
		Grid* pGrid = pManager->GetGrid();
		pGrid->PrintErrorMessage("Can't Place Cards Here .Click To Continue");
		Input* In = pGrid->GetInput();
		int x, y;
		In->GetPointClicked(x, y);
		pGrid->GetOutput()->ClearStatusBar();
	}
	else
	{
		Card* pCard = NULL; // will point to the card object type
		switch (cardNumber)
		{
		case 1:
			pCard = new CardOne(cardPosition);
			break;
		case 2:
			pCard = new CardTwo(cardPosition);
			break;
		case 3:
			pCard = new CardThree(cardPosition);
			break;
		case 4:
			pCard = new CardFour(cardPosition);
			break;
		case 5:
			pCard = new CardFive(cardPosition);
			break;
		case 6:
			pCard = new CardSix(cardPosition);
			break;
		case 7:
			pCard = new CardSeven(cardPosition);
			break;
		case 8:
			pCard = new CardEight(cardPosition);
			break;
		case 9:
			pCard = new CardNine(cardPosition);
			break;
		case 10:
			pCard = new CardTen(cardPosition);
			break;
		case 11:
			pCard = new CardEleven(cardPosition);
			break;
		case 12:
			pCard = new CardTwelve(cardPosition);
			break;
		case 13:
			pCard = new CardThirteen(cardPosition);
			break;
		case 14:
			pCard = new CardFourteen(cardPosition);
			break;

		}
		// 3- if pCard is correctly set in the switch case (i.e. if pCard is pointing to an object -- NOT NULL)
		if (pCard)
		{
			// We get a pointer to the Grid from the ApplicationManager
			Grid* pGrid = pManager->GetGrid();
			//Make the "pCard" reads its card parameters: ReadCardParameters(), It is virtual and depends on the card type
			pCard->ReadCardParameters(pGrid);
			//Add the card object to the GameObject of its Cell:
			//if the GameObject cannot be added in the Cell, Print the appropriate error message on statusbar

			bool IsValid = pGrid->AddObjectToCell(pCard);
			if (IsValid == false)
			{
				pGrid->PrintErrorMessage("This Cell Is Invalid");
				delete pCard;
			}

			// Here, the card is created and added to the GameObject of its Cell, so we finished executing the AddCardAction

		}

	}
	

}
