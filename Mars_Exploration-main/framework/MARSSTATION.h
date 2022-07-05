#pragma once
#include"definitions.h"
#include"formulation.h"
#include"rover.h"
#include"queue.h"
#include"priqueue.h"
#include"workwithfile.h"
#include"UI.h"
class MARSSTATION
{

	queue <misson*> waittingpolarm;//waitting polar misson
	
	priqueue<misson*>waittingemergancym;//waitting emergancy misson misson
	priqueue <rover*> avilablemergencyrover, availablpolarrover; //available rovers
	
	queue <event*>eventt;//queue for event
	queue <misson*>completedmisson;
	
	priqueue<rover*>roverinexecution;
	queue<rover*>roverincheckup_polar;
	queue<rover*>roverincheckup_emrgancy;
	queue<rover*>rovermaintenceEM;//for emergance rover maintance
	queue<rover*>rovermaintencePL;//for polar rover maintance

	int currentday;
	MODE mode;
	int checktims;//number of mission to make a check up
	bool silent;
	workwithfile w;
public:
	MODE selectmode();
	MARSSTATION( );
	void redinputfile();
	void makeoutputfile();
	void updetinterface();
	bool iscomplet();
	void failer(rover*);
	void getmaintence();
	void assgin();
	void makeevent();
	void completedmission();
	void getroverincheck();
	void day();
	void trsh();

};

