#include "ToPlayMode.h"
#include "Grid.h"
ToPlayMode::ToPlayMode(ApplicationManager* pApp):Action(pApp)
{
}
void ToPlayMode::ReadActionParameters()
{
}
void ToPlayMode::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	pOut->CreatePlayModeToolBar();
	
	
}

ToPlayMode::~ToPlayMode()
{
}
