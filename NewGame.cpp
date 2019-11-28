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
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	
	
	//// Allocate thePlayer Objects of the PlayerList
	//Cell* startplayerscell[NumVerticalCells - 1][0];
	//for (int i = 0; i < MaxPlayerCount; i++)
	//{
	//	pGrid->GetCurrentPlayer = new Player(startplayerscell, i); // first cell
	//	pGrid->GetCurrentPlayer->Draw(pOut); // initially draw players in the first cell
	//	pGrid->AdvanceCurrentPlayer();
	//}

	//// Initialize currPlayerNumber with 0 (first player)
	//// start with the first player
	//while (pGrid->GetCurrentPlayer() != 0)
	//{
	//	pGrid->AdvanceCurrentPlayer();
	//}
	//setting endgame false to start a new game
	pGrid->SetEndGame(false);
}

NewGame::~NewGame()
{
}
