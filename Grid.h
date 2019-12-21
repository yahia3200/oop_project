#pragma once

#include "UI_Info.h"
#include "DEFS.h"
#include "Input.h"
#include "Output.h"
#include "CellPosition.h"

// forward declarations (the includes are in the cpp)
class Cell;
class GameObject;
class Ladder;
class Card;
class Player;
class Snake;
class Lightning;
class Ice;
class Poison;
class Fire;
class Grid
{
	Output * pOut;   // A pointer to the Output object
	Input * pIn;     // A pointer to the Input object

	Cell * CellList[NumVerticalCells][NumHorizontalCells];  // An array of "Pointers" to All Cells of the Grid Cells
															// We make it array of pointers not objects because
															// there are NO default constructor for class Cell

	Player* PlayerList[MaxPlayerCount]; // An array of "Pointers" to the Players of the Game (MaxPlayerCount Players)
	int currPlayerNumber;   // The player number that has the turn to play 
							// currPlayerNumber is: from 0 to MaxPlayerCount - 1

	Card * Clipboard;	   // This is used in copy/cut/paste card (should be set in copy/cut and got in paste)

	bool endGame;	       // A boolean indicating if the Game is ended or not (a player reaches the end cell of the grid or not)
	
	bool card10owner;     // A boolean indicating if the Game was ended or not to restart card(s) 10 Property
	bool card11owner;     // A boolean indicating if the Game was ended or not to restart card(s) 11 Property
	bool card12owner;     // A boolean indicating if the Game was ended or not to restart card(s) 12 Property
	bool card13owner;     // A boolean indicating if the Game was ended or not to restart card(s) 13 Property
	bool card14owner;     // A boolean indicating if the Game was ended or not to restart card(s) 14 Property

	//setters and getters for special attack
	Lightning* Light;
	Ice* ice;
	Poison* poison;
	Fire* fire;
public:

	Grid(Input * pIn, Output * pOut);	  // Gives the Grid a Pointer to the Output Object and the Input Object
										  // and makes any needed initializations

	// ========= Adding or Removing GameObjects to Cells =========

	bool AddObjectToCell(GameObject * pNewObject);		 // Adds a GameObject to the Cell of its "position" data member
	                                                     // only if the Cell does NOT already contain an object, 
	                                                     // otherwise return false and don't add

	void RemoveObjectFromCell(const CellPosition & pos); // Removes the GameObject of the Cell of the passed "position"

	void UpdatePlayerCell(Player * player, const CellPosition & newPosition); // Update the player's pCell with the CellList's Cell pointer of the "newPosition",
	                                                                          // Clears the player's circle from the previous cell
	    																	  // and  Draws it in the new cell

	//setters and getters for special attack
	void SetLighting(Lightning* L);
	void SetIce(Ice* i);
	void SetPoison(Poison* p);
	void SetFire(Fire* f);
	Ice* GetIce()const;
	Lightning* GetLight()const;
	Poison* GetPoison()const;
	Fire* GetFire()const;
	// ========= Setters and Getters Functions =========

	Input * GetInput() const;	// Gets a Pointer to the Input
	Output * GetOutput() const; // Gets a Pointer to the Output 

	void SetClipboard(Card * card);  // A setter to be used in copy/cut (in order NOT to break class responsibilities)
	Card * GetClipboard() const;	 // A getter to be used in paste (in order NOT to break class responsibilities)

	void SetEndGame(bool endGame);	 // A setter for endGame data member
	bool GetEndGame() const;		 // A getter for endGame data member

	void setcard10owner(bool x);	 // A setter for card10owner data member
	bool getcard10owner() const;	 // A getter for card10owner data member
	void setcard11owner(bool x);	 // A setter for card11owner data member
	bool getcard11owner() const;	 // A getter for card11owner data member
	void setcard12owner(bool x);	 // A setter for card12owner data member
	bool getcard12owner() const;	 // A getter for card12owner data member
	void setcard13owner(bool x);	 // A setter for card13owner data member
	bool getcard13owner() const;	 // A getter for card13owner data member
	void setcard14owner(bool x);	 // A setter for card14owner data member
	bool getcard14owner() const;	 // A getter for card14owner data member


	void AdvanceCurrentPlayer();     // Increments the currPlayerNum and if reaches MaxPlayerCount reset to 0 (using %)
 
	///TODO: add any needed setter/getter "EXCEPT" ANY setters or getters of "CellList" or "PlayerList" (Forbidden for class Responsibilities)

	// ========= Other Getters =========
	Card* Getclickedcard(CellPosition& position); //getting the card in the cell
	Player * GetCurrentPlayer() const;	// Gets a Pointer to the Current Player	                                    
	Ladder * GetNextLadder(const CellPosition & position);  // Gets a Pointer to the first Ladder after the passed "position"
	Snake* GetNextSnake(const CellPosition& position); //Gets a Point to the first Snake after the passed "position"
	// ========= User Interface Functions =========

	void UpdateInterface() const;		// It Updates the Grid according to the last state of the game
	                                    // In Design mode, it draws all cells/cards THEN all ladders/snakes THEN all players
	                                    // In Play mode, it only draws the player's info on the right side of the toolbar
	                                    // Note: UpdatePlayerCell() function --> already update drawing players in Play Mode
	                                    //       and the cards/snakes/ladders positions do NOT change already in Play Mode

	void PrintErrorMessage(string msg); // Prints an error message on statusbar, Waits for mouse click then clears statusbar
	int GetcurrPlayerNumber();					    // We added this function once here because it is used many times by other classes

	void SaveAll(ofstream& OutFile,int t);
	void ResetGrid();
	void deleteObject(CellPosition pos);

	bool IsOverlapping(GameObject* newObj);

	~Grid(); // A destructor for any needed deallcations
};

