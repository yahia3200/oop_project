#include "Grid.h"
#include "Cell.h"
#include "GameObject.h"
#include "Ladder.h"
#include "Card.h"
#include "Player.h"
#include "Lightning.h"
#include "Ice.h"
#include "Poison.h"
#include "Fire.h"



Grid::Grid(Input * pIn, Output * pOut) : pIn(pIn), pOut(pOut) // Initializing pIn, pOut
{
	// Allocate the Cell Objects of the CellList
	for (int i = NumVerticalCells-1; i >= 0 ; i--) // to allocate cells from bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // to allocate cells from left to right
		{
			CellList[i][j] = new Cell(i, j);
		}
	}

	// Allocate thePlayer Objects of the PlayerList
	for (int i = 0; i < MaxPlayerCount; i++) 
	{
		PlayerList[i] = new Player(CellList[NumVerticalCells-1][0], i); // first cell
		PlayerList[i]->Draw(pOut); // initially draw players in the first cell
	}

	// Initialize currPlayerNumber with 0 (first player)
	currPlayerNumber = 0; // start with the first player

	// Initialize Clipboard with NULL
	Clipboard = NULL;

	// Initialize endGame with false
	endGame = false;
	
	// Initialize cards from 10 to 14 Property with false
	card10owner = false;	
	card11owner = false;
	card12owner = false;     
	card13owner = false;     
	card14owner = false;

}


// ========= Adding or Removing GameObjects to Cells =========


bool Grid::AddObjectToCell(GameObject * pNewObject)  // think if any validation is needed
{
	// Get the cell position of pNewObject
	CellPosition pos = pNewObject->GetPosition();
	if (pos.IsValidCell()) // Check if valid position
	{
		// Get the previous GameObject of the Cell
		GameObject * pPrevObject = CellList[pos.VCell()][pos.HCell()]->GetGameObject();
		if( pPrevObject)  // the cell already contains a game object
			return false; // do NOT add and return false

		// Set the game object of the Cell with the new game object
		CellList[pos.VCell()][pos.HCell()]->SetGameObject(pNewObject);
		return true; // indicating that addition is done
	}
	return false; // if not a valid position
}

void Grid::RemoveObjectFromCell(const CellPosition & pos)
{
	if (pos.IsValidCell()) // Check if valid position
	{
		// Note:: you can deallocate the object here before setting the pointer to null if it is needed
		//delete CellList[pos.VCell()][pos.HCell()]->GetGameObject();
		CellList[pos.VCell()][pos.HCell()]->SetGameObject(NULL);
	}
	
}
int Grid::GetcurrPlayerNumber()
{
	return currPlayerNumber;
}


void Grid::UpdatePlayerCell(Player * player, const CellPosition & newPosition)
{
	// Clear the player's circle from the old cell position
	player->ClearDrawing(pOut);

	// Set the player's CELL with the new position
	Cell * newCell = CellList[newPosition.VCell()][newPosition.HCell()];
	player->SetCell(newCell);	

	// Draw the player's circle on the new cell position
	player->Draw(pOut);
}

void Grid::SetLighting(Lightning* L)
{
	Light = L;
}

void Grid::SetIce(Ice* i)
{
	ice = i;
}

void Grid::SetPoison(Poison* p)
{
	poison = p;
}

void Grid::SetFire(Fire* f)
{
	fire = f;
}

Ice* Grid::GetIce() const
{
	return ice;
}

Lightning* Grid::GetLight() const
{
	return Light;
}

Poison* Grid::GetPoison() const
{
	return poison;
}

Fire* Grid::GetFire() const
{
	return fire;
}


// ========= Setters and Getters Functions =========


Input * Grid::GetInput() const
{
	return pIn;
}

Output * Grid::GetOutput() const
{
	return pOut;
}

void Grid::SetClipboard(Card * pCard) // to be used in copy/cut
{
	// you may update slightly in implementation if you want (but without breaking responsibilities)
	Clipboard = pCard;
}

Card * Grid::GetClipboard() const // to be used in paste
{
	return Clipboard;
}

void Grid::SetEndGame(bool endGame)
{
	this->endGame = endGame;
}

bool Grid::GetEndGame() const
{
	return endGame;
}

void Grid::setcard10owner(bool x)
{
	card10owner = x;
}

bool Grid::getcard10owner() const
{
	return card10owner;
}

void Grid::setcard11owner(bool x)
{
	card11owner = x;
}

bool Grid::getcard11owner() const
{
	return card11owner;
}

void Grid::setcard12owner(bool x)
{
	card12owner = x;
}

bool Grid::getcard12owner() const
{
	return card12owner;
}

void Grid::setcard13owner(bool x)
{
	card13owner = x;
}

bool Grid::getcard13owner() const
{
	return card13owner;
}

void Grid::setcard14owner(bool x)
{
	card14owner = x;
}

bool Grid::getcard14owner() const
{
	return card14owner;
}

void Grid::AdvanceCurrentPlayer()
{
	currPlayerNumber = (currPlayerNumber + 1) % MaxPlayerCount; // this generates value from 0 to MaxPlayerCount - 1
}







// ========= Other Getters =========




