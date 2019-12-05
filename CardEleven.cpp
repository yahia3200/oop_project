#include "CardEleven.h"

bool CardEleven::IsExisted = false;  // set false for first time it's created
Player* CardEleven::ownerplayer = NULL;  // set the owner of the card pointint to null
int CardEleven::price = 0;
int CardEleven::Fees = 0;

CardEleven::CardEleven(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 11;  // set the inherited cardNumber data member with the card number (11 here)
	Cardpos = pos;  //set the inherited Cardpos data member with the card position
	ownerplayer = NULL;  // set the owner of the card pointint to null
}

void CardEleven::ReadCardParameters(Grid* pGrid)
{
	// Get a Pointer to the Input / Output Interfaces from the Grid
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	int x, y;

	// check if card is existed before
	if (!IsExisted)
	{
		// get parameters for card
		pOut->PrintMessage("New CardEleven: Enter its price: ");
		price = pIn->GetInteger(pOut);
		while (price < 0)
		{
			pOut->PrintMessage("Invalid Input. Please enter a positive integer: ");
			price = pIn->GetInteger(pOut);
		}
		pOut->PrintMessage("Price: " + to_string(price) + "  , Click to continue");
		pIn->GetPointClicked(x, y);

		pOut->PrintMessage("New CardEleven: Enter its fee: ");
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

void CardEleven::Apply(Grid* pGrid, Player* pPlayer)
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
		pOut->ClearStatusBar();

		//check if player has enough coins to pay fees
		//if no he is preventd from moving till he pays
		if (pPlayer->GetWallet() < Fees)
		{
			pGrid->GetCurrentPlayer()->setpreventplayer(true);
			pOut->PrintMessage("you are prevented from move till you pay fees. click to contiue");
			pIn->GetPointClicked(x, y);
			pOut->ClearStatusBar();
		}
		//if yes he pays fees and move
		else
		{
			// Deduct the amount of fees from the passing player. 
			pPlayer->SetWallet(pPlayer->GetWallet() - Fees);

			//need to add fees to owner's wallet
			ownerplayer->SetWallet(ownerplayer->GetWallet() + Fees);

			//set preventedplayer false to make player able to move
			pGrid->GetCurrentPlayer()->setpreventplayer(false);

		}


	}
	//unless execute below
	else
	{
		//check if player's wallet has enough coins to buy the cell
		//if has enough coins execute below else execute no thing
		if (pPlayer->GetWallet() >= getprice())
		{
			pOut->PrintMessage("you have reached a station. Do you want to buy it? y/n");
			string ans = pIn->GetSrting(pOut);
			if (ans != "y" || ans != "Y")
			{
				ownerplayer = pPlayer;
				pPlayer->SetWallet(pPlayer->GetWallet() - price);
			}
			else if (ans != "n" || ans != "N")
			{
				pGrid->AdvanceCurrentPlayer();
			}
			else
			{
				pOut->PrintMessage("Invalid Input. Please answer with y/n");
			}
		}

	}

}


int CardEleven::getprice()
{
	return price;
}


int CardEleven::getfees()
{
	return Fees;
}

void CardEleven::Save(ofstream& OutFile, int t)
{
	if (t == 2)
	{
		OutFile << cardNumber << " " << Cardpos.GetCellNum() << " " << price << " " << Fees << '\n';
	}
}

void CardEleven::SetCardParameter(istream& InputFile)
{
	int p, f;
	InputFile >> p >> f;
	price = p;
	Fees = f;
}

CardEleven::~CardEleven()
{
}





