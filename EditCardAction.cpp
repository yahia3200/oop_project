#include "EditCardAction.h"
#include "Input.h"
#include "Output.h"
#include "CardOne.h"
#include "CardTwo.h"
#include "CardThree.h"
#include "CardFour.h"
#include "CardFive.h"
#include "CardSix.h"
#include "CardSeven.h"
#include "CardEight.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"
#include "CardThirteen.h"
#include "CardFourteen.h"
EditCardAction::EditCardAction(ApplicationManager* pApp) :Action(pApp)
{
	CardNumber = 0;
}

void EditCardAction::ReadActionParameters()
{
	////Allocation of Grid ,Input,Output Pointers
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("Click on The Sourse To Edit ..");
	cardPosition = pIn->GetCellClicked();
	Cardptr = pGrid->Getclickedcard(cardPosition); //Get the card of clicked Cell position 
	
	if (Cardptr!=NULL) //Check of not null pointer 
	{
	CardNumber = Cardptr->GetCardNumber();
	}
	

}

void EditCardAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	if (CardNumber != 0)
	{
		switch (CardNumber)

		{
		case 1:
			Cardptr->ReadCardParameters(pGrid);
			break;
		case 2:
			Cardptr->ReadCardParameters(pGrid);
			break;
		case 9:
			Cardptr->ReadCardParameters(pGrid);
			break;
		case 10:
			((CardTen*)Cardptr)->setIsExisted(false);
			Cardptr->ReadCardParameters(pGrid);
			((CardTen*)Cardptr)->setIsExisted(true);

			break;
		case 11:
			((CardEleven*)Cardptr)->setIsExisted(false);
			Cardptr->ReadCardParameters(pGrid);
			((CardEleven*)Cardptr)->setIsExisted(true);

			break;
		case 12:
			((CardTwelve*)Cardptr)->setIsExisted(false);

			Cardptr->ReadCardParameters(pGrid);
			((CardTwelve*)Cardptr)->setIsExisted(true);

			break;
		case 13:
			((CardThirteen*)Cardptr)->setIsExisted(false);

			Cardptr->ReadCardParameters(pGrid);
			((CardThirteen*)Cardptr)->setIsExisted(true);

			break;
		case 14:
			((CardFourteen*)Cardptr)->setIsExisted(false);

			Cardptr->ReadCardParameters(pGrid);
			((CardFourteen*)Cardptr)->setIsExisted(true);

			break;
		default:
			pOut->PrintMessage("This Card Cannot Be Editted,Press any where to continue..");
			int x, y;
			pIn->GetPointClicked(x, y);
			pOut->ClearStatusBar();
			break;
		}
	}
}

EditCardAction::~EditCardAction()
{
}
