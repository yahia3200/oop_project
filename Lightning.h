#pragma once
#include "Action.h"
class Lightning :
	public Action
{
private : 
	Player* CurrPlayer;
	int CurrPlayerNum;
	bool Used[MaxPlayerCount];
public :
	Lightning(ApplicationManager* pApp);  // Constructor

	// ============ Virtual Functions ============

	virtual void ReadActionParameters() ; // Reads parameters required for action to execute 
											 // (code depends on action type so virtual)

	virtual void Execute() ;  // Executes action (code depends on action type so virtual)
	void IsUsed(int PlayerIndex);
	virtual ~Lightning();  // Virtual Destructor
};

