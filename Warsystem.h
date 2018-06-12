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
	void startWar(Soldier **_pGroupA, Soldier **_pGroupB);	//��ʼս�� 
	void startRound();									//��ʼ�غ� 
	void EndRound();									//�����غ� 
	Warsystem(Soldier **pa, Soldier **pb);
	~Warsystem(){};
	int GAMEOVER();
	int getdeathnum(Soldier **GROUP)	;									//������Ϸ 
	
private:
	Soldier **_GroupA;
	Soldier **_GroupB;
	int round;		
};
#endif
