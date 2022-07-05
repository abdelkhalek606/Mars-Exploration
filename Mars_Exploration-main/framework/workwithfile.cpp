#include "workwithfile.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include<string>
 

using namespace std;
void workwithfile::readinput(priqueue <rover*>& PR, priqueue <rover*>& ER, queue <event*>& ev, int& N)
{
	

	//int N;
	int PRN; //polar rover number
	int ERN; // energrncy rover number
	//int PRS; // polar rover speed
	//int ERS;
	int NOM; // number of mission before checkup 
	int PD; // polar checkup diuration
	int ED; // emrgency ..........
	ifstream inF("in.txt", ios::in);
	int speed[20];
	if (!inF.is_open())
	{
		cout << "Couldn't Open Input File" << endl;
		return;
	}
	inF >> PRN >> ERN;
	int k=0;
	for (int i = 0; i < PRN + ERN; i++)
	{
		inF >> speed[k];
		k++;
	}
	inF >> NOM >> PD >> ED;
	
	N = NOM;
	number_of_PR = PRN;
	number_of_ER = ERN;
	int c = 1; // counter
	k = 0;
	for (int i = 0; i < PRN; i++)
	{
		rover* n = new rover;
		n->settype(polarrover2);
		n->setspeed(speed[k]);
		n->setcheckupdayes(PD);
		n->setid(c);
		PR.enqueue(n, speed[k]);
		k++;
		c++;

	}

	for(int i=0;i< ERN;i++)
	{
		rover* n = new rover;
		n->settype(emergencyrover);
		n->setspeed(speed[k]);
		n->setcheckupdayes(ED);
		ER.enqueue(n, speed[k]);
		n->setid(c);
		k++;
		c++;
	}
	
	int NOE; // number of events
	inF >> NOE;
	c = 0;
	while (c < NOE)
	{
		string ET; // event type
		string MT; // mission type
		int ED; // event day
		int ID;
		int TLOC;
		int MDUR;
		int SIG;
		
		inF >> ET >> MT >> ED >> ID >> TLOC >> MDUR >> SIG;
		
		event* n = new formulation;
		n->seteventtype(Formulation);
		n->seteventday(ED);
		n->setmissonid(ID);
		n->setdistance(TLOC);
		n->setmissonduration(MDUR);
		n->setsignficant(SIG);
		
		if (MT == "P") {
			n->setmissontype(polar);
		}

		if (MT == "E") {
			n->setmissontype(emergency);
		}
		ev.enqueue(n);
		c++;
	}
}
void workwithfile::makefile(queue <misson*>completM)
{
	misson* p;
	ofstream outF("out.txt", ios::out);
	outF << setw(4)<<"CD" << setw(5) << "ID" << setw(5) << "FD" << setw(5) << "WD" << setw(5) << "ED" << endl;

	int polar_count = 0;
	int Emergency_count = 0;
	int waiting_sum = 0;
	int exec_sum = 0;

	while (completM.dequeue(p))
	{
		outF << setw(4) << p->getcompletedday() << setw(5) << p->getid() << setw(5) << p->getformulationday() << setw(5) << p->getwationgday() << setw(5) << p->getexcday()<< endl;
		waiting_sum = waiting_sum + p->getwationgday();
		exec_sum = exec_sum + p->getexcday();
		if (p->gettmissontype() == polar) {
			polar_count++;
		}
		if (p->gettmissontype() == emergency) {
			Emergency_count++;
		}

	}
	int allmission = polar_count + Emergency_count;

	outF << "Missions :" << allmission << "[ P:" << polar_count << ", E:" << Emergency_count << "]" << endl;

	int number_of_all_rover = number_of_PR + number_of_ER;
	outF << "Rovers:" << number_of_all_rover << "[p:" << number_of_PR << ", E:" << number_of_ER << "]" << endl;

	double Avg_wait = waiting_sum / allmission;
	double Avg_exec = exec_sum / allmission;
	outF << "Avg Wait =" << Avg_wait << ", Avg Exec =" << Avg_exec << endl;
}