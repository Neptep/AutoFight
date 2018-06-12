#include "Wizard.h"
#include <iomanip>
Wizard::Wizard(string n)
{   Name=n;
    maxMP=100;
    MP=100; 
	HP=100;
	maxHP=100;
	SP=100; 
	maxSP=100;
    drugNum=5;
    Exp=0;
    Damege=20;
	Exp = 0;
	level = 1;
	drugNum = 5;
	alive=1;
}

void Wizard::show()
{
cout<<setw(8)<<Name<<setw(8)<<level<<setw(8)<<drugNum<<setw(8)<<HP<<setw(6)<<SP<<setw(6)<<MP<<endl;
}

void Wizard::makeDecision(int option,Soldier& p)
{
	switch(option)
	{
		case 1: attack(p);break;
		case 2: wizard_attack(p);break;
		case 3: rest();break;
		case 4: takingDrug();break;
		case 5: exit(1);break;
		default : break;
	}
}

void Wizard::wizard_attack(Soldier& E)
{
	double d;

		d=Damege*0.8;
		E.HP-=d;
		SP-=10;
		Exp+=3;
		MP-=10;
		if(Exp>=20)
			levelup();
		cout<<this->Name<<" 对 "<<E.Name<<" 使用了膜法攻击，"<<E.Name<<" 减少了 "<<d<<" 点HP"<<endl;
				if(E.HP<=0)
		{
			cout<<Name<<"击败了"<<E.Name<<endl;
			E.HP=0;
			
			drugNum+=E.drugNum;
			E.drugNum=0;
			E.alive=0;
		}
}
	
	

void Wizard::rest() 
{
	
  cout<<this->Name<<"休息了一下"<<endl; 
	if(HP<=maxHP*0.5)
		HP += maxHP*0.5;
	else HP = maxHP;
	
	if(SP<=maxSP*0.5)
		SP += maxSP*0.5;
	else SP = maxSP;
	
	if(MP<=maxMP*0.5)
		MP += maxMP*0.5;
	else MP = maxMP;	
}

void Wizard::levelup()
{
	cout<<this->Name<<"升级了！"<<endl; 
	Exp=Exp%20;
	level++;
	HP=((double)HP)/((double)maxHP)*(maxHP+12);
	SP=((double)SP)/((double)maxSP)*(maxSP+10);
	MP=((double)MP)/((double)maxMP)*(maxMP+15);
	maxSP+=10;
	maxHP+=12;
	maxMP+=15;
	Damege+=10;
}
