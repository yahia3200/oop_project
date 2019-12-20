#pragma once
#include "Action.h"

// Action: Open A Saved Grid From A File And Re-Drawing It

class LoadAction : public Action
{
	string fileName; // Name Of The File To Read From It 

public:
	LoadAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};

