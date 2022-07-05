#pragma once
#include"definitions.h"
#include"queue.h"
#include"priqueue.h"
#include"misson.h"
class event
{
public:
	virtual int getmissonid() {
		return 0;
	}

	virtual void setmissonid(int x) {

	}
	virtual void execute(queue <misson*>& PM,  priqueue <misson*>&EM)=0;

	virtual int geteventday()=0;
	virtual void seteventday(int x)=0;
	virtual int getsignficant(){
		return 0;

	}
	virtual void setsignficant(int x) {
		

	}
	virtual int getdistance() {
		return 0;

	}
	virtual void setdistance(int c) {
		

	}
	virtual int getmissonduration() = 0;
	virtual void setmissonduration(int x) {

	}
	virtual void setmissontype(missontype m){
	
	}
	virtual missontype gettmissontype() {
		return emergency;
	}
	virtual eventtype geteventtype() {
		return Formulation;
	}
	virtual void seteventtype(eventtype e) {
		
	}
};

