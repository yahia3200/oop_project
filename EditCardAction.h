#pragma once
#include "Action.h"
class EditCardAction :
	public Action
{
	int CardNumber;
	CellPosition cardPosition;
	Card* Cardptr;
public :
	EditCardAction(ApplicationManager* pApp); //Constructor

	virtual void ReadActionParameters();
	virtual void Execute();
	virtual ~EditCardAction();
};

