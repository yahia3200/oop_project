#include "Poison.h"
#include "Grid.h"
#include "Player.h"
Poison::Poison(ApplicationManager* pApp) :Action(pApp)
{
	for (int i = 0; i < MaxPlayerCount; i++) //Making all player initially didn't use this attack
	{
		Used[i] = false;
	}
}

void Poison::ReadActionParameters()
{
	//This Action Has no Parameters
	//Getting pointers to Grid, Player 
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
		IsUsed(CurrPlayerNum); //Making the attacker player use this attack to prevent him from using it again
		//Making The Player Choose a Player To Reduce his rolled dice value for 5 turns
		int PoisonedPlayer;
		do
		{
			pGrid->GetOutput()->PrintMessage("Poison Attack:Choose A player to deduct 1 number from his dice roll");
			PoisonedPlayer = pGrid->GetInput()->GetInteger(pGrid->GetOutput());
			if (PoisonedPlayer == CurrPlayerNum) {
				pGrid->GetOutput()->PrintMessage("You cannot Attack yourslef !,press anywhere to continue..");
				int x, y;
				pGrid->GetInput()->GetPointClicked(x, y);
				pGrid->GetOutput()->ClearStatusBar();
			}
		} while (PoisonedPlayer>3||PoisonedPlayer<0||PoisonedPlayer==CurrPlayerNum);
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			pGrid->AdvanceCurrentPlayer();
			ReadActionParameters();
			if (CurrPlayerNum== PoisonedPlayer)
			{
				CurrPlayer->setIspoisoned(true);
				CurrPlayer->increaseturnsofpoison();
				pGrid->GetOutput()->PrintMessage("Player No. " + to_string(PoisonedPlayer) + " Is poisoned by deducting 1 number from his dice roll. ,Press anywhere to continue");
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

void Poison::IsUsed(int PlayerIndex)
{
	Used[PlayerIndex] = true;
}

void Poison::restart()
{
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		Used[i] = false;
	}
}

Poison::~Poison()
{
}
