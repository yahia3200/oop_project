#include "CutCardAction.h"
#include "Input.h"
#include "Output.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"
#include "CardThirteen.h"
#include "CardFourteen.h"

CutCardAction::CutCardAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer

}

CutCardAction::~CutCardAction()
{

}

void CutCardAction::ReadActionParameters()
{
	//getting pointer to output && input class

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	//getting position of the cell clicked and get the cell

	pOut->PrintMessage("Click On The Source Cell..to Cut the Card");
	position = pIn->GetCellClicked();

	//getting card in the clicked cell
	CutCard = pGrid->Getclickedcard(position);
	pOut->ClearStatusBar();

	

}

void CutCardAction::Execute()
{
	//getting pointer to output && input class

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// call read parameter

	ReadActionParameters();

	//cut the card clicked After check there is card in clicked 

	if (CutCard != NULL)
	{
		pGrid->SetClipboard(CutCard);
		pGrid->RemoveObjectFromCell(position);
		pOut->DrawCell(position);
		Card::DecrementCardCounter();
		//Getting pointers to the Cards 
		CardTen* IsCardTen = dynamic_cast<CardTen*>(CutCard);
		CardEleven* IsCardEleven = dynamic_cast<CardEleven*>(CutCard);
		CardTwelve* IsCardTwelve = dynamic_cast<CardTwelve*>(CutCard);
		CardThirteen* IsCardThirteen = dynamic_cast<CardThirteen*>(CutCard);
		CardFourteen* IsCardFourteen = dynamic_cast<CardFourteen*>(CutCard);

		if (IsCardTen)
			IsCardTen->DecrementCardTenCounter();

		else if (IsCardEleven)
			IsCardEleven->DecrementCardElevenCounter();

		else if (IsCardTwelve)
			IsCardTwelve->DecrementCardTwelveCounter();

		else if (IsCardThirteen)
			IsCardThirteen->DecrementCardThirteenCounter();

		else if (IsCardFourteen)
			IsCardFourteen->DecrementCardFourteenCounter();
	}
	else
	{
		int x, y;
		pGrid->PrintErrorMessage("There is No Card In The Clicked Cell...Click to Continue") ;
		pIn->GetPointClicked(x, y);
		pOut->ClearStatusBar();

	}
}