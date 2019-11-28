
#include "ToDesignModeAction.h"
#include "Grid.h"
#include "Output.h"

ToDesignModeAction::ToDesignModeAction(ApplicationManager* pApp) : Action(pApp)
{

}

void ToDesignModeAction::ReadActionParameters()
{
	// No Parameters For this Action
}

void ToDesignModeAction::Execute()
{

	// Draw toolbar for design mode
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	pOut->CreateDesignModeToolBar();
}


ToDesignModeAction::~ToDesignModeAction()
{

}