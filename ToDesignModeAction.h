
#pragma once
#include "Action.h"

class ToDesignModeAction : public Action
{
	ApplicationManager* pApp;
public:
	ToDesignModeAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual ~ToDesignModeAction();
};
