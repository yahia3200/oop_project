#pragma once
#include "Action.h"
class Poison:
	public Action
{
private:
	Player* CurrPlayer;
	int CurrPlayerNum;
	bool Used[MaxPlayerCount];
public:
	Poison(ApplicationManager* pApp);  // Constructor

	// ============ Virtual Functions ============

	virtual void ReadActionParameters(); // Reads parameters required for action to execute 
											 // (code depends on action type so virtual)

	virtual void Execute();  // Executes action (code depends on action type so virtual)
	void IsUsed(int PlayerIndex);
	void restart();  //restart Used array
	virtual ~Poison();  // Virtual Destructor
};

