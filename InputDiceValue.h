#pragma once
#include "Action.h"
#include "Player.h"
#include "Grid.h"
#include <time.h> // used to in srand to generate random numbers with different seed

class InputDiceValue : public Action
{
private:
	int diceNumber;
public:
	InputDiceValue(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~InputDiceValue();

};

