#pragma once
#include "Action.h"
class LoadAction : public Action
{
	string fileName;
public:
	LoadAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

