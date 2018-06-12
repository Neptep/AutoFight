#include "Warsystem.h"
Warsystem::Warsystem(Soldier **pa, Soldier **pb)
{
	_GroupA = pa;
	_GroupB = pb;
	round = 0;
}
int Warsystem::GAMEOVER()
{
	if(_GroupA[0]-> alive==0&&_GroupA[1]-> alive==0&&_GroupA[2]-> alive==0)
	 	return 1;
 	else if(_GroupB[0]->alive==0&&_GroupB[1]->alive==0&&_GroupB[2]->alive==0)
 		return 2;
 	else return 0;	
 }

int Warsystem::getdeathnum(Soldier **GROUP)
{
	int sum=0,i;
	for(i=0;i<3;i++)
	{
		if(GROUP[i]->alive==0)
			sum++;
	}
	
	return sum;
}

void Warsystem::startWar(Soldier **_pGroupA, Soldier **_pGroupB)
{
	int k,i,s,n=0;
	srand(time(NULL));

	if(_pGroupA[0]-> alive==1)
	{
starta1:
		
		if(_pGroupA[0]->HP<=_pGroupA[0]->maxHP*0.5 && _pGroupA[0]->drugNum>0) 
			_pGroupA[0]-> takingDrug();
		
		else if((_pGroupA[0]->HP<=_pGroupA[0]->maxHP*0.5 && _pGroupA[0]->drugNum==0 )|| _pGroupA[0]->SP<10) 
			_pGroupA[0]->rest(); 
			
		else if(_pGroupA[0]->SP>=10) 
		{
			s=rand()%3;
			if(_pGroupB[s]->alive==0&&getdeathnum(_pGroupB)<3)
				goto starta1;
			_pGroupA[0]->attack(**(_pGroupB+s));
			if(_pGroupB[s]->alive==1)
			{
			
			}
		}
	}

	if(_pGroupA[1]->alive==1)
	{
starta2:	
		s=rand()%10+1;
		if(_pGroupA[1]->HP<=_pGroupA[1]->maxHP*0.5 && _pGroupA[1]->drugNum>0)
			_pGroupA[1]->takingDrug();
		
		else if((_pGroupA[1]->HP<=_pGroupA[1]->maxHP*0.5 && _pGroupA[1]->drugNum==0 )|| _pGroupA[1]->SP<10) 
			_pGroupA[1]->rest();  
			
		else if(s>4&&_pGroupA[1]->MP>=30)
		{
			for(i=0;i<3;i++)
			{
				if(_pGroupB[i]->alive==0)
					continue;	
				_pGroupA[1]->makeDecision('2',**(_pGroupB+i));
			}	
		}
		else if((s<=4&&(_pGroupA[1]->SP<30||_pGroupA[1]->MP>=30))||(s>3&&_pGroupA[1]->MP<30))
		{
			s=rand()%3;
			if(_pGroupB[s]->alive==0&&getdeathnum(_pGroupB)<3)
				goto starta2;
			_pGroupA[1]->makeDecision('1',**(_pGroupB+s));
			if(_pGroupB[s]->alive==1)
			{
			
			}	
		}			
	}
	
	if(_pGroupA[2]->alive==1)
	{
starta3:
		s=rand()%10+1;	
		
	  if(_pGroupA[2]->HP<=_pGroupA[2]->maxHP*0.5 && _pGroupA[2]->drugNum>0) 
			_pGroupA[2]->takingDrug();
		
		else if((_pGroupA[2]->HP<=_pGroupA[2]->maxHP*0.5 && _pGroupA[2]->drugNum==0 )|| _pGroupA[2]->SP<10) 
			_pGroupA[2]->rest();  
			
		else if(s<=3&&_pGroupA[2]->SP>20||s>3&&_pGroupA[2]->MP>30) 
		{	
			s=rand()%3;
			if(_pGroupB[s]->alive==0&&getdeathnum(_pGroupB)<3)
				goto starta3;
			_pGroupA[2]->makeDecision('3',**(_pGroupB+s));
		}
		
		else if(((s>3&&s<=6)&&_pGroupA[2]->SP>30)||(s<=3&&_pGroupA[2]->MP>30)) 
		{
			s=rand()%3;
			if(_pGroupB[s]->alive==0&&getdeathnum(_pGroupB)<3)
				goto starta3;
			_pGroupA[2]->attack(**(_pGroupB+s));
			if(_pGroupB[s]->alive==1)
			{
			}
		} 
		
		else if((s>6&&(_pGroupA[2]->MP>20||_pGroupA[2]->SP>10))) //魔法攻击 
		{
			for(i=0;i<3;i++)
			{
				if(_pGroupB[i]->alive==0)
					continue;	
				_pGroupA[2]->makeDecision(2,**(_pGroupB+i));
			}	
		}			
	}	
}

