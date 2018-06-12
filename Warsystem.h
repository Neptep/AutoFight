#ifndef WARSYSTEM_H
#define WARSYSTEM_H
#include <iostream>
#include "Soldier.h"
#include "Wizard.h"
#include "Master.h"
#include <iomanip> 
class Warsystem
{
public:
	void startWar(Soldier **_pGroupA, Soldier **_pGroupB);	//开始战斗 
	void startRound();									//开始回合 
	void EndRound();									//结束回合 
	Warsystem(Soldier **pa, Soldier **pb);
	~Warsystem(){};
	int GAMEOVER();
	int getdeathnum(Soldier **GROUP)	;									//结束游戏 
	
private:
	Soldier **_GroupA;
	Soldier **_GroupB;
	int round;		
};
#endif
