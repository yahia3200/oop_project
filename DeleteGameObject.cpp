#include "DeleteGameObject.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"
DeleteGameObject::DeleteGameObject(ApplicationManager* pApp) :Action(pApp)
{
}

void DeleteGameObject::ReadActionParameters()
{
	//Getting pointer to the Input/Output and grid Classes
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	//Getting the Cell that will be removed
	pOut->PrintMessage("Click on any cell to remove object from it ");
	cellPos = pIn->GetCellClicked();
	pOut->ClearStatusBar(); //Clearing the Message
}

void DeleteGameObject::Execute()
{
	ReadActionParameters(); //Reading The position of the Action
	Grid* pGrid = pManager->GetGrid();
	
	pGrid->deleteObject(cellPos); //Deallocation
	pGrid->RemoveObjectFromCell(cellPos); //Making the pointer of the grid points to null after deallocation
	pGrid->UpdateInterface();  //Updating the Screen (Grid)
}

DeleteGameObject::~DeleteGameObject()
{
}
