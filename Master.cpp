#include "Soldier.h"
#include "Wizard.h"
#include "Master.h"
#include <iomanip> 
Master::Master(string n)
{
    Name=n;
    NP=100;
    maxNP=100;
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

void Master::master_attack(Soldier& E)
{
	double n;
	if(SP>=30&&NP>=50)
	    {
		n=Damege;
		E.HP-=n;
		SP-=30;
		Exp+=12;
		NP-=50;
		cout<<this->Name<<" 对 "<<E.Name<<" 使用了大师攻击，"<<E.Name<<" 减少了 "<<n<<" 点HP"<<endl;
	    }
				if(E.HP<=0)
		{
			cout<<Name<<"击败了"<<E.Name<<endl;
						E.HP=0;
			drugNum+=E.drugNum;
			E.drugNum=0;
			E.alive=0;
		}
		if(Exp>=20+5*level)
			levelup();
	
}


void Master::makeDecision(int option, Soldier& p)
{
	switch(option)
	{
		case 1: attack(p);break;
		case 2: wizard_attack(p);break;
		case 3: master_attack(p);break;
		case 4: rest();break;
		case 5: takingDrug();break;
		case 6: exit(1);break;
		default : break;
	}
}

void Master::show()
{
cout<<setw(8)<<Name<<setw(8)<<level<<setw(8)<<drugNum<<setw(8)<<HP<<setw(6)<<SP<<setw(6)<<MP<<setw(6)<<NP<<endl;
}

void Master::rest()
{
	cout<<this->Name<<"休息了一下"<<endl; 
	if(HP<=maxHP*0.7)
		HP += maxHP*0.3;
	else HP = maxHP;
	
	if(SP<=maxSP*0.7)
		SP += maxSP*0.3;
	else SP = maxSP;
	
	if(MP<=maxMP-40)
		MP += 40;
	else MP = maxMP;
	
	if(NP<=maxNP*0.3)
		NP += maxNP*0.3;
	else NP = maxNP;	
}

void Master::levelup()
{
	cout<<this->Name<<"升级了！"<<endl;
	Exp=Exp%20;
	level++;
	HP=((double)HP)/((double)maxHP)*(maxHP+15);
	SP=((double)SP)/((double)maxSP)*(maxSP+10);
	MP=((double)MP)/((double)maxMP)*(maxMP+10);
	NP=((double)NP)/((double)maxNP)*(maxNP+15);
	maxSP+=10;
	maxHP+=15;
	maxNP+=15;
	maxMP+=10;
	Damege+=15;
}
