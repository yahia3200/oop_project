#include "SaveAction.h"
#include "Grid.h"
#include "Input.h"
#include "Output.h"
#include "Ladder.h"
#include "Snake.h"
#include "Card.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"
#include "CardThirteen.h"
#include "CardFourteen.h"
#include <fstream>

SaveAction::SaveAction(ApplicationManager* pApp) :Action(pApp)
{

}
void SaveAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Get The File Name From The User
	pOut->PrintMessage("Enter The File Name: ");
	fileName = pIn->GetSrting(pOut);

	pOut->ClearStatusBar();
}

void SaveAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();

	// Create A New File Write In It
	//Note: If There's Alredy A File With The Same Name 
	//      This Will Override That File
	ofstream OutFile;
	OutFile.open(fileName,ios::out);

	// Save Ladders Number Then Save All Ladders 
	Ladder::SaveLaddersNumber(OutFile);
	pGrid->SaveAll(OutFile,0);

	// Save Snakes Number Then Save All Snakes
	Snake::SaveSnakesNumber(OutFile);
	pGrid->SaveAll(OutFile, 1);

	// This Required To Save Parameters Of Card 10 To 14 Only Once
	CardTen::SetIsSaved(false);
	CardEleven::SetIsSaved(false);
	CardTwelve::SetIsSaved(false);
	CardThirteen::SetIsSaved(false);
	CardFourteen::SetIsSaved(false);

	// Save Cards Number Then Save All Cards
	Card::SaveCardsNumber(OutFile);
	pGrid->SaveAll(OutFile, 2);

	OutFile.close();
}
SaveAction::~SaveAction()
{

}