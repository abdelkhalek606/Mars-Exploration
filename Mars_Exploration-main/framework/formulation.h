#pragma once
#include "event.h"
class formulation :
    public event
{
private:
    eventtype type;
    int eventday;
    missontype missont;
    int missonid;
    int missonduration;
    int distance;
	int significant;
public:
	 int getmissonid();
	 void setmissonid(int x);
	 void execute( queue <misson*>&PM, priqueue <misson*>&EM);

	 virtual int geteventday();
	 virtual void seteventday(int x);
	 int getsignficant();
	  void setsignficant(int x);
	int getdistance();
	 void setdistance(int c);
	int getmissonduration();
	 void setmissonduration(int x);
	 void setmissontype(missontype m);
	 missontype gettmissontype();
      eventtype geteventtype();
	  void seteventtype(eventtype e);
};
