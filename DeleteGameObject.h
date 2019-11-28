#pragma once
#include "Action.h"
class DeleteGameObject :
	public Action
{
	CellPosition cellPos; // 2- cell position of the card

	// Note: These parameters should be read in ReadActionParameters()

public:
	DeleteGameObject(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads AddCardAction action parameters (cardNumber, cardPosition)

	virtual void Execute(); // Creates a new Card Object of the specific Card Number
							// and Reads the Parameters of This Card Number (if any)
							// then Sets this Card Object to GameObject Pointer of its Cell

	virtual ~DeleteGameObject(); // A Virtual Destructor
};

