#pragma once
#pragma once
#include "Action.h"
#include "Grid.h"
#include"CellPosition.h"
#include "GameObject.h"
class PasteCardAction:public Action
{
		// [Action Parameters] 
		CellPosition position; //position of the card
		int cardnum;    //card pasted num 
		// Note: These parameters should be read in ReadActionParameters()

	public:
		PasteCardAction(ApplicationManager* pApp); // A Constructor

		virtual void ReadActionParameters(); // Reads CopyCardAction action parameters (cardNumber, cardPosition)

		virtual void Execute(); // Creates a new Card Object of the specific Card Number
								// and Reads the Parameters of This Card Number (if any)
								// then Sets this Card Object to GameObject Pointer of its Cell

		virtual ~PasteCardAction(); // A Virtual Destructor
};

