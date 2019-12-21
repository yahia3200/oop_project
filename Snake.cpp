#include "Snake.h"

int Snake::SnakeCount = 0;
Snake::Snake(const CellPosition& startCellPos, const CellPosition& endCellPos):GameObject(startCellPos)
{
	this->endCellPos = endCellPos;
	this->startCellPos = startCellPos;
	SnakeCount++;

//Validation 
}

void Snake::Draw(Output* pOut) const
{
	pOut->DrawSnake(endCellPos, position);
}

void Snake::Apply(Grid* pGrid, Player* pPlayer)
{
	//Creating Pointer To Output Class Using Grid Class

	Output* pOut = pGrid->GetOutput(); 

	//Creating Pointer To Input Class Using Grid Class

	Input* pIn = pGrid->GetInput();
	//Int Variables to be used in GetPointClicked
	int x, y; 
	pOut->PrintMessage("You have reached a snake. Click to continue ...");
	//Wating For User Click
	pIn->GetPointClicked(x, y); 
	pOut->ClearStatusBar();

	//applaying snake effect 
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);
	pGrid->UpdateInterface();
}

CellPosition Snake::GetEndPosition() const
{
	return endCellPos;
}



void Snake::Save(ofstream& OutFile, int t)
{
	if (t == 1)
	{
		OutFile << startCellPos.GetCellNum() << " " << endCellPos.GetCellNum() << '\n';
	}	
}

void Snake::SaveSnakesNumber(ofstream& OutPut)
{
	OutPut << SnakeCount << '\n';
}

void Snake::DecrementSnakeCounter()
{
	SnakeCount--;
}

Snake::~Snake()
{
	SnakeCount--;
}
