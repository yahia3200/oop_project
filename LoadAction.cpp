#include "LoadAction.h"
#include "CellPosition.h"
#include "Grid.h"
#include "Ladder.h"
#include "Snake.h"
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
#include <fstream>


LoadAction::LoadAction(ApplicationManager* pApp):Action(pApp)
{
}

void LoadAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read File Name From The User
	pOut->PrintMessage("Enter The File Name: ");
	fileName = pIn->GetSrting(pOut);
	
	pOut->ClearStatusBar();
}

void LoadAction::Execute()
{
	ReadActionParameters();

	Grid* pGrid = pManager->GetGrid();

	// Delete All Objects From The Grid And Reset Cards From 10 To 14
	pGrid->ResetGrid();
	CardTen::IsExisted = false;
	CardEleven::IsExisted = false;
	CardTwelve::IsExisted = false;
	CardThirteen::IsExisted = false;
	CardFourteen::IsExisted = false;

	ifstream InputFile;
	InputFile.open(fileName);
	if (InputFile.is_open()) //This Line for checking if the file is Opened or not 
	{
		// Read Ladders Number
		int LaddersNum;
		int start, end;
		InputFile >> LaddersNum;

		// Create All Ladders
		for (int i = 0; i < LaddersNum; i++)
		{
			InputFile >> start >> end;

			CellPosition startPos(start);
			CellPosition endPos(end);

			Ladder* pLadder = new Ladder(startPos, endPos);
			pGrid->AddObjectToCell(pLadder);
		}

		// Read Snakes Number
		int SnakesNum;
		InputFile >> SnakesNum;

		// Create All Snakes
		for (int i = 0; i < SnakesNum; i++)
		{
			InputFile >> start >> end;

			CellPosition startPos(start);
			CellPosition endPos(end);

			Snake* pSnake = new Snake(startPos, endPos);
			pGrid->AddObjectToCell(pSnake);

		}

		// Read Cards Number
		int CardsNum;
		InputFile >> CardsNum;

		// Read Card Type And Postion Then Create All Cards
		int cardType, cardpos;
		for (int i = 0; i < CardsNum; i++)
		{

			InputFile >> cardType;
			Card* pCard = NULL;

			InputFile >> cardpos;
			CellPosition cardPosition(cardpos);

			switch (cardType)
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

			// Set Parameters For Cards And Add It To The Cell
			pCard->Load(InputFile);
			pGrid->AddObjectToCell(pCard);
		}
	}

	else // If The File Didn't Found
	{
		pGrid->GetOutput()->PrintMessage("Couldn't Open The File . Click To Contiue");
		int x, y;
		pGrid->GetInput()->GetPointClicked(x, y);
		pGrid->GetOutput()->ClearStatusBar();
	}
		
}


