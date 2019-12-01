#include "InputDiceValue.h"
#include "Player.h"
#include "Grid.h"
#include <time.h> // used to in srand to generate random numbers with different seed

InputDiceValue::InputDiceValue(ApplicationManager* pApp) :Action(pApp)
{
}

void InputDiceValue::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces from the Grid
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	int x, y;

	// get dice value from user
	pOut->PrintMessage("Enter dice value: ");
	diceNumber = pIn->GetInteger(pOut);
	while (!(diceNumber >= 0 && diceNumber <= 6))
	{
		pOut->PrintMessage("Invalid Input. Please enter a positive integer between 0 to 6: ");
		diceNumber = pIn->GetInteger(pOut);
	}

	// Clear the status bar
	pOut->ClearStatusBar();

}

void InputDiceValue::Execute()
{
	// Get a Pointer to the Input / Output Interfaces from the Grid
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	// Check if the Game is ended (Use the GetEndGame() function of pGrid), if yes, make the appropriate action
	if (!pGrid->GetEndGame())
	{
		// Get the "current" player from pGrid
		Player* pPlayer = pGrid->GetCurrentPlayer();

		// Move the currentPlayer using function Move of class player
		pPlayer->Move(pGrid, diceNumber);

		// Advance the current player number of pGrid
		pGrid->AdvanceCurrentPlayer();
	}
	else {
		int x, y;

		//print a random messege to the user
		srand((int)time(NULL));
		int randomvalue = 1 + rand() % 3;
		switch (randomvalue)
		{
		case 1:
			pOut->PrintMessage("Winner winner! Chicken Dinner! click to continue");
			pIn->GetPointClicked(x, y);
			break;

		case 2:
			pOut->PrintMessage("Congratulations! you get no reward for winning");
			pIn->GetPointClicked(x, y);
			break;

		case 3:
			pOut->PrintMessage("Please stop playing and go study you will fail");
			pIn->GetPointClicked(x, y);
			break;


		default:
			pOut->PrintMessage("P" + to_string(pGrid->GetcurrPlayerNumber()) + "is winner");
			pIn->GetPointClicked(x, y);
			break;
		}

		// restart thePlayer Objects
		CellPosition startplayerscell(NumVerticalCells - 1, 0);
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			pGrid->GetCurrentPlayer()->SetWallet(100);
			pGrid->GetCurrentPlayer()->SetturnCount(0);
			pGrid->UpdatePlayerCell(pGrid->GetCurrentPlayer(), startplayerscell);
			pGrid->AdvanceCurrentPlayer();
		} 

		// Initialize currPlayerNumber with 0 (first player)
		// start with the first player
		while (pGrid->GetcurrPlayerNumber() != 0)
		{
			pGrid->AdvanceCurrentPlayer();
		}

		//setting endgame false to start a new game
		pGrid->SetEndGame(false);
		// -- If not ended, do the following --:


	}
}

InputDiceValue::~InputDiceValue()
{
}


