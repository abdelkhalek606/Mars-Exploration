#pragma once
#include"definitions.h"
#include"priqueue.h"
#include"queue.h"
#include"misson.h"
#include"rover.h"




class UI
{
public:
	MODE getmod();
	//to updet interface in interactive mode
	void interactiveM(int x,priqueue<misson*>,queue<misson*>,priqueue<rover*>,priqueue<rover*>, priqueue<rover*>,queue<rover*>, queue<rover*>, queue<misson*>);
	//to updet interface in stepbystep mode
	void stepbystep(int x,priqueue<misson*>, queue<misson*>, priqueue<rover*>, priqueue<rover*>, priqueue<rover*>, queue<rover*>, queue<rover*>, queue<misson*>);
	void sulent1();
	void sulent2();
	void nextstep();//to move to next step in interactive mode
	void trash();


};

