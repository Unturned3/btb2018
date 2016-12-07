#include <wallaby.h>
#include <botball.h>
#include <stdio.h>
#include "../rdrive.h"
int ds0;
int ds1;


int main()
{
	// clear motor pos counters
	cmpc(0);
	cmpc(1);

	// drift left 
	mtp(0, 450, 2880);
	mtp(1, 565, 3617);

	/*
	bmd(0);
	bmd(1);
	freeze(0);
	freeze(1);
	*/
	msleep(6400);	// wait for 6.4 seconds for "drift left" to finish
	ao();

	int p0 = gmpc(0);
	int p1 = gmpc(1);
	printf("pos after drift: %d %d\n", p0, p1);

	// clear motor pos counters
	cmpc(0);
	cmpc(1);

	// move back
	mtp(0, 450, -2803);
	mtp(1, 322, -2004);

	msleep(6220);

	ao();


	return 0;
}
