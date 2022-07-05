#pragma once
#include"definitions.h"
class misson
{
	int watingday;
	int id;
	int formulationday;
	int signficant;
	int distance;
	int missonduration;
	int triptime;
	missontype type;

public:
	int getexcday();
	int getcompletedday();
	 int getid();
	 int getwationgday();
	 void setid(int x);
	 int getformulationday();
	 void setformulationday(int x);
	 int getsignficant();
	 void setsignficant(int x);
	 void setwationgday(int t, int x);

	 int getdistance();
 void setdistance(int c);
 int getmissonduration();
	 void setmissonduration(int x);
	 void setmissontype(missontype m);
	 missontype gettmissontype();
};

