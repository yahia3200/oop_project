#pragma once

#include "GameObject.h"

class Ladder :	public GameObject // inherited from GameObject
{
	// Note: the "position" data member inherited from the GameObject class is used as the ladder's "Start Cell Position"

	CellPosition endCellPos; // here is the ladder's End Cell Position
	static int LadderCounter;
public:

	Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos); // A constructor for initialization

	virtual void Draw(Output* pOut) const; // Draws a ladder from its start cell to its end cell

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applys the effect of the ladder by moving player to ladder's end cell

	CellPosition GetEndPosition() const; // A getter for the endCellPos data member
<<<<<<< HEAD

	virtual void Save(ofstream& OutFile, int t);

=======
	static int Count();
	virtual int GetCount()const;
>>>>>>> 8e6901293e530ea9a64910aae53213d907d7cdcd
	virtual ~Ladder(); // Virtual destructor
};

