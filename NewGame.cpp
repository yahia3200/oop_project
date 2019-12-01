#include "NewGame.h"

NewGame::NewGame(ApplicationManager* pApp) : Action(pApp)
{
}

void NewGame::ReadActionParameters()
{
	// no parameters to read from user
}

void NewGame::Execute()
{
	// Get a Pointer to the Input / Output Interfaces from the Grid
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	
	
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

	// setting endgame false to start a new game
	pGrid->SetEndGame(false);
}

NewGame::~NewGame()
{
}
