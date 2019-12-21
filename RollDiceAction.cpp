#include "RollDiceAction.h"

#include "Grid.h"
#include "Player.h"
#include "Lightning.h"
#include "Ice.h"
#include "Poison.h"
#include "Fire.h"
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
	//Get a Pointer to the Input / Output Interfaces from the Grid
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();


	// == Here are some guideline steps (numbered below) to implement this function ==

	// Check if the Game is ended (Use the GetEndGame() function of pGrid), if yes, make the appropriate action
	if (pGrid->GetEndGame())
	{
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
		CellPosition* startplayerscell;
		startplayerscell = new CellPosition(NumVerticalCells - 1, 0);
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			pGrid->GetCurrentPlayer()->SetWallet(100);
			pGrid->GetCurrentPlayer()->SetturnCount(0);
			pGrid->GetCurrentPlayer()->setIspoisoned(false);
			pGrid->GetCurrentPlayer()->setIsBurnt(false);
			pGrid->GetCurrentPlayer()->setIsiced(false);
			pGrid->GetCurrentPlayer()->setpreventplayer(false);
			pGrid->GetCurrentPlayer()->resetNumberOfAttacks();
			pGrid->GetCurrentPlayer()->resetFirecounter();
			pGrid->GetCurrentPlayer()->resetPoisoncounter();
			pGrid->GetCurrentPlayer()->reseticecounter();
			pGrid->UpdatePlayerCell(pGrid->GetCurrentPlayer(), *startplayerscell);
			pGrid->GetLight()->restart();
			pGrid->GetIce()->restart();
			pGrid->GetPoison()->restart();
			pGrid->GetFire()->restart();
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

		// setting cards from 10 to 14 Property true to restart them in the execute of each one 
		pGrid->setcard10owner(true);
		pGrid->setcard11owner(true);
		pGrid->setcard12owner(true);
		pGrid->setcard13owner(true);
		pGrid->setcard14owner(true);

		// Clear the status bar
		pOut->ClearStatusBar();
	}
	// -- If not ended, do the following --:
	else
	{
		if (pGrid->GetCurrentPlayer()->getpreventplayer())
		{
			if (pGrid->GetCurrentPlayer()->GetWallet() >= 0)
			{
				//prevent player from rolling dice by gettng 0 for dicenumber 
				pGrid->GetCurrentPlayer()->Move(pGrid, 0);

				//let the current player availabel to play in the next turn
				pGrid->GetCurrentPlayer()->setpreventplayer(false);
			}
			else
			{
				// Generate a random number from 1 to 6 --> This step is done for you
				srand((int)time(NULL)); // time is for different seed each run
				int diceNumber = 1 + rand() % 6; // from 1 to 6 --> should change seed
				pOut->PrintMessage("Dice Number Is " + to_string(diceNumber));

				// Get the "current" player from pGrid
				Player* pPlayer = pGrid->GetCurrentPlayer();

				// Move the currentPlayer using function Move of class player
				pPlayer->Move(pGrid, diceNumber);
				
				if (pGrid->GetCurrentPlayer()->GetWallet() >= 0)
					pGrid->GetCurrentPlayer()->setpreventplayer(false);
			}
			// Advance the current player number of pGrid
			pGrid->AdvanceCurrentPlayer();
		}	
		else
		{
			// Generate a random number from 1 to 6 --> This step is done for you
			srand((int)time(NULL)); // time is for different seed each run
			int diceNumber = 1 + rand() % 6; // from 1 to 6 --> should change seed
			pOut->PrintMessage("Dice Number Is " + to_string(diceNumber));

			// Get the "current" player from pGrid
			Player* pPlayer = pGrid->GetCurrentPlayer();

			// Move the currentPlayer using function Move of class player
			pPlayer->Move(pGrid, diceNumber);

			// Advance the current player number of pGrid
			pGrid->AdvanceCurrentPlayer();
		}
	}
	
	// NOTE: the above guidelines are the main ones but not a complete set (You may need to add more steps).

}

RollDiceAction::~RollDiceAction()
{
}
