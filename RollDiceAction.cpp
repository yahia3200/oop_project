#include "RollDiceAction.h"

#include "Grid.h"
#include "Player.h"

#include <time.h> // used to in srand to generate random numbers with different seed

RollDiceAction::RollDiceAction(ApplicationManager* pApp) : Action(pApp)
{
}

void RollDiceAction::ReadActionParameters()
{
	// no parameters to read from user
}

void RollDiceAction::Execute()
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Check if the Game is ended (Use the GetEndGame() function of pGrid), if yes, make the appropriate action
	if (pGrid->GetEndGame())
	{
		int x, y;

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
		/*	cout << pGrid->getcurrPlayerNumber() << endl;
			cout << pGrid->GetEndGame() << endl;
			cout << pGrid->GetCurrentPlayer()->GetWallet()<<endl;
			cout << pGrid->GetCurrentPlayer()->GetTurnCount()<<endl;
			cout << pGrid->GetCurrentPlayer()->GetCell()<<endl;*/
		pGrid->SetEndGame(false);
		//cout << pGrid->GetEndGame() << endl;	}
		// -- If not ended, do the following --:
	}
	else
	{
		// 2- Generate a random number from 1 to 6 --> This step is done for you
		srand((int)time(NULL)); // time is for different seed each run
		int diceNumber = 1 + rand() % 6; // from 1 to 6 --> should change seed
		pOut->PrintMessage("Dice Number Is " + to_string(diceNumber));

		// 3- Get the "current" player from pGrid
		Player* pPlayer = pGrid->GetCurrentPlayer();
		//Player* pPlayer = pGrid->GetPlayer1();
		// 4- Move the currentPlayer using function Move of class player
		pPlayer->Move(pGrid, diceNumber);
		// 5- Advance the current player number of pGrid
		pGrid->AdvanceCurrentPlayer();

	}
	// NOTE: the above guidelines are the main ones but not a complete set (You may need to add more steps).

}

RollDiceAction::~RollDiceAction()
{
}
