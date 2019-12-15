#include "Poison.h"
#include "Grid.h"
#include "Player.h"
Poison::Poison(ApplicationManager* pApp) :Action(pApp)
{
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		Used[i] = false;
	}
}

void Poison::ReadActionParameters()
{
	//This Action Has no Parameters
	Grid* pGrid = pManager->GetGrid();
	CurrPlayer = pGrid->GetCurrentPlayer();
	CurrPlayerNum = pGrid->GetcurrPlayerNumber();
}

void Poison::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	ReadActionParameters();
	if (Used[CurrPlayerNum] == false)
	{
		IsUsed(CurrPlayerNum);
		//Making The Player Choose a Player To Reduce his rolled dice value for 5 turns
		pGrid->GetOutput()->PrintMessage("Ice Attack:Choose A player to prevent him from Dicing next time");
		int PoisonedPlayer = pGrid->GetInput()->GetInteger(pGrid->GetOutput());
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			pGrid->AdvanceCurrentPlayer();
			ReadActionParameters();
			if (CurrPlayerNum== PoisonedPlayer)
			{
				CurrPlayer->setIspoisoned(true);
				CurrPlayer->NumberOfAttacksincrements();
			}
		}

	}
	else
	{
		pGrid->GetOutput()->PrintMessage("You Have Used This Attack Befroe,Click anywhere to continue..");
		int x, y;
		pGrid->GetInput()->GetPointClicked(x, y);
		pGrid->GetOutput()->ClearStatusBar();
	}
}

void Poison::IsUsed(int PlayerIndex)
{
	Used[PlayerIndex] = true;
}

Poison::~Poison()
{
}
