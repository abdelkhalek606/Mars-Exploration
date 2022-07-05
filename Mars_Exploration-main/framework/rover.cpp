#include"rover.h"
rover::rover() {
	finshingday = -5;
	inexdayes = 0;
	checktimes = 0;
	checkupdays = 0;
}

int rover::getchecktimes(int x) {
	if (checktimes == 0)
		return false;
	return checktimes%x==0;
}
void rover::setchecktimes() {
	
	checktimes++;
}
 void rover::setfinshingday(int x) {
	finshingday = x;
}

int rover::getfinshingday() {

	if(finshingday>0)
	return finshingday;
	return 0;
}

int rover::getid()
{
	return id;
}
void rover::asign(misson* m2, int t)
{
	m = m2;
	int x = 2 * (m->getdistance() / getspeed()) / 25;
	m2->setwationgday(t, x);

}
misson* rover::getmission()
{
	return m;

}
 void rover::setid(int x) {
	id = x;
}
void rover::setspeed(int x)
{
	speed = x;
}
int rover::getspeed() {
	return speed;
}
int rover::getcheckupdayes() {
	return checkupdays;

}
bool rover::propfailer()
{
	
	int f = rand() % 101;
	if (f < 3)
		return true;
	return false;
}
 void rover::setcheckupdayes(int c) {
	checkupdays = c;
}
rovertype rover::gettype() {
	return type;
}
 void rover::settype(rovertype r) {
	type = r;
}

 int rover::getinexdayes() {
	return inexdayes;

}
 void rover::setinexdayes(int x, int c) {
	 if (x < 0)
		 inexdayes = 0;
	inexdayes = inexdayes + c - x;
}