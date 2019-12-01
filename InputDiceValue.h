#pragma once
#include "Action.h"


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

