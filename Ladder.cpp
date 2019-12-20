#include "Ladder.h"
#include "Player.h"
#include "Snake.h"

int Ladder::LadderCounter = 0;
Ladder::Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;
	this->startCellPos = startCellPos;
	LadderCounter++;
}

void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}

void Ladder::Apply(Grid* pGrid, Player* pPlayer) 
{
	

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==
	
	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click
	Output* pOut = pGrid->GetOutput(); //Creating Pointer To Output Class Using Grid Class
	Input* pIn = pGrid->GetInput();    //Creating Pointer To Input Class Using Grid Class
	int x, y;  //Int Variables to be used in GetPointClicked
	pOut->PrintMessage("You have reached a ladder. Click to continue ..."); 
	pIn->GetPointClicked(x, y); //Wating For User Click
	pOut->ClearStatusBar();

	// 2- Apply the ladder's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that
	pGrid->UpdatePlayerCell(pPlayer, endCellPos); //Applying Ladder Effect 

	
	
}

CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}


void Ladder::Save(ofstream& OutFile, int t)
{
	if (t == 0)
	{
		OutFile << startCellPos.GetCellNum() << " " << endCellPos.GetCellNum() << '\n';
	}
}


void Ladder::SaveLaddersNumber(ofstream& OutFile)
{
	OutFile << LadderCounter << '\n';
}

bool Ladder::IsOverlaping(GameObject* newObj)
{
	if (startCellPos.HCell() == newObj->GetPosition().HCell())
	{
		Snake* newSnake = dynamic_cast<Snake*>(newObj);
		Ladder* newLadder = dynamic_cast<Ladder*>(newObj);
		if (newLadder)
		{

			if (newLadder->startCellPos.GetCellNum() >= startCellPos.GetCellNum() && newLadder->startCellPos.GetCellNum() <= endCellPos.GetCellNum())
				return true;
			else if (newLadder->startCellPos.GetCellNum() <= startCellPos.GetCellNum() && newLadder->endCellPos.GetCellNum() >= endCellPos.GetCellNum())
				return true;
		}

		if (newSnake)
		{
			if (newSnake->GetPosition().GetCellNum() == endCellPos.GetCellNum())
				return true;
		}
	}

	return false;
		
}

void Ladder::DecrementLadderCounter()
{
	LadderCounter--;
}

Ladder::~Ladder()
{
	LadderCounter--;
}
