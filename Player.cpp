#include "Player.h"

#include "GameObject.h"
#include "Ladder.h"
#include "Snake.h"
#include "Card.h"
#include "Lightning.h"
#include "Ice.h"
#include "Poison.h"
#include "Fire.h"

Player::Player(Cell* pCell, int playerNum) : stepCount(0), wallet(100), playerNum(playerNum), preventplayer(false)
{
	this->pCell = pCell;
	this->turnCount = 0;
	NumberOfAttacks = 0;
	poisoncounter = 0;
	Ispoisoned = false;
	firecounter = 0;
	IsBurnt = false;
	icecounter = 0;
	Isiced = false;
	// Make all the needed initialization or validations
}

// ====== Setters and Getters ======

void Player::SetCell(Cell* cell)
{
	pCell = cell;
}

Cell* Player::GetCell() const
{
	return pCell;
}

void Player::SetWallet(int wallet)
{
	this->wallet = wallet;
}

int Player::GetWallet() const
{
	return wallet;
}

void Player::SetturnCount(int c)
{
	turnCount = c;
}

int Player::GetTurnCount() const
{
	return turnCount;
}

int Player::GetRolledDiceNUm()
{
	return justRolledDiceNum;
}



void Player::setpreventplayer(bool prev)
{
	preventplayer = prev;
}

bool Player::getpreventplayer()
{
	return preventplayer;
}

void Player::setIspoisoned(bool poisonstatus)
{
	Ispoisoned = poisonstatus;
}

void Player::increaseturnsofpoison()
{
	poisoncounter += 5;
}

void Player::resetPoisoncounter()
{
	poisoncounter = 0;
}

int Player::GetPoisoncounter()
{
	return poisoncounter;
}

void Player::setIsBurnt(bool burntstatus)
{
	IsBurnt = burntstatus;
}

void Player::increaseturnsofFire()
{
	firecounter += 3;
}

void Player::resetFirecounter()
{
	firecounter = 0;
}

int Player::GetFirecounter()
{
	return firecounter;
}

void Player::setIsiced(bool icedstatus)
{
	Isiced = icedstatus;
}

void Player::increaseturnsoice()
{
	icecounter++;
}

void Player::reseticecounter()
{
	icecounter = 0;
}

int Player::Geticecounter()
{
	return icecounter;
}



void Player::NumberOfAttacksincrements()
{
	NumberOfAttacks++;
}

void Player::resetNumberOfAttacks()
{
	NumberOfAttacks = 0;
}

// ====== Drawing Functions ======

void Player::Draw(Output* pOut) const
{
	//Drawing the player using output class
	color playerColor = UI.PlayerColors[playerNum];
	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, playerColor);

}

void Player::ClearDrawing(Output* pOut) const
{
	//This is used to clear the drawing of player in a certian Cell (For Movement)
	color cellColor = pCell->HasCard() ? UI.CellColor_HasCard : UI.CellColor_NoCard;
	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, cellColor);

}

// ====== Game Functions ======

