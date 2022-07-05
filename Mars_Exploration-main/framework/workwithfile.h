#pragma once
#include"queue.h"
#include"priqueue.h"
#include"formulation.h"
#include"rover.h"
#include"formulation.h"
#include"misson.h"
#include<string>

class workwithfile
{
	int number_of_PR;
	int number_of_ER;
public:
	void readinput( priqueue <rover*>&PR, priqueue <rover*>&EM, queue <event*>&ev,int& checktims);
	void makefile(queue <misson*>completM);
};

