#pragma once
#include "Action.h"

class SaveAction : public Action
{
	string fileName;
public: 
	SaveAction(ApplicationManager* pApp);
	~SaveAction();
	virtual void ReadActionParameters();
	virtual void Execute();
};

