#include "CardTwo.h"

CardTwo::CardTwo(const CellPosition& cpos):Card(cpos)
{
	cardNumber = 2;
}

void CardTwo::ReadCardParameters(Grid* pGrid)
{
	Input* Pin = pGrid->GetInput();
	Output* Pout = pGrid->GetOutput();
	Pout->PrintMessage("New CardTwo: Enter its wallet amount ");
	walletAmount = Pin->GetInteger(Pout);
	while (walletAmount < 0)
	{
		Pout->PrintMessage("Invalid Input. Please Enter Correct Value : ");
		walletAmount = Pin->GetInteger(Pout);
	}

	Pout->ClearStatusBar();
}

void CardTwo::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);

	//InCrementing Wallet Of Player By walletAmount
	pPlayer->SetWallet(pPlayer->GetWallet() + walletAmount);
}

Card* CardTwo::GetCard(CellPosition& pos)
{
	Card* cptr = new CardTwo(pos);
	((CardTwo*)cptr)->walletAmount;
	return cptr;
}

void CardTwo::Save(ofstream& OutFile, int t)
{
	//Saving the card number ,position and wallet amount...
	if (t == 2)
	{
		OutFile << cardNumber << " " << position.GetCellNum() << " " << walletAmount << '\n';
	}
}

void CardTwo::Load(istream& InputFile)
{
	int wallet;
	InputFile >> wallet;
	walletAmount = wallet;
}

CardTwo::~CardTwo()
{
}
