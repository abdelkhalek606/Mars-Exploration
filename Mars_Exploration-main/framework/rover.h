#pragma once
#include"definitions.h"
#include"misson.h"
#include"random"

class rover
{
	int checktimes;
	misson* m;
	int finshingday;
	int id;
	int speed;
	int checkupdays;
	rovertype type;
	int waittingdays;
	int inexdayes;
	public:
		rover();
	
		int getchecktimes(int x);
		void setchecktimes();
	 void setfinshingday(int x);
	
	 int getfinshingday();

	 int getid();
	 void asign(misson* m2, int t);
	
	 misson* getmission();

	 void setid(int x);
	 void setspeed(int x);
	
	 int getspeed();
	 int getcheckupdayes();
	 bool propfailer();
	
	 void setcheckupdayes(int c);
	 rovertype gettype();
	 void settype(rovertype r);

	  int getinexdayes();
	 void setinexdayes(int x, int c);
};

