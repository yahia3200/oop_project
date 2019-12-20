#include "Ice.h"
#include "Grid.h"
#include "Player.h"

Ice::Ice(ApplicationManager* pApp) :Action(pApp)
{
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		Used[i] = false;
	}
}

void Ice::ReadActionParameters()
{
	//This Action Has no Parameters
	Grid* pGrid = pManager->GetGrid();
	CurrPlayer = pGrid->GetCurrentPlayer();
	CurrPlayerNum = pGrid->GetcurrPlayerNumber();
}

void Ice::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	ReadActionParameters();
	if (Used[CurrPlayerNum] == false) 
	{
		IsUsed(CurrPlayerNum);
		//Making The Player Choose a Player To Reduce his Wallet
		int icedPlayer;
		//Preventing Player from playing next time:
		do
		{
			pGrid->GetOutput()->PrintMessage("Ice Attack:Choose A player to prevent him from Dicing next time");
			icedPlayer = pGrid->GetInput()->GetInteger(pGrid->GetOutput());
			if (icedPlayer == CurrPlayerNum) {
				pGrid->GetOutput()->PrintMessage("You cannot Attack yourslef !,press anywhere to continue..");
				int x, y;
				pGrid->GetInput()->GetPointClicked(x, y);
				pGrid->GetOutput()->ClearStatusBar();
			}
		} while (icedPlayer > 3 || icedPlayer < 0 || icedPlayer == CurrPlayerNum);
		for (int i = 0; i <= 3; i++)
		{
			pGrid->AdvanceCurrentPlayer();
			ReadActionParameters();
			if (CurrPlayerNum == icedPlayer)
			{
				CurrPlayer->setIsiced(true);
				CurrPlayer->increaseturnsoice();
				pGrid->GetOutput()->PrintMessage("Player No. " + to_string(icedPlayer) + " Is iced for " + to_string(pGrid->GetCurrentPlayer()->Geticecounter()) + " turns by preventing him from rolling dice next turn. ,Press anywhere to continue");
				int x, y;
				pGrid->GetInput()->GetPointClicked(x, y);
				pGrid->GetOutput()->ClearStatusBar();
			}
		}
		CurrPlayer->NumberOfAttacksincrements();
	}
	else 
	{
		pGrid->GetOutput()->PrintMessage("You Have Used This Attack Befroe,Click anywhere to continue..");
		int x, y;
		pGrid->GetInput()->GetPointClicked(x, y);
		pGrid->GetOutput()->ClearStatusBar();
	}
}

void Ice::IsUsed(int PlayerIndex)
{
	Used[PlayerIndex] = true;
}

void Ice::restart()
{
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		Used[i] = false;
	}
}

Ice::~Ice()
{
}
