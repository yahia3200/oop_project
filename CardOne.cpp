#include "CardOne.h"

CardOne::CardOne(const CellPosition & pos) : Card(pos) 
{
	cardNumber = 1;
}

CardOne::~CardOne(void)
{
}

void CardOne::ReadCardParameters(Grid * pGrid)
{
	///DONE: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==
	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Input* Pin = pGrid->GetInput();
	Output* Pout = pGrid->GetOutput();

	// 2- Read an Integer from the user using the Input class and set the walletAmount parameter with it
	//    Don't forget to first print to a descriptive message to the user like:"New CardOne: Enter its wallet amount ..."
	Pout->PrintMessage("New CardOne: Enter its wallet amount ");
	walletAmount =Pin->GetInteger(Pout);
	while (walletAmount < 0)
	{
		Pout->PrintMessage("Invalid Input. Please Enter Correct Value : ");
		walletAmount = Pin->GetInteger(Pout);
	}

	// [ Note ]:
	// In CardOne, the only parameter of CardOne is the "walletAmount" value to decrease from player
	// Card parameters are the inputs you need to take from the user in the time of adding the Card in the grid
	// to be able to perform his Apply() action

	// 3- Clear the status bar (Done)
	Pout->ClearStatusBar();
}

Card* CardOne::GetCard(CellPosition& pos)
{
	Card* pcard = new CardOne(pos);
	((CardOne*)pcard )->walletAmount = walletAmount;
	return pcard;

}

void CardOne::Apply(Grid* pGrid, Player* pPlayer)
{
	//Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);

	// Decrement the wallet of pPlayer by the walletAmount data member of CardOne
	pPlayer->SetWallet(pPlayer->GetWallet() - walletAmount);

}

void CardOne::Save(ofstream& OutFile, int t)
{
	//Save the card number,position and its parameters
	if (t == 2)
	{
		OutFile << cardNumber << " " << position.GetCellNum() << " " << walletAmount << '\n';
	}
}

void CardOne::Load(istream& InputFile)
{
	int wallet;
	InputFile >> wallet;
	walletAmount = wallet;
}
