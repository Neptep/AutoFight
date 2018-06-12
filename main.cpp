#include <iostream>
#include <ctime>
#include <string>
#include "Soldier.h"
#include "Wizard.h"
#include "Master.h"
#include "Warsystem.h"
int main(int argc, char *argv[])
{
	Soldier *groupa[3],*groupb[3];
	Soldier sa("SoldierA"),sb("SoldierB");
	Wizard wa("WizardA"),wb("WizardB");
	Master ma("MasterA"),mb("MasterB");
	groupa[0] = &sa;
	groupa[1] = &wa;
	groupa[2] = &ma;
	groupb[0] = &sb;
	groupb[1] = &wb;
	groupb[2] = &mb;
	_sleep(1000);

	Warsystem pk(groupa,groupb);
	while(1)
	pk.startRound();
	return 0;
}
