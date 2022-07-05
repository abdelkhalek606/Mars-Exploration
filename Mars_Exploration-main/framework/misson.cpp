#include"misson.h"
int misson::getcompletedday() {

	return watingday + formulationday + missonduration + triptime;
}
int  misson::getid() {
	return id;
}
int  misson::getwationgday() {
	return watingday;
}
void  misson::setid(int x) {
	id = x;
}
int  misson::getformulationday() {
	return formulationday;
}
int misson::getexcday() {
	return triptime + missonduration;
}
void  misson::setformulationday(int x) {
	formulationday = x;
}
int  misson::getsignficant() {
	return signficant;
}
void  misson::setsignficant(int x) {
	signficant = x;
}
void  misson::setwationgday(int t, int x) {
	watingday = t - getformulationday();
	triptime = x;
}

int  misson::getdistance() {
	return distance;
}
void  misson::setdistance(int c) {
	distance = c;
}
int  misson::getmissonduration() {
	return missonduration;
}
void  misson::setmissonduration(int x) {
	missonduration = x;
}
void  misson::setmissontype(missontype m) {

	type = m;
}
missontype  misson::gettmissontype() {
	return type;
}