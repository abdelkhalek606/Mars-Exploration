#include "UI.h"
#include<windows.h>
using namespace std;
#include"iostream"
MODE UI::getmod() {
	cout << "select mode" << endl;
	cout << "1-interactive mode" << endl;
	cout << "2-step-by-step mode" << endl;
	cout << "3-silent" << endl;
	int x;
	cin >> x;
	if (x==1) {
		return interactivem;
	}
	else if (x == 2) {
		return stepbystepm;

	}
	else {
		return silentm;

	}

}
void UI::trash() {
	char temp = 'x';
	do
	{
		cin.get(temp);
	} while (temp != '\n');
}
void UI::nextstep()
{
	cout << endl;

	cout << "Press Enter to Continue" << endl;
	char temp = 'x';
	do
	{
		cin.get(temp);
	} while (temp != '\n');
}
void UI::interactiveM(int x,priqueue<misson*>EW, queue<misson*>PW, priqueue<rover*>EX, priqueue<rover*>AE, priqueue<rover*>AP, queue<rover*>CE, queue<rover*>CP, queue<misson*>CM) 
{
	system("cls");
	queue<misson*>WE ;
	queue<misson*>WP ;
	queue<rover*>exr ;
	queue<rover*>avlpolr;
	queue<rover*>avlemr;
	queue<rover*>chekEMrover;
	queue<rover*>chekPLrover;
	queue<misson*>combletM;
	rover* r;
	misson* m;
	int e=0;
	int p=0;
	int ex = 0;
	int cp = 0;
	int ce = 0;
	int ap = 0;
	int ae = 0;
	int cm = 0;
	while (EW.dequeue(m)) {

		e++;
		WE.enqueue(m);
	}
	while (PW.dequeue(m)) {
		p++;
		WP.enqueue(m);
	}
	while (EX.dequeue(r)) {
		ex++;
		exr.enqueue(r);
	}
	while (AE.dequeue(r)) {
		ae++;
		avlemr.enqueue(r);
	}
	while (AP.dequeue(r)) {
		ap++;
		avlpolr.enqueue(r);
	}
	while (CE.dequeue(r)) {
		ce++;
		chekEMrover.enqueue(r);
	}
	while (CP.dequeue(r)) {
		cp++;
		chekPLrover.enqueue(r);
	}
	while (CM.dequeue(m)) {
		cm++;
		combletM.enqueue(m);
	}


	cout << "interactive Mode" << endl;
	cout << "current Day: " << x<<endl;
	cout <<e+p<< " Waiting Missons:" ;
	while (WE.peak(m))
	{
		cout <<" "<< "[";
		WE.dequeue(m);
		cout << m->getid();
		while (WE.dequeue(m))
			cout <<","<< m->getid()<<",";
		cout << "]"<<" ";
	}
	while (WP.peak(m))
	{
		cout << "(";
		WP.dequeue(m);
		cout << m->getid();
		while (WP.dequeue(m))
			cout<<"," << m->getid();
		cout << ")";
	}
	cout << endl<<"------------------------------------------------------------------------------------------------"<<endl;

	cout <<ex<< " In-Execution Misson/Rovers";
	
		queue<rover*> er;
		queue<rover*> pr;

		while (exr.dequeue(r))
		{
			if (r->gettype() == emergencyrover)
				er.enqueue(r);
			else
				pr.enqueue(r);
		}
		while (er.peak(r))
		{
			er.dequeue(r);
			cout << " [" << r->getmission()->getid() << "/" << r->getid();
				while(er.dequeue(r))
					cout<<","<< r->getmission()->getid() << "/" << r->getid();
				cout << "] ";
		}
		while (pr.peak(r))
		{
			pr.dequeue(r);
			cout << " (" << r->getmission()->getid() << "/" << r->getid();
			while (pr.dequeue(r))
				cout << "," << r->getmission()->getid() << "/" << r->getid();
			cout << ") ";
		}
		cout << endl<<"------------------------------------------------------------------------------------------------"<<endl;
	
	
	cout<<ae+ap << " Available Rover: ";
	if (avlemr.dequeue(r))
	{
		
		cout << " ["<< r->getid();
		while (avlemr.dequeue(r))
			cout << ","<< r->getid();
		cout << "] ";
		
	}
	if (avlpolr.dequeue(r))
	{

		cout << " (" << r->getid();
		while (avlpolr.dequeue(r))
			cout << "," << r->getid();
		cout << ") ";

	}
	cout << endl<<"------------------------------------------------------------------------------------------------"<<endl;
	cout<<ce+cp << " In-Check Rovers: " ;

	if (chekEMrover.dequeue(r))
	{

		cout << " [" << r->getid();
		while (chekEMrover.dequeue(r))
			cout << "," << r->getid();
		cout << "] ";

	}
	if (chekPLrover.dequeue(r))
	{

		cout << "(" << r->getid();
		while (chekPLrover.dequeue(r))
			cout << "," << r->getid();
		cout << ") ";

	}
	cout << endl<<"------------------------------------------------------------------------------------------------"<<endl;
	cout<<cm << " Completed Missons: " ;
	queue<misson*> em;
	queue<misson*> pm;
	while (combletM.dequeue(m))
	{

		if (m->gettmissontype() == polar)
			pm.enqueue(m);
		else
			em.enqueue(m);
	}
	while (em.peak(m))
	{
		em.dequeue(m);
		cout << " [" << m->getid();
		while (em.dequeue(m))
			cout << "," << m->getid();
		cout << "] ";
	}
	while (pm.peak(m))
	{
		pm.dequeue(m);
		cout << " ("  << m->getid();
		while (pm.dequeue(m))
			cout << "," << m->getid();
		cout << ") ";
	}
	cout << endl;

}
void UI::stepbystep(int x, priqueue<misson*>EW, queue<misson*>PW, priqueue<rover*>EX, priqueue<rover*>AE, priqueue<rover*>AP, queue<rover*>CE, queue<rover*>CP, queue<misson*>CM) {

	system("cls");
	queue<misson*>WE;
	queue<misson*>WP;
	queue<rover*>exr;
	queue<rover*>avlpolr;
	queue<rover*>avlemr;
	queue<rover*>chekEMrover;
	queue<rover*>chekPLrover;
	queue<misson*>combletM;
	rover* r;
	misson* m;
	int e = 0;
	int p = 0;
	int ex = 0;
	int cp = 0;
	int ce = 0;
	int ap = 0;
	int ae = 0;
	int cm = 0;
	while (EW.dequeue(m)) {

		e++;
		WE.enqueue(m);
	}
	while (PW.dequeue(m)) {
		p++;
		WP.enqueue(m);
	}
	while (EX.dequeue(r)) {
		ex++;
		exr.enqueue(r);
	}
	while (AE.dequeue(r)) {
		ae++;
		avlemr.enqueue(r);
	}
	while (AP.dequeue(r)) {
		ap++;
		avlpolr.enqueue(r);
	}
	while (CE.dequeue(r)) {
		ce++;
		chekEMrover.enqueue(r);
	}
	while (CP.dequeue(r)) {
		cp++;
		chekPLrover.enqueue(r);
	}
	while (CM.dequeue(m)) {
		cm++;
		combletM.enqueue(m);
	}


	cout << "step-by-step mode" << endl;
	cout << "current Day: " << x << endl;
	cout << e + p << " Waiting Missons:";
	while (WE.peak(m))
	{
		cout << " " << "[";
		WE.dequeue(m);
		cout << m->getid();
		while (WE.dequeue(m))
			cout << "," << m->getid() << ",";
		cout << "]" << " ";
	}
	while (WP.peak(m))
	{
		cout << "(";
		WP.dequeue(m);
		cout << m->getid();
		while (WP.dequeue(m))
			cout << "," << m->getid();
		cout << ")";
	}
	cout << endl << "------------------------------------------------------------------------------------------------" << endl;

	cout << ex << " In-Execution Misson/Rovers";

	queue<rover*> er;
	queue<rover*> pr;

	while (exr.dequeue(r))
	{
		if (r->gettype() == emergencyrover)
			er.enqueue(r);
		else
			pr.enqueue(r);
	}
	while (er.peak(r))
	{
		er.dequeue(r);
		cout << " [" << r->getmission()->getid() << "/" << r->getid();
		while (er.dequeue(r))
			cout << "," << r->getmission()->getid() << "/" << r->getid();
		cout << "] ";
	}
	while (pr.peak(r))
	{
		pr.dequeue(r);
		cout << " (" << r->getmission()->getid() << "/" << r->getid();
		while (pr.dequeue(r))
			cout << "," << r->getmission()->getid() << "/" << r->getid();
		cout << ") ";
	}
	cout << endl << "------------------------------------------------------------------------------------------------" << endl;


	cout << ae + ap << " Available Rover: ";
	if (avlemr.dequeue(r))
	{

		cout << " [" << r->getid();
		while (avlemr.dequeue(r))
			cout << "," << r->getid();
		cout << "] ";

	}
	if (avlpolr.dequeue(r))
	{

		cout << " (" << r->getid();
		while (avlpolr.dequeue(r))
			cout << "," << r->getid();
		cout << ") ";

	}
	cout << endl << "------------------------------------------------------------------------------------------------" << endl;
	cout << ce + cp << " In-Check Rovers: ";

	if (chekEMrover.dequeue(r))
	{

		cout << " [" << r->getid();
		while (chekEMrover.dequeue(r))
			cout << "," << r->getid();
		cout << "] ";

	}
	if (chekPLrover.dequeue(r))
	{

		cout << "(" << r->getid();
		while (chekPLrover.dequeue(r))
			cout << "," << r->getid();
		cout << ") ";

	}
	cout << endl << "------------------------------------------------------------------------------------------------" << endl;
	cout << cm << " Completed Missons: ";
	queue<misson*> em;
	queue<misson*> pm;
	while (combletM.dequeue(m))
	{

		if (m->gettmissontype() == polar)
			pm.enqueue(m);
		else
			em.enqueue(m);
	}
	while (em.peak(m))
	{
		em.dequeue(m);
		cout << " [" << m->getid();
		while (em.dequeue(m))
			cout << "," << m->getid();
		cout << "] ";
	}
	while (pm.peak(m))
	{
		pm.dequeue(m);
		cout << " (" << m->getid();
		while (pm.dequeue(m))
			cout << "," << m->getid();
		cout << ") ";
	}
	cout << endl;
	Sleep(1000);

}
void UI::sulent1() {
	system("cls");
	cout << "silent mode"<<endl;
	cout << "simulation starts...." << endl;

}
void UI::sulent2() {
	cout << "simulation end,outputfile created" ;
}
