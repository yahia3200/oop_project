#include "DeleteGameObject.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"
DeleteGameObject::DeleteGameObject(ApplicationManager* pApp) :Action(pApp)
{
}

void DeleteGameObject::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("Click on any cell to remove object from it ");
	cellPos = pIn->GetCellClicked();
	pOut->ClearStatusBar();
}

void DeleteGameObject::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	
	pGrid->deleteObject(cellPos);
	pGrid->RemoveObjectFromCell(cellPos);
	//pGrid->GetOutput()->ClearGridArea(); //Wrong
	//pGrid->GetOutput()->DrawCell(cellPos);
	pGrid->UpdateInterface();
}

DeleteGameObject::~DeleteGameObject()
{
}
