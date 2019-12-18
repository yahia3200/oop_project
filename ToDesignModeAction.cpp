#include "ToDesignModeAction.h"
#include "NewGame.h"
#include "Grid.h"
#include "Output.h"

ToDesignModeAction::ToDesignModeAction(ApplicationManager* pApp) : Action(pApp)
{
	this->pApp = pApp;
}

void ToDesignModeAction::ReadActionParameters()
{
	// No Parameters For this Action
}

void ToDesignModeAction::Execute()
{
	// Reset the game 
	NewGame reset = NewGame(pApp);
	reset.Execute();

	// Draw toolbar for design mode
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	pOut->CreateDesignModeToolBar();
}


ToDesignModeAction::~ToDesignModeAction()
{

}