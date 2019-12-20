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
	//Setting the cardNumber Intially 0 
	//An indicator that there is no card is chosen by user
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
		//if the card is exsist CardNumber will get the card number
	CardNumber = Cardptr->GetCardNumber();
	}
	

}

void EditCardAction::Execute()
{
	ReadActionParameters(); //Reading The parameters (cell position which will be edited
	Grid* pGrid = pManager->GetGrid(); //Getting pointer to the Grid
	Input* pIn = pGrid->GetInput(); //Getting pointer to the input Class to Get UserAction waiting to Clear Statusbar
	Output* pOut = pGrid->GetOutput(); //Getting Pointer to Output Class using Grid to Print Messages 
	
	if (CardNumber != 0) //To check if a card is chosen
	{
		//this switch case is made to check for the cards that have parameters can be editted,otherwise print a message that 
		//the card cannot be edited and waiting user action
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
			//From card 10 to 14 This cards parameters is read once ,when the first one is added ,so the function is Existed will be setted false
			//To make the card Customizable again and sets its parameter again the switch the function to false
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
