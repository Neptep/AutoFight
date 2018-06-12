#ifndef SOLDIER_H
#define SOLDIER_H
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;
class Soldier
{
	
    protected:  
	          double HP,SP,level,drugNum,maxHP,maxSP,alive,Damege,MP;
	          int Exp; 
              string Name;
	public:
		Soldier(string n="Soldier");
		~ Soldier(){};
		void takingDrug();  				 
		virtual void rest();						 
		virtual void attack(Soldier& E);				 
	    virtual void show();					 
	    virtual void makeDecision(int c, Soldier& E);   					
	    virtual void levelup(); 												 	
	friend class Warsystem;
	friend class Wizard;
	friend class Master;
};
#endif
