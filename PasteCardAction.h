#pragma once
#pragma once
#include "Action.h"
#include"Cell.h"
#include"Card.h"
#include "Grid.h"
#include"CellPosition.h"
#include "GameObject.h"
class PasteCardAction:public Action
{
		// [Action Parameters]
		Cell* Cardcell;     //cell of the card which need to paste 
		Card* PasteCardinfo;	// paste card 
		CellPosition position; //position of the card
		Grid* pGrid;
		GameObject *Object;
		// Note: These parameters should be read in ReadActionParameters()

	public:
		PasteCardAction(ApplicationManager* pApp); // A Constructor

		virtual void ReadActionParameters(); // Reads CopyCardAction action parameters (cardNumber, cardPosition)

		virtual void Execute(); // Creates a new Card Object of the specific Card Number
								// and Reads the Parameters of This Card Number (if any)
								// then Sets this Card Object to GameObject Pointer of its Cell

		virtual ~PasteCardAction(); // A Virtual Destructor
};

