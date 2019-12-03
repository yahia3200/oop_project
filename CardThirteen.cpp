﻿#include "CardThirteen.h"

bool CardThirteen::IsExisted = false;  // set false for first time it's created
int CardThirteen::price = 0;
int CardThirteen::Fees = 0;

CardThirteen::CardThirteen(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 13;  // set the inherited cardNumber data member with the card number (13 here)
	Cardpos = pos;  //set the inherited Cardpos data member with the card position
	ownerplayer = NULL;  // set the owner of the card pointint to null

}

void CardThirteen::ReadCardParameters(Grid* pGrid)
{
	// Get a Pointer to the Input / Output Interfaces from the Grid
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	int x, y;

	// check if card is existed before
	if (!IsExisted)
	{
		// get parameters for card
		pOut->PrintMessage("New CardThirteen: Enter its price: ");
		price = pIn->GetInteger(pOut);
		while (price < 0)
		{
			pOut->PrintMessage("Invalid Input. Please enter a positive integer: ");
			price = pIn->GetInteger(pOut);
		}
		pOut->PrintMessage("Price: " + to_string(price) + "  , Click to continue");
		pIn->GetPointClicked(x, y);

		pOut->PrintMessage("New CardThirteen: Enter its fee: ");
		Fees = pIn->GetInteger(pOut);

		while (Fees < 0)
		{
			pOut->PrintMessage("Invalid Input. Please enter a positive integer: ");
			Fees = pIn->GetInteger(pOut);
		}
		pOut->PrintMessage("Fees: " + to_string(Fees) + "  , Click to continue");
		pIn->GetPointClicked(x, y);

		// set IsExisted true after creating the card for first time
		IsExisted = true;

		// 3- Clear the status bar
		pOut->ClearStatusBar();
	}
}

void CardThirteen::Apply(Grid* pGrid, Player* pPlayer)
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

int CardThirteen::getprice()
{
	return price;
}


int CardThirteen::getfees()
{
	return Fees;
}

void CardThirteen::Save(ofstream& OutFile, int t)
{
	if (t == 2)
	{
		OutFile << cardNumber << " " << Cardpos.GetCellNum() << " " << price << " " << Fees << '\n';
	}
}

void CardThirteen::SetCardParameter(istream& InputFile)
{
	int p, f;
	InputFile >> p >> f;
	price = p;
	Fees = f;
}

CardThirteen::~CardThirteen()
{
}





