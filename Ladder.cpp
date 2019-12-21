#include "Ladder.h"
#include "Player.h"

int Ladder::LadderCounter = 0;
Ladder::Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;
	this->startCellPos = startCellPos;
	LadderCounter++;
	///TODO: Do the needed validation
}

void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}

void Ladder::Apply(Grid* pGrid, Player* pPlayer) 
{
	
	//Creating Pointer To Output Class Using Grid Class
	//Creating Pointer To Input Class Using Grid Class

	Output* pOut = pGrid->GetOutput(); 
	Input* pIn = pGrid->GetInput();  

	//Int Variables to be used in GetPointClicked
	int x, y; 
	pOut->PrintMessage("You have reached a ladder. Click to continue ..."); 

	//Wating For User Click
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();

	//Applying Ladder Effect 
	pGrid->UpdatePlayerCell(pPlayer, endCellPos); 
	
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

void Ladder::DecrementLadderCounter()
{
	LadderCounter--;
}

Ladder::~Ladder()
{
	LadderCounter--;
}
