#include "Lightning.h"
#include "Grid.h"
#include "Player.h"
Lightning::Lightning(ApplicationManager* pApp):Action(pApp)
{
}

void Lightning::ReadActionParameters()
{
	//This Action Has no Parameters
	Grid* pGrid = pManager->GetGrid();
	CurrPlayer = pGrid->GetCurrentPlayer();
	CurrPlayerNum = pGrid->GetcurrPlayerNumber();
}

void Lightning::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	ReadActionParameters();
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		pGrid->AdvanceCurrentPlayer();
		if (i != CurrPlayerNum)
			CurrPlayer->SetWallet(CurrPlayer->GetWallet() - 20);
	}
}
