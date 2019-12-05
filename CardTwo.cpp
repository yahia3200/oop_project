#include "CardTwo.h"

CardTwo::CardTwo(const CellPosition& cpos):Card(cpos)
{
	cardNumber = 2;
	Cardpos = cpos;
}

void CardTwo::ReadCardParameters(Grid* pGrid)
{
	//Description in CardOne
	Input* Pin = pGrid->GetInput();
	Output* Pout = pGrid->GetOutput();
	Pout->PrintMessage("New CardOne: Enter its wallet amount ");
	walletAmount = Pin->GetInteger(Pout);
	Pout->ClearStatusBar();
}

void CardTwo::Apply(Grid* pGrid, Player* pPlayer)
{
	//InCrementing Wallet Of Player By walletAmount
	Card::Apply(pGrid, pPlayer);
	pPlayer->SetWallet(pPlayer->GetWallet() + walletAmount);
}

void CardTwo::Save(ofstream& OutFile, int t)
{
	if (t == 2)
	{
		OutFile << cardNumber << " " << Cardpos.GetCellNum() << " " << walletAmount << '\n';
	}
}

void CardTwo::SetCardParameter(istream& InputFile)
{
	int wallet;
	InputFile >> wallet;
	walletAmount = wallet;
}

CardTwo::~CardTwo()
{
}
