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
		int AttackedPlayer;
		//Preventing Player from playing next time:
		do
		{
			pGrid->GetOutput()->PrintMessage("Ice Attack:Choose A player to prevent him from Dicing next time");
			AttackedPlayer = pGrid->GetInput()->GetInteger(pGrid->GetOutput());
			if (AttackedPlayer == CurrPlayerNum) {
				pGrid->GetOutput()->PrintMessage("You cannot Attack yourslef !,press anywhere to continue..");
				int x, y;
				pGrid->GetInput()->GetPointClicked(x, y);
				pGrid->GetOutput()->ClearStatusBar();
			}
		} while (AttackedPlayer>3||AttackedPlayer<0||AttackedPlayer==CurrPlayerNum);
		for (int i = 0; i <= 3; i++)
		{
			pGrid->AdvanceCurrentPlayer();
			if (pGrid->GetcurrPlayerNumber() == AttackedPlayer)
			{
				pGrid->GetOutput()->PrintMessage("Player No. " + to_string(AttackedPlayer) + " Is prevented from playing next time,Press anywhere to continue");
				int x, y;
				pGrid->GetInput()->GetPointClicked(x, y);
				pGrid->GetOutput()->ClearStatusBar();
				int turnnum = pGrid->GetCurrentPlayer()->GetTurnCount();
				pGrid->GetCurrentPlayer()->setpreventplayer(true);
			}
		}
		pGrid->GetCurrentPlayer()->NumberOfAttacksincrements();
	}
	else {
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
