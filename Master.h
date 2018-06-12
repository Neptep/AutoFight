#ifndef MASTER_H
#define MASTER_H
#include "Soldier.h"
#include "Wizard.h"
class Master: public Wizard
{
private:
	double maxNP,NP;
public:
	Master(string n);
	~Master(){};
	void master_attack(Soldier& E);			//¾øÉ±¹¥»÷
	void makeDecision(int c, Soldier& p);
	void show();
	void rest();
	void levelup();
};

#endif
