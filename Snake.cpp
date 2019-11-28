#include "Snake.h"
int Snake::SnakeCount = 0;
Snake::Snake(const CellPosition& startCellPos, const CellPosition& endCellPos):GameObject(startCellPos)
{
	this->endCellPos = endCellPos;
	SnakeCount++;

//Validation 
}

void Snake::Draw(Output* pOut) const
{
	pOut->DrawSnake(endCellPos, position);
}

void Snake::Apply(Grid* pGrid, Player* pPlayer)
{
	Output* pOut = pGrid->GetOutput(); //Creating Pointer To Output Class Using Grid Class
	Input* pIn = pGrid->GetInput();    //Creating Pointer To Input Class Using Grid Class
	int x, y;  //Int Variables to be used in GetPointClicked
	pOut->PrintMessage("You have reached a ladder. Click to continue ...");
	pIn->GetPointClicked(x, y); //Wating For User Click
	pOut->ClearStatusBar();
	pGrid->UpdatePlayerCell(pPlayer, endCellPos); //Applying Ladder Effect 
	pGrid->UpdateInterface();
}

CellPosition Snake::GetEndPosition() const
{
	return endCellPos;
}

int Snake::Count()
{
	return SnakeCount;
}

int Snake::GetCounter() const
{
	return Count();
}


void Snake::Save(ofstream& OutFile, int t)
{

}

Snake::~Snake()
{
}
