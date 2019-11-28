
#pragma once
#include "Action.h"

class ToDesignModeAction : public Action
{
public:
	ToDesignModeAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~ToDesignModeAction();
};
