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

	pOut->PrintMessage("Enter The File Name: ");
	fileName = pIn->GetSrting(pOut);

	pOut->ClearStatusBar();
}

void SaveAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();


	ofstream OutFile;
	OutFile.open(fileName,ios::out);

	Ladder::SaveLaddersNumber(OutFile);
	pGrid->SaveAll(OutFile,0);

	Snake::SaveSnakesNumber(OutFile);
	pGrid->SaveAll(OutFile, 1);

	CardTen::SetIsSaved(false);
	CardEleven::SetIsSaved(false);
	CardTwelve::SetIsSaved(false);
	CardThirteen::SetIsSaved(false);
	CardFourteen::SetIsSaved(false);
	Card::SaveCardsNumber(OutFile);
	pGrid->SaveAll(OutFile, 2);

	OutFile.close();
}
SaveAction::~SaveAction()
{

}