void Player::Move(Grid* pGrid, int diceNumber)
{
	

	// 2- Check the turnCount to know if the wallet recharge turn comes (recharge wallet instead of move)
	//    If yes, recharge wallet and reset the turnCount and return from the function (do NOT move)

	// 3- Set the justRolledDiceNum with the passed diceNumber

	// 4- Get the player current cell position, say "pos", and add to it the diceNumber (update the position)
	//    Using the appropriate function of CellPosition class to update "pos"

	// 5- Use pGrid->UpdatePlayerCell() func to Update player's cell POINTER (pCell) with the cell in the passed position, "pos" (the updated one)
	//    the importance of this function is that it Updates the pCell pointer of the player and Draws it in the new position

	// 6- Apply() the game object of the reached cell (if any)

	
	
	// 7- Check if the player reached the end cell of the whole game, and if yes, Set end game with true: pGrid->SetEndGame(true)
	//Increment the turnCount
	turnCount++;
	//Getting pointer to the input && output Interfaces from the Grid
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	string ans;
	//check if player is iced if yes
	if (Isiced)
	{
		//deduct 1 number from his dice roll and a poison counter 
		diceNumber = 0;
		--icecounter;
		pOut->PrintMessage("You are prevented from moving, you can't use a special attack this turn or recharging. Click Anywhere to continue  ");
		int x, y;
		pIn->GetPointClicked(x, y);//Waiting user Action
		pOut->ClearStatusBar();		//if poison counters equal 0 means player is no poisoned any more
	}
	//Check the turnCount if it is equal 3 to recharge or use special attack
	if (turnCount == 3)
	{
		turnCount = 0;
		// check if player used all his chance to special attack
		//if no:.......
		if (NumberOfAttacks < 2)
		{
			//check if player is iced or not to indicate to ask him if he want to recharge or use special attack
			if (!Isiced)
			{
				//check if player wants to special attack
				pOut->PrintMessage("Do you wish to launch a special attack instead of recharging? y/n");
				ans = pIn->GetSrting(pOut);
				
				if (ans == "y" || ans == "Y")
				{
					pOut->PrintMessage("Press 1.Ice, 2.Fire, 3.Poison, 4.Lightning...");
					int Answer = pIn->GetInteger(pOut);
					Lightning* Light = pGrid->GetLight();
					Ice* ice = pGrid->GetIce();
					Poison* poison = pGrid->GetPoison();
					Fire* fire = pGrid->GetFire();

					switch (Answer)
					{
					case 1:
						ice->Execute();
						break;
					case 2:
						fire->Execute();
						break;
					case 3:
						poison->Execute();
						break;
					case 4:
						Light->Execute();
						break;
					default:
						break;
					}
				}
				else if (ans == "n" || ans == "N") {
					wallet = wallet + diceNumber * 10;
					pOut->PrintMessage("In This Turn you wont Play but ur Wallet will be increased. Click Anywhere to continue  ");
					int x, y;
					pIn->GetPointClicked(x, y);//Waiting user Action
					pOut->ClearStatusBar();
				}
			}
			else if (ans == "n" || ans == "N") {
				wallet = wallet + diceNumber * 10;
				pOut->PrintMessage("In This Turn you wont Play but ur Wallet will be increased. Click Anywhere to continue  ");
			}
			else
			{
				//check if player is iced or not ti indicate to ask him if he recharges
				if (!Isiced)
				{
					wallet = wallet + diceNumber * 10;
					pOut->PrintMessage("In This Turn you wont Play but ur Wallet will be increased,Click Anywhere to continue  ");
					int x, y;
					pIn->GetPointClicked(x, y);//Waiting user Action
					pOut->ClearStatusBar();
				}
			}
		}
		else
		{
			wallet = wallet + diceNumber * 10;
			pOut->PrintMessage("In This Turn you wont Play but ur Wallet will be increased,Click Anywhere to continue  ");
			int x, y;
			pIn->GetPointClicked(x, y);//Waiting user Action
			pOut->ClearStatusBar();
		}
	
	}
	else
	{
		justRolledDiceNum = diceNumber;
		if (pGrid->GetCurrentPlayer()->GetCell()->GetCellPosition().GetCellNum() + diceNumber <= 99 && !preventplayer)
		{
			//check if player is poisoned if yes
			if (Ispoisoned)
			{
				//deduct 1 number from his dice roll and a poison counter 
				--justRolledDiceNum;
				--poisoncounter;
				//if poison counters equal 0 means player is no poisoned any more
				if (poisoncounter == 0)
				{
					Ispoisoned = false;
				}
			}

			//check if player is burnt if yes
			if (IsBurnt)
			{
				//deduct 1 number from his dice roll and a poison counter 
				wallet -= 20;
				--firecounter;
				//if poison counters equal 0 means player is no poisoned any more
				if (firecounter == 0)
				{
					IsBurnt = false;
				}
			}

			this->ClearDrawing(pOut);

			CellPosition pos;
			pos = pos.GetCellPositionFromNum(pCell->GetCellPosition().GetCellNum() + justRolledDiceNum);


			if (pos.GetCellNum() + justRolledDiceNum <= 99)
				pos.AddCellNum(justRolledDiceNum);
			pGrid->UpdatePlayerCell(this, pos);

			color playerColor = UI.PlayerColors[playerNum];


			///TODO: use the appropriate output function to draw the player with "playerColor" (Done)
			pOut->DrawPlayer(pos, playerNum, playerColor);
			if (pCell->HasLadder())
			{
				Ladder* Lptr = pCell->HasLadder();
				Lptr->Apply(pGrid, this);

				if (pCell->HasCard())
				{
					Card* Cardptr = pCell->HasCard();
					Cardptr->Apply(pGrid, this);
				}
			}
			else if (pCell->HasSnake())
			{
				Snake* Snakeptr = pCell->HasSnake();
				Snakeptr->Apply(pGrid, this);

				if (pCell->HasCard())
				{
					Card* Cardptr = pCell->HasCard();
					Cardptr->Apply(pGrid, this);
				}
			}
			else if (pCell->HasCard())
			{
				Card* Cardptr = pCell->HasCard();
				Cardptr->Apply(pGrid, this);
			}

			if (pCell->GetCellPosition().GetCellNum() == 99)
				pGrid->SetEndGame(true);
			if (pGrid->GetEndGame())
				pOut->PrintMessage("Player " + to_string(this->playerNum) + " Won the Game...");
		}
	}

	//check if icecounters are finished to remove iced status on him
	if (icecounter == 0)
	{
		Isiced = false;
	}
}

void Player::AppendPlayerInfo(string& playersInfo) const
{
	playersInfo += "P" + to_string(playerNum) + "(";
	playersInfo += to_string(wallet) + ", ";
	playersInfo += to_string(turnCount) + ")";
}