#ifndef WIZARD_H 
#define WIZARD_H 
#include "Soldier.h"
class Wizard: public Soldier
{
protected:
    double maxMP,MP;
public:
	Wizard(string n="Wizard");
	~Wizard(){};
	void wizard_attack(Soldier& E); 		//·¨Êõ¹¥»÷ 
	void makeDecision(int c, Soldier& E);
    void show();
    void rest();  
	void levelup(); 
	

};

#endif
