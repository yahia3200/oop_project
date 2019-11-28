#include "Ladder.h"
#include "Player.h"
int Ladder::LadderCounter = 0;
Ladder::Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;
	LadderCounter++;
	///TODO: Do the needed validation
}

void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}

void Ladder::Apply(Grid* pGrid, Player* pPlayer) 
{
	

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==
	
	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click

	// 2- Apply the ladder's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that
	Output* pOut = pGrid->GetOutput(); //Creating Pointer To Output Class Using Grid Class
	Input* pIn = pGrid->GetInput();    //Creating Pointer To Input Class Using Grid Class
	int x, y;  //Int Variables to be used in GetPointClicked
	pOut->PrintMessage("You have reached a ladder. Click to continue ..."); 
	pIn->GetPointClicked(x, y); //Wating For User Click
	pGrid->UpdatePlayerCell(pPlayer, endCellPos); //Applying Ladder Effect 
	
}

CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}

<<<<<<< HEAD
void Ladder::Save(ofstream& OutFile, int t)
{

=======
int Ladder::Count()
{
	return LadderCounter;
}

int Ladder::GetCount() const
{
	return Count();
>>>>>>> 8e6901293e530ea9a64910aae53213d907d7cdcd
}

Ladder::~Ladder()
{
}
