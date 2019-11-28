#pragma once
#include "GameObject.h"
class Snake :
	public GameObject
{
	CellPosition endCellPos;
	static int SnakeCount;
public :
	Snake(const CellPosition& startCellPos, const CellPosition& endCellPos); // A constructor for initialization
	virtual void Draw(Output* pOut) const; // Draws a ladder from its start cell to its end cell

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applys the effect of the ladder by moving player to ladder's end cell

	CellPosition GetEndPosition() const;
	static int Count();
	virtual int GetCount()const;
	virtual ~Snake();
};

