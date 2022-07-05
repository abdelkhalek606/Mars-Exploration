#include "MARSSTATION.h"
MODE MARSSTATION::selectmode()
{
	//to chosse mode
	UI u;
	mode = u.getmod();
	return mode;
	
}
MARSSTATION::MARSSTATION( ) {
	currentday = 1;
	 silent = true;//for silant mode
}
void MARSSTATION:: failer(rover*r) {
	// if failuer happen move rover to cheakup and add misson to availble misson 
	if (!r)
		return;
	misson* m;
	m = r->getmission();
	if (m->gettmissontype() == polar)
		waittingpolarm.enqueue(m);
	else
		waittingemergancym.enqueue(m,m->getsignficant());
	if (r->gettype() == emergencyrover)
	{
		r->setfinshingday(currentday + r->getcheckupdayes());
		r->setchecktimes();
		roverincheckup_emrgancy.enqueue(r);
	}
	else {
		r->setfinshingday(currentday + r->getcheckupdayes());
		r->setchecktimes();
		roverincheckup_polar .enqueue(r);
	}

}

void MARSSTATION::redinputfile()
{
	//to read input file
	w.readinput(availablpolarrover, avilablemergencyrover, eventt, checktims);

}
void MARSSTATION::makeoutputfile()
{
	//to print output file

	w.makefile(completedmisson);
}
void MARSSTATION::trsh() {
	UI u;
	u.trash();
}
void MARSSTATION::updetinterface()
{
	//to call UI CLASS and update interface
	UI u;
	
	if (mode == interactivem)
	{
		u.interactiveM(currentday, waittingemergancym, waittingpolarm, roverinexecution, avilablemergencyrover, availablpolarrover, roverincheckup_emrgancy, roverincheckup_polar, completedmisson);
		u.nextstep();

	}
	else if (mode == stepbystepm)
	{
		u.stepbystep(currentday, waittingemergancym, waittingpolarm, roverinexecution, avilablemergencyrover, availablpolarrover, roverincheckup_emrgancy, roverincheckup_polar, completedmisson);
		//for step by step
	}
	else if (silent)

	{//to print first part from silant mode
		u.sulent1();
		silent = false;
	}
	else
		u.sulent2();//to print second part from silant mode
}
bool MARSSTATION::iscomplet()
{
	if (waittingpolarm.isEmpty()  && waittingemergancym.isEmpty() && eventt.isEmpty()&&roverinexecution.isEmpty()&& roverincheckup_polar.isEmpty()&& roverincheckup_emrgancy.isEmpty())
		return true;
	return false;
}
void MARSSTATION::assgin()
{
      /// <summary>
      /// assign available misson to availble rover or rover in maintance
      /// </summary>
      while (!waittingemergancym.isEmpty()&&(!avilablemergencyrover.isEmpty()|| !availablpolarrover.isEmpty()|| (!rovermaintenceEM.isEmpty())|| (!rovermaintencePL.isEmpty())))
	  {
		if (!avilablemergencyrover.isEmpty())
		{
			misson* m;
			rover* r;
			waittingemergancym.dequeue(m);
			avilablemergencyrover.dequeue(r);
			r->asign(m,currentday);
			int x = currentday + (m->getmissonduration()) + 2 * (m->getdistance() / r->getspeed()) / 25;
			r->setinexdayes(currentday, x);
			r->setchecktimes();
			r->setfinshingday(x);//finshing day is sum of currentday +mission duration+trip time
			roverinexecution.enqueue(r, -(r->getfinshingday()));
		}
		else if (!availablpolarrover.isEmpty())
		{
			misson* m;
			rover* r;

			waittingemergancym.dequeue(m);
			availablpolarrover.dequeue(r);
			r->asign(m, currentday);
			int x = currentday + (m->getmissonduration()) + 2 * (m->getdistance() / r->getspeed()) / 25;
			r->setinexdayes(currentday, x);
			r->setchecktimes();
			r->setfinshingday(x);
			roverinexecution.enqueue(r, -r->getfinshingday());

		}
		else if(!rovermaintenceEM.isEmpty()){
			misson* m;
			rover* r;
			rovermaintenceEM.peak(r);
			if (r->getspeed() == 1)//if its speed =1  if it halved became 0 and its refused 
				break;
			waittingemergancym.dequeue(m);
			rovermaintenceEM.dequeue(r);
			r->setspeed(r->getspeed() / 2);//if it need a maintance rover its speed halved
			r->asign(m, currentday);
			int x = currentday + (m->getmissonduration()) + 2 * (m->getdistance() / r->getspeed()) / 25;
			r->setinexdayes(currentday, x);
			r->setfinshingday(x);
			roverinexecution.enqueue(r, -r->getfinshingday());
			r->setchecktimes();

		}
		else if (!rovermaintencePL.isEmpty()) {
			misson* m;
			rover* r;
			rovermaintencePL.peak(r);
			if (r->getspeed() == 1)//if its speed =1  if it halved became 0 and its refused 
				break;
			waittingemergancym.dequeue(m);
			rovermaintencePL.dequeue(r);
			r->setspeed(r->getspeed() / 2);//if it need a maintance rover its speed halved
			r->asign(m, currentday);
			int x = currentday + (m->getmissonduration()) + 2 * (m->getdistance() / r->getspeed()) / 25;
			r->setinexdayes(currentday, x);
			r->setfinshingday(x);
			roverinexecution.enqueue(r, -r->getfinshingday());
			r->setchecktimes();

		}
	}
	while (!waittingpolarm.isEmpty()&& (!availablpolarrover.isEmpty()|| (!rovermaintencePL.isEmpty()))) {
		if (!availablpolarrover.isEmpty())
		{
			misson* m;
			rover* r;
			waittingpolarm.dequeue(m);
			availablpolarrover.dequeue(r);
			r->asign(m, currentday);
			int x = currentday + (m->getmissonduration()) + 2 * (m->getdistance() / r->getspeed()) / 25;
			r->setinexdayes(currentday, x);
			r->setchecktimes();

			r->setfinshingday(x);
			roverinexecution.enqueue(r, -r->getfinshingday());

		}
		else if (!rovermaintencePL.isEmpty()) {
			misson* m;
			rover* r;
			rovermaintencePL.peak(r);
			if (r->getspeed() == 1)//if its speed =1  if it halved became 0 and its refused 
				break;
			waittingpolarm.dequeue(m);
			rovermaintencePL.dequeue(r);
			r->setspeed(r->getspeed() / 2);//if it need a maintance rover its speed halved
			r->asign(m, currentday);
			int x = currentday + (m->getmissonduration()) + 2 * (m->getdistance() / r->getspeed()) / 25;
			r->setinexdayes(currentday, x);
			r->setfinshingday(x);
			r->setchecktimes();
			roverinexecution.enqueue(r, -r->getfinshingday());
		}
	}
}
void MARSSTATION::day()
{
	currentday++;
}
void MARSSTATION::makeevent(){
	event* e;
	while (eventt.peak(e)&&e->geteventday()==currentday)
	{
		eventt.dequeue(e);
		e->execute(waittingpolarm, waittingemergancym);
	}
	return ;
}
void MARSSTATION::completedmission() {
	rover* r;

	while (roverinexecution.peak(r)&&r->getfinshingday()==currentday)
	{
		roverinexecution.dequeue(r);

		if (r->propfailer())//if failuer happend 
		{
			failer(r);
		}
		else {
			completedmisson.enqueue(r->getmission());
			if (r->getchecktimes(checktims))//if its turn to check up
			{
				r->setinexdayes(-5, -10);
				r->setfinshingday(currentday + r->getcheckupdayes());
				if (r->gettype() == polarrover2) {
					roverincheckup_polar.enqueue(r);
				}
				else {
					roverincheckup_emrgancy.enqueue(r);
				}

			}

			else if (r->gettype() == polarrover2)
			{
				if (r->getinexdayes() > 100) {// if maintence habbened
					r->setinexdayes(-5, -10); //make maintenc counter became 0 
					rovermaintencePL.enqueue(r);
					r->setfinshingday(currentday + 10);
				}
				else
					availablpolarrover.enqueue(r, r->getspeed());//add to available rover
			}
			else {
				if (r->getinexdayes() > 100) {// if maintence habbened
					r->setinexdayes(-5, -10);//make maintenc counter became 0 
					rovermaintenceEM.enqueue(r);
					r->setfinshingday(currentday + 10);
				}
				else
					avilablemergencyrover.enqueue(r, r->getspeed());//add to available rover
			}
		}
	}

}



void MARSSTATION::getmaintence() {
	//to get rover from maintance queue
	rover* r;
	while (rovermaintencePL.peak(r) && r->getfinshingday() == currentday)
	{
		rovermaintencePL.dequeue(r);
		availablpolarrover.enqueue(r, r->getspeed());
	}
	while (rovermaintenceEM.peak(r) && r->getfinshingday() == currentday)
	{
		rovermaintenceEM.dequeue(r);
		avilablemergencyrover.enqueue(r, r->getspeed());
	}
}

void MARSSTATION::getroverincheck() {
	//to get rover from check up queue queue
	rover* r;
	while (roverincheckup_emrgancy.peak(r) && r->getfinshingday() == currentday)
	{
		roverincheckup_emrgancy.dequeue(r);
			avilablemergencyrover.enqueue(r, r->getspeed());
	}
	while (roverincheckup_polar.peak(r) && r->getfinshingday() == currentday)
	{
		roverincheckup_polar.dequeue(r);
		availablpolarrover.enqueue(r, r->getspeed());

	}

}
