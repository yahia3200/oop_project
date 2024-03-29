#include "ApplicationManager.h"

#include "Grid.h"
#include "AddLadderAction.h"
#include "AddCardAction.h"
#include "RollDiceAction.h"
#include "AddSnakeAction.h"
#include "EditCardAction.h"
#include "DeleteGameObject.h"
#include "InputDiceValue.h"
#include "ToPlayMode.h"
#include "ToDesignModeAction.h"
#include "CopyCardAction.h"
#include "CutCardAction.h"
#include "PasteCardAction.h"
#include "SaveAction.h"
#include "Lightning.h"
#include "NewGame.h"
#include "LoadAction.h"
#include "Ice.h"
#include "Poison.h"
#include "Fire.h"

///TODO: Add #include for all action types

ApplicationManager::ApplicationManager()
{
	// Create Input, output and Grid
	pOut = new Output();
	pIn = pOut->CreateInput();
	pGrid = new Grid(pIn, pOut);
	Lightingptr = new Lightning(this);
	iceptr = new Ice(this);
	poisonptr = new Poison(this);
	fireptr = new Fire(this);
	pGrid->SetLighting(Lightingptr);
	pGrid->SetIce(iceptr);
	pGrid->SetPoison(poisonptr);
	pGrid->SetFire(fireptr);
}

////////////////////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	delete pGrid;
}

//==================================================================================//
//								Interface Management Functions						//
//==================================================================================//

Grid * ApplicationManager::GetGrid() const
{
	return pGrid;
}

void ApplicationManager::UpdateInterface() const
{
	pGrid->UpdateInterface();
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//

ActionType ApplicationManager::GetUserAction() const
{
	// Ask the input to get the action from the user.
	return pIn->GetUserAction();
}

////////////////////////////////////////////////////////////////////////////////////

// Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	// According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case ADD_LADDER:
		pAct = new AddLadderAction(this);
		break;

	case ADD_SNAKE:
		pAct = new AddSnakeAction(this);
		break;

	case ADD_CARD:
		// create an object of AddCardAction here
		pAct = new AddCardAction(this);
		break;

	case ITM_COPY_CARD:
		pAct = new CopyCardAction(this);
		break;

	case ITM_CUT_CARD:
		pAct = new CutCardAction(this);
		break;

	case ITM_Paste_Card:
		pAct = new PasteCardAction(this);
		break;

	case ITM_EDIT_CARD:
		pAct = new EditCardAction(this);
		break;
	case ITM_DELETE_GAME_OBJECT:
		pAct = new DeleteGameObject(this);
		break;
	case EXIT:
		break;

	case ITM_Save_Grid:
		pAct = new SaveAction(this);
		break;

	case TO_PLAY_MODE:
		pAct = new ToPlayMode(this);
		break;

	case ROLL_DICE:
		// create an object of RollDiceAction here
		pAct = new RollDiceAction(this);
		break;

	case INPUT_DICE_VALUE:
		pAct = new InputDiceValue(this);
		break;

	case TO_DESIGN_MODE:
		pAct = new ToDesignModeAction(this);
		break;

	case NEW_GAME:
		pAct = new NewGame(this);
		break;

	case OPEN_GRID:
		pAct = new LoadAction(this);
		break;


	case STATUS:	// a click on the status bar ==> no action
		return;
	}

	// Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute(); // Execute
		delete pAct;	 // Action is not needed any more after executing ==> delete it
		pAct = NULL;
	}
}
