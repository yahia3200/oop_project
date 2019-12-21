#include "AddSnakeAction.h"
#include "Input.h"
#include "Output.h"
#include "Snake.h"
AddSnakeAction::AddSnakeAction(ApplicationManager* pApp):Action(pApp)
{
}

void AddSnakeAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	// Read the startPos parameter
	pOut->PrintMessage("New Snake: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();
	// Read the endPos parameter
	pOut->PrintMessage("New Snake: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();
	// Clear messages
	pOut->ClearStatusBar();
}

void AddSnakeAction::Execute()
{
	// The first line is to read its parameter first 
    // and hence initializes its data members
	ReadActionParameters();

	if (startPos.GetCellNum() == 99)
	{
		Grid* pGrid = pManager->GetGrid();
		pGrid->PrintErrorMessage("Can't Place Snake Here .Click To Continue");
		Input* In = pGrid->GetInput();
		int x, y;
		In->GetPointClicked(x, y);
		pGrid->GetOutput()->ClearStatusBar();
	}
	else
	{
		if (startPos.GetCellNum() > endPos.GetCellNum() && endPos.HCell() == startPos.HCell())
		{
			// Create a Snake object with the parameters read from the user
			Snake* pSnake = new Snake(startPos, endPos);

			Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager
			// if there is overlaping
			if (pGrid->IsOverlapping(pSnake))
			{
				pGrid->PrintErrorMessage("Overlaping! Click to continue ...");
				delete pSnake;
			}
			else
			{
				// Add the card object to the GameObject of its Cell:
				bool added = pGrid->AddObjectToCell(pSnake);
				// if the GameObject cannot be added
				if (!added)
				{
					// Print an appropriate message
					pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
					delete pSnake;
				}
				// Here, the Snake is created and added to the GameObject of its Cell, so we finished executing the AddLadderAction
			}
		}
		else
		{
			//if invalid print Error Message
			Grid* pGrid = pManager->GetGrid();
			pGrid->PrintErrorMessage("Error: In Input Parameters ! Click to continue ...");
		}
	}

	
}

AddSnakeAction::~AddSnakeAction()
{
}
