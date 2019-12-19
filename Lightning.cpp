#include "Lightning.h"
#include "Grid.h"
#include "Player.h"
Lightning::Lightning(ApplicationManager* pApp):Action(pApp)
{
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		Used[i] = false;
	}
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
	if (Used[CurrPlayerNum] == false) {
		IsUsed(CurrPlayerNum);
		for (int i = 0; i < MaxPlayerCount-1; i++)
		{
			pGrid->AdvanceCurrentPlayer();
			ReadActionParameters();
				CurrPlayer->SetWallet(CurrPlayer->GetWallet() - 20);
		}
		CurrPlayer->NumberOfAttacksincrements();
		pGrid->AdvanceCurrentPlayer();
	}
	else {
		pGrid->GetOutput()->PrintMessage("You Have Used This Attack Befroe,Click anywhere to continue..");
		int x, y;
		pGrid->GetInput()->GetPointClicked(x, y);
		pGrid->GetOutput()->ClearStatusBar();
	}
}

void Lightning::IsUsed(int PlayerIndex)
{
	Used[PlayerIndex] = true;
}

void Lightning::restart()
{
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		Used[i] = false;
	}
}

Lightning::~Lightning()
{
}
