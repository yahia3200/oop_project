#include "Player.h"

#include "GameObject.h"
#include "Ladder.h"
#include "Snake.h"
#include "Card.h"
Player::Player(Cell * pCell, int playerNum) : stepCount(0), wallet(100), playerNum(playerNum)
{
	this->pCell = pCell;
	this->turnCount = 0;

	// Make all the needed initialization or validations
}

// ====== Setters and Getters ======

void Player::SetCell(Cell * cell)
{
	pCell = cell;
}

Cell* Player::GetCell() const
{
	return pCell;
}

void Player::SetWallet(int wallet)
{
	//this->wallet = wallet;
	this->wallet = wallet>0?wallet:0;
	// Make any needed validations
}

int Player::GetWallet() const
{
	return wallet;
}

int Player::GetTurnCount() const
{
	return turnCount;
}

int Player::GetRolledDiceNUm()
{
	return justRolledDiceNum;
}

// ====== Drawing Functions ======

void Player::SetturnCount(int c)
{
	turnCount = c;
}

void Player::Draw(Output* pOut) const
{
	color playerColor = UI.PlayerColors[playerNum];


	///TODO: use the appropriate output function to draw the player with "playerColor" (Done)
	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, playerColor);

}

void Player::ClearDrawing(Output* pOut) const
{
	color cellColor = pCell->HasCard() ? UI.CellColor_HasCard : UI.CellColor_NoCard;
	

	///TODO: use the appropriate output function to draw the player with "cellColor" (to clear it) (Done)
	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, cellColor);
	
}

// ====== Game Functions ======

void Player::Move(Grid * pGrid, int diceNumber)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below (Done)


	// == Here are some guideline steps (numbered below) to implement this function ==


	// 1- Increment the turnCount because calling Move() means that the player has rolled the dice once
	
	// 2- Check the turnCount to know if the wallet recharge turn comes (recharge wallet instead of move)
	//    If yes, recharge wallet and reset the turnCount and return from the function (do NOT move)
	
	// 3- Set the justRolledDiceNum with the passed diceNumber

	// 4- Get the player current cell position, say "pos", and add to it the diceNumber (update the position)
	//    Using the appropriate function of CellPosition class to update "pos"

	// 5- Use pGrid->UpdatePlayerCell() func to Update player's cell POINTER (pCell) with the cell in the passed position, "pos" (the updated one)
	//    the importance of this function is that it Updates the pCell pointer of the player and Draws it in the new position

	// 6- Apply() the game object of the reached cell (if any)

	// 7- Check if the player reached the end cell of the whole game, and if yes, Set end game with true: pGrid->SetEndGame(true)
	turnCount++;
	Output* pOut = pGrid->GetOutput();

	if (turnCount == 3)
	{
		turnCount = 0;
		SetWallet(wallet + 10 * diceNumber);
	}

	else
	{
	
		justRolledDiceNum = diceNumber;
		this->ClearDrawing(pOut);

		//CellPosition pos = pCell->GetCellPosition();
		CellPosition pos;
		pos = pos.GetCellPositionFromNum(pCell->GetCellPosition().GetCellNum() + justRolledDiceNum);

		//pos.GetCellPositionFromNum(pos.GetCellNum() + justRolledDiceNum);
		pos.AddCellNum(justRolledDiceNum);
		pGrid->UpdatePlayerCell(this, pos);
		//Draw(pOut);
		color playerColor = UI.PlayerColors[playerNum];


		///TODO: use the appropriate output function to draw the player with "playerColor" (Done)
		pOut->DrawPlayer(pos, playerNum, playerColor);
		pCell = this->GetCell();
		if(pCell->HasLadder())
		{
			Ladder* Lptr = pCell->HasLadder();
			Lptr->Apply(pGrid, this);
		}
		else if (pCell->HasSnake())
		{
			Snake* Snakeptr = pCell->HasSnake();
			Snakeptr->Apply(pGrid, this);
		}
		else if (pCell->HasCard())
		{
			Card* Cardptr = pCell->HasCard();
			Cardptr->Apply(pGrid,this);
		}
		//pCell->GetGameObject()->Apply(pGrid, this);
		if (pCell->GetCellPosition().GetCellNum() == 99)pGrid->SetEndGame(true);
	}

}

void Player::AppendPlayerInfo(string & playersInfo) const
{
	playersInfo += "P" + to_string(playerNum) + "(" ;
	playersInfo += to_string(wallet) + ", ";
	playersInfo += to_string(turnCount) + ")";
}