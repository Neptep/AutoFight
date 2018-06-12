#include "Soldier.h"
#include <iomanip> 
Soldier::Soldier(string n)
{   Name=n;
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
void Soldier::levelup()
{
	cout<<this->Name<<"�����ˣ�"<<endl; 
	Exp=Exp%20;
	level++;
	HP=((double)HP)/((double)maxHP)*(maxHP+15);
	SP=((double)SP)/((double)maxSP)*(maxSP+15);
	maxSP+=15;
	maxHP+=15;
	Damege+=20;

}
void Soldier::show()
{	
cout<<setw(8)<<Name<<setw(8)<<level<<setw(8)<<drugNum<<setw(8)<<HP<<setw(6)<<SP<<endl;}
 
void Soldier::attack(Soldier& E)
{
	double d,t;
		t=rand()%100+1;
		if(t>=25)
		{
			d=Damege;
			cout<<this->Name<<" �� "<<E.Name<<" ����������"<<E.Name<<" ������ "<<d<<" ��HP"<<endl;
					}	
		else if(t<=20&&t>10)
		{
			d=Damege*1.5;
			cout<<this->Name<<" �����ˣ�   "<<E.Name<<" ������ "<<d<<" ��HP"<<endl;
					}	
		else if(t<=5)
		{
			cout<<this->Name<<"������"<<E.Name<<"�������м�ס��"<<endl;
			cout<< E.Name<<"�˺�������5"<<endl;
			this->Damege-=5;
			d=0; 
		}
		
		else
		{
			cout<<Name<<"û�ж���"<<endl;
			d=0;
		} 	
		
		E.HP-=d;
		SP-=10;
		Exp+=5;
		
		if(E.HP<=0)
		{
			cout<<Name<<"������"<<E.Name<<endl;
			E.HP=0;
			drugNum+=E.drugNum;
			E.drugNum=0;
			E.alive=0;
		}
		if(Exp>=20)
			levelup();
		
} 

void Soldier::rest()
{
	cout<<this->Name<<"��Ϣ��һ��"<<endl; 
		if(HP<=maxHP*0.5)
		HP += maxHP*0.5;
	else HP = maxHP;
	
	if(SP<=maxSP*0.5)
		SP += maxSP*0.5;
	else SP = maxSP;	
}

void Soldier::takingDrug()
{
	if(drugNum>0)
	{
		cout<<this->Name<<"����һƿҩ"<<endl;
		if(HP<=maxHP*0.8)
		{
			if(HP += 80>=maxHP)
				HP=maxHP;
			else 
				HP += 80;	
		}	
		else HP = maxHP;
		drugNum--;	
	}
	else 
	{
		cout<<"ҩ�Ѿ�û��"<<endl;
	}	
}


void Soldier::makeDecision(int option, Soldier& E)
{
	switch(option)
	{
		case 1: attack(E);break;
		case 2: rest();break;
		case 3: takingDrug();break;
		case 4: exit(1);break;
		default : break;
	}
}
