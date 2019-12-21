#include "AddLadderAction.h"

#include "Input.h"
#include "Output.h"
#include "Ladder.h"

AddLadderAction::AddLadderAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddLadderAction::~AddLadderAction()
{
}

void AddLadderAction::ReadActionParameters() 
{	
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	// Read the startPos parameter
	pOut->PrintMessage("New Ladder: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();
	// Read the endPos parameter
	pOut->PrintMessage("New Ladder: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();	
	// Clear messages
	pOut->ClearStatusBar();
}


// Execute the action
void AddLadderAction::Execute() 
{
	// The first line is to read its parameter first 
	ReadActionParameters();

	if (startPos.GetCellNum() == 1)
	{
		Grid* pGrid = pManager->GetGrid();
		pGrid->PrintErrorMessage("Can't Place Ladder Here .Click To Continue");
		Input* In = pGrid->GetInput();
		int x, y;
		In->GetPointClicked(x, y);
		pGrid->GetOutput()->ClearStatusBar();
	}
	else
	{
		if (startPos.GetCellNum() < endPos.GetCellNum() && endPos.HCell() == startPos.HCell())
		{
			// Create a Ladder object with the parameters read from the user
			Ladder* pLadder = new Ladder(startPos, endPos);
			Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager
			// if there is overlaping
			if (pGrid->IsOverlapping(pLadder))
			{
				pGrid->PrintErrorMessage("Overlaping! Click to continue ...");
				delete pLadder;
			}
			// Add the card object to the GameObject of its Cell:
			else
			{
				bool added = pGrid->AddObjectToCell(pLadder);
				// if the GameObject cannot be added
				if (!added)
				{
					// Print an appropriate message
					pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
					delete pLadder;
				}
				// Here, the ladder is created and added to the GameObject of its Cell, so we finished executing the AddLadderAction
			}


		}
		else
		{
			//If invalid priting error message
			Grid* pGrid = pManager->GetGrid();
			pGrid->PrintErrorMessage("Error: In Input Parameters ! Click to continue ...");
		}
	}
	
	

}
