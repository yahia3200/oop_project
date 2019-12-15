#pragma once
#include "Action.h"
class Fire :
	public Action
{
private:
	Player* CurrPlayer;
	int CurrPlayerNum;
	bool Used[MaxPlayerCount];
public:
	Fire(ApplicationManager* pApp);  // Constructor

	// ============ Virtual Functions ============

	virtual void ReadActionParameters(); // Reads parameters required for action to execute 
											 // (code depends on action type so virtual)

	virtual void Execute();  // Executes action (code depends on action type so virtual)
	void IsUsed(int PlayerIndex);
	virtual ~Fire();  // Virtual Destructor
};

