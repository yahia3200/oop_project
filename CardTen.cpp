#include "CardTen.h"

bool CardTen::IsExisted = false;  // set false for first time it's created
Player* CardTen::ownerplayer = NULL;  // set the owner of the card pointint to null
int CardTen::price = 0;
int CardTen::Fees = 0;
bool CardTen::IsSaved = false;
int CardTen::CardTenCounter = 0;

CardTen::CardTen(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 10;  // set the inherited cardNumber data member with the card number (10 here)
	ownerplayer = NULL;  // set the owner of the card pointint to null
	CardTenCounter++;
}

void CardTen::ReadCardParameters(Grid* pGrid)
{
	// Get a Pointer to the Input / Output Interfaces from the Grid
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	int x, y;

	// check if card is existed before
	if (!IsExisted)
	{
		// get parameters for card
		pOut->PrintMessage("CardTen: Enter It's price: ");
		price = pIn->GetInteger(pOut);
		while (price < 0)
		{
			pOut->PrintMessage("Invalid Input. Please Enter A Positive Integer: ");
			price = pIn->GetInteger(pOut);
		}
		pOut->PrintMessage("Price: " + to_string(price) + "  . Click To Continue");
		pIn->GetPointClicked(x, y);

		pOut->PrintMessage("CardTen: Enter It's Fees: ");
		Fees = pIn->GetInteger(pOut);

		while (Fees < 0)
		{
			pOut->PrintMessage("Invalid Input. Please enter a positive integer: ");
			Fees = pIn->GetInteger(pOut);
		}
		pOut->PrintMessage("Fees: " + to_string(Fees) + "  . Click To Continue");
		pIn->GetPointClicked(x, y);

		// set IsExisted true after creating the card for first time
		IsExisted = true;

		// Clear the status bar
		pOut->ClearStatusBar();
	}
}

void CardTen::Apply(Grid* pGrid, Player* pPlayer)
{
	//Calling Apply() of the base class Card to print the message that I reached this card number
	Card::Apply(pGrid, pPlayer);

	// Get a Pointer to the Input / Output Interfaces from the Grid
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	int x, y;


	//check if game was ended before to restart card(s) Property
	if (pGrid->getcard10owner())
	{
		ownerplayer = NULL;
		pGrid->setcard10owner(false);
	}

	//check if cell is owned by a player or not
	//if owned execute below
	if (ownerplayer != NULL)
	{
		pOut->PrintMessage("You Have Reached A Bought Station. Click To Continue ");
		pIn->GetPointClicked(x, y);
		pOut->ClearStatusBar();

		// Deduct the amount of fees from the passing player. 

		pPlayer->SetWallet(pPlayer->GetWallet() - Fees);

		//adding fees to the card owner 's wallet

		ownerplayer->SetWallet(ownerplayer->GetWallet() + Fees);

		//check if player has enough coins to pay fees
		//if no he is preventd from moving till he has enough wallet 
		if (pPlayer->GetWallet() < 0)
		{
			pPlayer->setpreventplayer(true);
			pOut->PrintMessage("You Are Prevented From Move Till You Pay Fees. Click To Continue");
			pIn->GetPointClicked(x, y);
			pOut->ClearStatusBar();
		
		}
		

	}
	//unless execute below
	else
	{
		//check if player's wallet has enough coins to buy the cell
		//if has enough coins execute below else execute no thing
		if (pPlayer->GetWallet() >= price)
		{
			pOut->PrintMessage("You Have Reached A Station. Do You Want To Buy It? y/n ");
			string ans = pIn->GetSrting(pOut);
			do
			{
				if (ans == "y" || ans == "Y")
				{
					ownerplayer = pPlayer;
					pPlayer->SetWallet(pPlayer->GetWallet() - price);
					pOut->PrintMessage("Congratulations you have bought all cards 10 in grid. Press anywhere to continue  ");
					int x, y;
					pIn->GetPointClicked(x, y);
					pOut->ClearStatusBar();
				}
				else if (ans == "n" || ans == "N")
				{
					pOut->ClearStatusBar();
				}
				else
				{
					pOut->PrintMessage("Invalid Input. Please Answer Choose y/n");
					ans = pIn->GetSrting(pOut);
				}
			} while (ans != "y" && ans != "Y" && ans != "n" && ans != "N");
		}

	}

}

Card* CardTen::GetCard(CellPosition& pos)
{
	Card* cptr = new CardTen(pos);
	((CardTen*)cptr)->price = price;
	((CardTen*)cptr)->Fees = Fees;
	((CardTen*)cptr)->ownerplayer = ownerplayer;
	((CardTen*)cptr)->IsExisted = IsExisted;
	((CardTen*)cptr)->IsSaved = IsSaved;

	return cptr;
}

void CardTen::setIsExisted(bool Existed)
{
	IsExisted = Existed;
}

void CardTen::Load(istream& InputFile)
{
	if (!IsExisted)
	{
		int p, f;
		InputFile >> p >> f;
		price = p;
		Fees = f;
		IsExisted = true;
	}
	
}

void CardTen::Save(ofstream& OutFile, int t)
{
	if (t == 2)
	{
		if (!IsSaved)
		{
			OutFile << cardNumber << " " << position.GetCellNum() << " " << price << " " << Fees << '\n';
			IsSaved = true;
		}
			
		else
			OutFile << cardNumber << " " << position.GetCellNum() << '\n';
	}
}

void CardTen::SetIsSaved(bool s)
{
	IsSaved = s;
}

void CardTen::DecrementCardTenCounter()
{
	CardTenCounter--;

	if (CardTenCounter == 0)
		IsExisted = false;
}

CardTen::~CardTen()
{
	CardTenCounter--;

	if (CardTenCounter == 0)
		IsExisted = false;
}
