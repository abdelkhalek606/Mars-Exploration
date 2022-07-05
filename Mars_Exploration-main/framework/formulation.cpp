#include "formulation.h"

int formulation::getmissonid()
{
	return missonid;
}
void formulation::setmissonid(int x) {
	missonid = x;
}
void formulation::execute(queue <misson*>& PM, priqueue <misson*>&EM) {
	misson* m;
	if (missont == polar)
	{
		//for sit misson data
		m = new misson;
		m->setdistance(distance);
		m->setformulationday(eventday);
		m->setsignficant(significant);
		m->setmissontype(polar);
		m->setid(missonid);
		m->setmissonduration(missonduration);
		PM.enqueue(m);
		
	}
	else {
		//for sit misson data
		m = new misson;
		m->setdistance(distance);
		m->setformulationday(eventday);
		m->setsignficant((significant + missonduration + distance - eventday));
		// the significant of emergancy misson is high if it take long time and formalted fist
		m->setmissontype(emergency);
		m->setid(missonid);
		m->setmissonduration(missonduration);

		EM.enqueue(m, (significant+missonduration+distance- eventday));
	}
 }

int formulation::geteventday() {
	return eventday;
 }
void formulation::seteventday(int x) {
	eventday = x;
 }
int formulation::getsignficant()
{
	return significant;
}
void formulation::setsignficant(int x)
{
	significant = x;
}
int formulation::getdistance()
{
	return distance;
}
void formulation::setdistance(int c)
{
	distance = c;

}
int formulation::getmissonduration()
{
	return missonduration;
}
void formulation::setmissonduration(int x)
{
	missonduration = x;
}
void formulation::setmissontype(missontype m)
{
	missont = m;
}
missontype formulation::gettmissontype()
{
	return missont;
}
eventtype formulation::geteventtype()
{
	return type;
}
void formulation::seteventtype(eventtype e)
{
	type = e;
}