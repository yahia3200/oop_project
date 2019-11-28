#include "SaveAction.h"
#include "Grid.h"
#include "Input.h"
#include "Output.h"
#include <fstream>

SaveAction::SaveAction(ApplicationManager* pApp) :Action(pApp)
{

}
void SaveAction::ReadActionParameters()
{
	
}

void SaveAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Enter The File Name: ");
	fileName = pIn->GetSrting(pOut);

	ofstream OutFile;
	OutFile.open(fileName,ios::out);

	pGrid->SaveAll(OutFile,0);
	pGrid->SaveAll(OutFile,1);

	OutFile.close();
}
SaveAction::~SaveAction()
{

}