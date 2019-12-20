#pragma once
#include "Action.h"

//Action: Saving The Information Of The Designed Grid To A File

class SaveAction : public Action
{
	string fileName;   // File Name

public: 
	SaveAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	~SaveAction();

};

