#include "CardTwelve.h"

CardTwelve::CardTwelve(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 10;  // set the inherited cardNumber data member with the card number (10 here)
	ownerplayer = NULL;
}

void CardTwelve::ReadCardParameters(Grid* pGrid)
{
	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	int x, y;

	pOut->PrintMessage("New CardTwelve: Enter its price: ");
	price = pIn->GetInteger(pOut);
	while (price < 0)
	{
		pOut->PrintMessage("Invalid Input. Please enter a positive integer: ");
		price = pIn->GetInteger(pOut);
	}
	pOut->PrintMessage("Price: " + to_string(price) + "  , Click to continue");
	pIn->GetPointClicked(x, y);

	pOut->PrintMessage("New CardTwelve: Enter its fee: ");
	Fees = pIn->GetInteger(pOut);

	while (Fees < 0)
	{
		pOut->PrintMessage("Invalid Input. Please enter a positive integer: ");
		Fees = pIn->GetInteger(pOut);
	}
	pOut->PrintMessage("Fees: " + to_string(Fees) + "  , Click to continue");
	pIn->GetPointClicked(x, y);



	// 3- Clear the status bar
	pOut->ClearStatusBar();
}

void CardTwelve::Apply(Grid* pGrid, Player* pPlayer)
{
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	int x, y;

	Card::Apply(pGrid, pPlayer);

	//check if cell is owned by a player or not
	//if owned execute below
	if (ownerplayer != NULL)
	{
		pOut->PrintMessage("you have reached a bought station.Click to continue ?");
		pIn->GetPointClicked(x, y);
		// Deduct the amount of fees from the passing player. 
		pPlayer->SetWallet(pPlayer->GetWallet() - Fees);
		//need to add fees to owner's wallet
		ownerplayer->SetWallet(ownerplayer->GetWallet() + Fees);
		// لو ابن كوم شكاير الشحاتين الى واقف ع الكارت معهوش فلوس 
		//غالبا هيفضل واقف ف السيل لحد ما يتشحنله فلوس كفاية تخرجه منها بس هناكد
	}
	//unless execute below
	else
	{
		//check if player's wallet has enough coins to buy the cell
		//if has enough coins execute below else execute no thing
		if (pPlayer->GetWallet() >= getprice())
		{
			pOut->PrintMessage("you have reached a station. Do you want to buy it? y/n");
			while (pIn->GetSrting(pOut) != "y" && pIn->GetSrting(pOut) != "n" && pIn->GetSrting(pOut) != "Y" && pIn->GetSrting(pOut) != "N")
			{
				pOut->PrintMessage("Invalid Input. Please answer with y/n");
			}
			if (pIn->GetSrting(pOut) != "y" || pIn->GetSrting(pOut) != "Y")
			{
				ownerplayer = pPlayer;
				pPlayer->SetWallet(pPlayer->GetWallet() - price);
			}

		}

	}
}

int CardTwelve::getprice()
{
	return price;
}


int CardTwelve::getfees()
{
	return Fees;
}


CardTwelve::~CardTwelve()
{
}





