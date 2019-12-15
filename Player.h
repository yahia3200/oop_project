#pragma once

#include "Grid.h"
#include "Cell.h"

class Player
{
	Cell * pCell;		   // pointer to the current Cell of the player

	const int playerNum;   // the player number (from 0 to MaxPlayerCount-1)
	                       // player number does NOT change after construction (const.)

	int stepCount;		   // step count which is the same as his cellNum: from 1 to NumVerticalCells*NumHorizontalCells
	int wallet;		       // player's wallet (how many coins he has -- integer)
	int justRolledDiceNum; // the current dice number which is just rolled by the player
	int turnCount;         // a counter that starts with 0, is incremented with each dice roll
	                       // and reset again when reached 3
	                       // it is used to indicate when to move and when to add to your wallet
	int NumberOfAttacks; //Determine how many times did the player Attack 
	bool preventplayer;  //bool data member to prevent player from moving
	int poisoncounter;  //refers how many turn player is poisoned
	bool Ispoisoned;  //bool data member indicate if player is poisned or not
	int firecounter;  //refers how many turn player is burnt
	bool IsBurnt;  //bool data member indicate if player is burnt or not

public:

	Player(Cell * pCell, int playerNum); // Constructor making any needed initializations

	// ====== Setters and Getters ======

	void SetCell(Cell * cell);		// A setter for the pCell
	Cell* GetCell() const;			// A getter for the pCell

	void SetWallet(int wallet);		// A setter for the wallet
	int GetWallet() const;			// a getter for the wallet

	int GetTurnCount() const;		// A getter for the turnCount
	int GetRolledDiceNUm();

	void setpreventplayer(bool prev); //A stter for prevent player
	bool getpreventplayer();         //A getter for prevent player

	void setIspoisoned(bool poisonstatus);  //A setter for poisoned player
	void increaseturnsofpoison();  //put 5 counters on the player
	void resetPoisoncounter();  //reset poisoncounter

	void setIsBurnt(bool burntstatus);  //A setter for burnt player
	void increaseturnsofFire();  //put 3 counters on the player
	void resetFirecounter();  //reset firecounter

	void NumberOfAttacksincrements();  //increase  Number Of Attacks for each player with one when attacks
	void resetNumberOfAttacks();  //reset Number of attacks
	///TODO: You can add setters and getters for data members here (if needed)

	// ====== Drawing Functions ======
	void SetturnCount(int);
	void Draw(Output* pOut) const;			// Draws the Player's Circle on its current cell

	void ClearDrawing(Output* pOut) const;	// Clears the Player's Circle from its current cell

	// ====== Game Functions ======

	void Move(Grid * pGrid, int diceNumber);	// Moves the Player with the passed diceNumber 
	                                            // and Applies the Game Object's effect (if any) of the end reached cell 
	                                            // for example, if the end cell contains a ladder, take it
	
	void AppendPlayerInfo(string & playersInfo) const; // Appends player's info to the input string, 
	                                                   // for example: P0(wallet, turnCount)

};

