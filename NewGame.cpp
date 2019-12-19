#include "NewGame.h"
#include "Lightning.h"
#include "Ice.h"
#include "Poison.h"
#include "Fire.h"

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
	Lightning* Light = pGrid->GetLight();
	Ice* ice = pGrid->GetIce();
	Poison* poison = pGrid->GetPoison();
	Fire* fire = pGrid->GetFire();
	// restart thePlayer Objects
	CellPosition* startplayerscell;
	startplayerscell = new CellPosition(NumVerticalCells - 1, 0);
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		pGrid->GetCurrentPlayer()->SetWallet(100);
		pGrid->GetCurrentPlayer()->SetturnCount(0);
		pGrid->GetCurrentPlayer()->setIspoisoned(false);
		pGrid->GetCurrentPlayer()->setIsBurnt(false);
		pGrid->GetCurrentPlayer()->setpreventplayer(false);
		pGrid->GetCurrentPlayer()->resetNumberOfAttacks();
		pGrid->GetCurrentPlayer()->resetFirecounter();
		pGrid->GetCurrentPlayer()->resetPoisoncounter();
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

	// setting endgame false to start a new game
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

NewGame::~NewGame()
{
}




