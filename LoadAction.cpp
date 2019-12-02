#include "LoadAction.h"
#include "CellPosition.h"
#include "Grid.h"
#include "Ladder.h"
#include "Snake.h"
#include <fstream>


LoadAction::LoadAction(ApplicationManager* pApp):Action(pApp)
{
}

void LoadAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Enter The File Name: ");
	fileName = pIn->GetSrting(pOut);

	pOut->ClearStatusBar();
}

void LoadAction::Execute()
{
	ReadActionParameters();

	Grid* pGrid = pManager->GetGrid();

	ifstream InputFile;
	InputFile.open(fileName);

	int LaddersNum;
	int start, end;
	InputFile >> LaddersNum;

	for (int i = 0; i < LaddersNum; i++)
	{
		InputFile >> start >> end;

		CellPosition startPos(start);
		CellPosition endPos(end);

		Ladder* pLadder = new Ladder(startPos, endPos);
		pGrid->AddObjectToCell(pLadder);
	}

	int SnakesNum;
	InputFile >> SnakesNum;

	for (int i = 0; i < SnakesNum; i++)
	{
		InputFile >> start >> end;

		CellPosition startPos(start);
		CellPosition endPos(end);

		Snake* pSnake = new Snake(startPos,endPos);
		pGrid->AddObjectToCell(pSnake);

	}
}