Card* Grid::Getclickedcard(CellPosition& position)
{
	//getting vcell and hcell of the position
	int Vcell = position.VCell();
	int Hcell = position.HCell();
	
    //retun the card in the cell clicked
	return CellList[Vcell][Hcell]->HasCard();
}

Player * Grid::GetCurrentPlayer() const
{
	return PlayerList[currPlayerNumber];
}

Ladder * Grid::GetNextLadder(const CellPosition & position)
{
	
	int startH = position.HCell(); // represents the start hCell in the current row to search for the ladder in
	for (int i = position.VCell(); i >= 0; i--) // searching from position.vCell and ABOVE
	{
		for (int j = startH; j < NumHorizontalCells; j++) // searching from startH and RIGHT
		{


			///TODO: Check if CellList[i][j] has a ladder, if yes return it (Done)
			if (CellList[i][j]->HasLadder())
				return CellList[i][j]->HasLadder();

		}
		startH = 0; // because in the next above rows, we will search from the first left cell (hCell = 0) to the right
	}
	return NULL; // not found
}

Snake* Grid::GetNextSnake(const CellPosition& position)
{
	int startH = position.HCell(); // represents the start hCell in the current row to search for the ladder in
	for (int i = position.VCell(); i >= 0; i--) // searching from position.vCell and ABOVE
	{
		for (int j = startH; j < NumHorizontalCells; j++) // searching from startH and RIGHT
		{


			///TODO: Check if CellList[i][j] has a ladder, if yes return it
			if (CellList[i][j]->HasSnake())
				return CellList[i][j]->HasSnake();

		}
		startH = 0; // because in the next above rows, we will search from the first left cell (hCell = 0) to the right
	}
	return NULL; // not found
}


// ========= User Interface Functions =========


void Grid::UpdateInterface() const
{
	if (UI.InterfaceMode == MODE_DESIGN)
	{
		// 1- Draw cells with or without cards 
		for (int i = NumVerticalCells-1; i >= 0 ; i--) // bottom up
		{
			for (int j = 0; j < NumHorizontalCells; j++) // left to right
			{
				CellList[i][j]->DrawCellOrCard(pOut);
			}
		}

		// 2- Draw other cell objects (ladders, snakes)
		for (int i = NumVerticalCells-1; i >= 0 ; i--) // bottom up
		{
			for (int j = 0; j < NumHorizontalCells; j++) // left to right
			{
				CellList[i][j]->DrawLadderOrSnake(pOut);
			}
		}

		// 3- Draw players
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			PlayerList[i]->Draw(pOut);
		}
	}
	else // In PLAY Mode
	{
		// 1- Print Player's Info
		string playersInfo = "";
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			PlayerList[i]->AppendPlayerInfo(playersInfo); // passed by reference
			if (i < MaxPlayerCount-1) // except the last player
				playersInfo += ", ";
		}
		playersInfo += " | Curr = " + to_string(currPlayerNumber);

		pOut->PrintPlayersInfo(playersInfo);

		// Note: UpdatePlayerCell() function --> already update drawing players in Play Mode
		//       so we do NOT need draw all players again in UpdateInterface() of the Play mode
		// In addition, cards/snakes/ladders do NOT change positions in Play Mode, so need to draw them here too
	}
}

void Grid::PrintErrorMessage(string msg)
{
	pOut->PrintMessage(msg);
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
}


Grid::~Grid()
{
	delete pIn;
	delete pOut;

	// Deallocate the Cell Objects of the CellList
	for (int i = NumVerticalCells-1; i >= 0 ; i--) 
	{
		for (int j = 0; j < NumHorizontalCells; j++) 
		{
			delete CellList[i][j];
		}
	}

	// Deallocate the Player Objects of the PlayerList
	for (int i = 0; i < MaxPlayerCount; i++) 
	{
		delete PlayerList[i];
	}
}

void Grid::SaveAll(ofstream & OutFile,int t)
{
	for (int i = NumVerticalCells - 1; i >= 0; i--) // bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // left to right
		{

			if (CellList[i][j]->GetGameObject())
			{
				CellList[i][j]->GetGameObject()->Save(OutFile,t);
			}
		}
	}
}

void Grid::ResetGrid()
{
	for (int i = NumVerticalCells - 1; i >= 0; i--) // bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // left to right
		{

			if (CellList[i][j]->GetGameObject())
			{
				delete CellList[i][j]->GetGameObject();
				CellList[i][j]->SetGameObject(NULL);
			}
		}
	}
}

void Grid::deleteObject(CellPosition pos)
{
	
	if (pos.IsValidCell()) // Check if valid position
	{
		delete CellList[pos.VCell()][pos.HCell()]->GetGameObject();		
	}
}

bool Grid::IsOverlapping(GameObject* newObj)
{
	bool IsOverlap = false;
	for (int i = NumVerticalCells - 1; i >= 0; i--) // to allocate cells from bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // to allocate cells from left to right
		{
			if (CellList[i][j]->GetGameObject())
			{
				IsOverlap = CellList[i][j]->GetGameObject()->IsOverlaping(newObj);

				if (IsOverlap)
					break;
			}
		}
	}

	return IsOverlap;

}

