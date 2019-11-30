#include "CardOne.h"

CardOne::CardOne(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 1; // set the inherited cardNumber data member with the card number (1 here)
	Cardpos = pos;
}

CardOne::~CardOne(void)
{
}

void CardOne::ReadCardParameters(Grid * pGrid)
{
	
	
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	Input* Pin = pGrid->GetInput();
	Output* Pout = pGrid->GetOutput();
	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Pout->PrintMessage("New CardOne: Enter its wallet amount ");
	walletAmount=Pin->GetInteger(Pout);
	// 2- Read an Integer from the user using the Input class and set the walletAmount parameter with it
	//    Don't forget to first print to a descriptive message to the user like:"New CardOne: Enter its wallet amount ..."
	

	// [ Note ]:
	// In CardOne, the only parameter of CardOne is the "walletAmount" value to decrease from player
	// Card parameters are the inputs you need to take from the user in the time of adding the Card in the grid
	// to be able to perform his Apply() action

	// 3- Clear the status bar (Done)
	Pout->ClearStatusBar();
}

void CardOne::Apply(Grid* pGrid, Player* pPlayer)
{
		
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	

	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number

	// 2- Decrement the wallet of pPlayer by the walletAmount data member of CardOne
	Card::Apply(pGrid, pPlayer);
	//This Step Need Validation (What If Wallet Is Negative ? ) (Note In Player.cpp)
	pPlayer->SetWallet(pPlayer->GetWallet() - walletAmount);

}

void CardOne::SetWalletAmount(int w)
{
	walletAmount = w;
}

void CardOne::Save(ofstream& OutFile, int t)
{
	if (t == 2)
	{
		OutFile << cardNumber << " " << Cardpos.GetCellNum() << " " << walletAmount << '\n';
	}
}
