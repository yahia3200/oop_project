#include "Fire.h"
#include "Grid.h"
#include "Player.h"
Fire::Fire(ApplicationManager* pApp) :Action(pApp)
{
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		Used[i] = false;
	}
}

void Fire::ReadActionParameters()
{
	//This Action Has no Parameters
	Grid* pGrid = pManager->GetGrid();
	CurrPlayer = pGrid->GetCurrentPlayer();
	CurrPlayerNum = pGrid->GetcurrPlayerNumber();
}

void Fire::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	ReadActionParameters();
	if (Used[CurrPlayerNum] == false)
	{
		IsUsed(CurrPlayerNum);
		CurrPlayer->NumberOfAttacksincrements();
		//Making The Player Choose a Player To Reduce his rolled dice value for 5 turns
		pGrid->GetOutput()->PrintMessage("Fire Attack:Choose A player to Deduct 20 coins from his wallet for his next 3 turns");
		int burntPlayer = pGrid->GetInput()->GetInteger(pGrid->GetOutput());
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			pGrid->AdvanceCurrentPlayer();
			ReadActionParameters();
			if (CurrPlayerNum == burntPlayer)
			{
				CurrPlayer->setIsBurnt(true);
				CurrPlayer->increaseturnsofFire();
				pGrid->GetOutput()->PrintMessage("Player No. " + to_string(burntPlayer) + " Is Fireed by deducting 20 coins from his wallet. ,Press anywhere to continue");
				int x, y;
				pGrid->GetInput()->GetPointClicked(x, y);
				pGrid->GetOutput()->ClearStatusBar();
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

void Fire::IsUsed(int PlayerIndex)
{
	Used[PlayerIndex] = true;
}

Fire::~Fire()
{
}
