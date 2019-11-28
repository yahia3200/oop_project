#include "InputDiceValue.h"

InputDiceValue::InputDiceValue(ApplicationManager* pApp) :Action(pApp)
{
}

void InputDiceValue::ReadActionParameters()
{
	Grid* pGrid;
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	int x, y;

	pOut->PrintMessage("Enter dice value: ");
	diceNumber = pIn->GetInteger(pOut);
	while (!(diceNumber >= 0 && diceNumber <= 6))
	{
		pOut->PrintMessage("Invalid Input. Please enter a positive integer between 0 & 6: ");
		diceNumber = pIn->GetInteger(pOut);
	}
}

void InputDiceValue::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	if (pGrid->GetEndGame() == false)
	{
		Player* pPlayer = pGrid->GetCurrentPlayer();
		// 4- Move the currentPlayer using function Move of class player
		pPlayer->Move(pGrid, diceNumber);
		// 5- Advance the current player number of pGrid
		pGrid->AdvanceCurrentPlayer();
	}
	else {
		int x, y;
	
		pOut->PrintMessage("Winner winner! Chicken Dinner! click to continue");
		pIn->GetPointClicked(x, y);
		Cell* startplayerscell[NumVerticalCells][NumHorizontalCells];
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			pGrid->GetCurrentPlayer()->SetCell(startplayerscell[NumVerticalCells - 1][0]);
			pGrid->GetCurrentPlayer()->SetWallet(100);
			pGrid->GetCurrentPlayer()->SetturnCount(0);
			pGrid->AdvanceCurrentPlayer();
		}
		while (pGrid->GetcurrPlayerNumber() != 0)
		{
			pGrid->AdvanceCurrentPlayer();
		}

		pGrid->SetEndGame(false);


	}
}

InputDiceValue::~InputDiceValue()
{
}