void Warsystem::startRound()
{
	
	int k,i,s,n=0;
	char option;
	srand(time(NULL));
	
	cout<<"队伍A的信息："<<endl;
	cout<<setw(8)<<"Name"<<setw(8)<<"level"<<setw(8)<<"drugNum"<<setw(8)<<"HP"<<setw(6)<<"SP"<<setw(6)<<"MP"<<setw(6)<<"NP"<<endl;
	if (_GroupA[0]-> HP > 0)
		_GroupA[0]->show();
	else
	{ 
		cout <<"         "<< _GroupA[0]->Name <<"        "<<"死亡"<<endl;
	}	
	
	if (_GroupA[1]-> HP > 0)
		_GroupA[1]->show();
	else
	{
		cout <<"         "<< _GroupA[1]->Name <<"          "<<"死亡"<<endl ;
	}	
		if (_GroupA[2]-> HP > 0)
		_GroupA[2]->show();
	else
	{
		cout <<"         "<< _GroupA[2]->Name <<"         "<<"死亡"<<endl;
		}	
	cout<<"队伍B的信息："<<endl;
	cout<<setw(8)<<"Name"<<setw(8)<<"level"<<setw(8)<<"drugNum"<<setw(8)<<"HP"<<setw(6)<<"SP"<<setw(6)<<"MP"<<setw(6)<<"NP"<<endl;
	if (_GroupB[0]-> HP > 0)
		_GroupB[0]->show();
	else 
	{
		cout <<"         "<< _GroupB[0]->Name <<"         "<<"死亡"<<endl;
			}	
	if (_GroupB[1]-> HP > 0)
		_GroupB[1]->show();
	else 
	{
		cout <<"         "<< _GroupB[1]->Name <<"         "<<"死亡"<<endl;
	}		
	if (_GroupB[2]-> HP > 0)
		_GroupB[2]->show();
	else 
	{
		cout <<"         "<< _GroupB[2]->Name <<"         "<<"死亡"<<endl;
		}	
	round++;
	cout<<"第"<<round<<"回合开始"<<endl;
		s=rand()%2;
	if(s==0)	
	{
		cout<<"<A队先发起进攻>"<<endl;	
		startWar(_GroupA,_GroupB);
		cout<<"--------------------------------------------------------------"<<endl;
		startWar(_GroupB,_GroupA);
		EndRound();
	} 
	else if(s==1)
	{
		cout<<"<B队先发起进攻>"<<endl;
		startWar(_GroupB,_GroupA);
		cout<<"-------------------------------------------------------------"<<endl;
		startWar(_GroupA,_GroupB);
		EndRound();
	}
}

void Warsystem::EndRound()
{
	cout<<"第"<<round<<"回合结束"<<endl;
		cout<<setw(40)<<"****4秒后进行下一回合****"<<endl;
	_sleep(4*1000);
	if(GAMEOVER()!=0)
	{	
		if(GAMEOVER()==2)
		{
			cout<<"A军团获得了胜利!"<<endl;
					}
		else
		{
			cout<<"B军团获得了胜利"<<endl;
				}
		cout<<"-------------------战斗结束-----------------"<<endl;
		cout<<setw(40)<<"****4秒后进行下一回合****"<<endl;
		_sleep(4*1000);
		exit(1);
	} 
	
}


