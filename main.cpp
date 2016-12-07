
#include <botball.h>
#include <wallaby.h>
#include <stdio.h>
#include "rclaw.h"
#include "rarm.h"
#include "rdrive.h"
#include "rsweeper.h"

int main()
{
	RDrive car(0, 1);
	RSweeper sweep(0);
	sweep.on();

	for(int i=0; i<6; i++)
	{
		// action multiplier
		int mult;
		if(i%2 == 0)
			mult = -1;
		else
			mult = 1;

		// follow straight line until meeting a pom
		while(analog(0) > 1000)
		{
			while(analog(1) <= 500)
			{
				car.speed(550, 600);
			}
			car.speed(600, 550);
		}
		
		// stop the car
		ao();
		msleep(100);

		// sweep the poms
		sweep.mov(mult);
		msleep(100);
		sweep.mov(-mult);
		msleep(100);
		sweep.mov(mult);
		msleep(100);
	}
	/*
	car.mov(19, 2);
	msleep(1500);

	camera_open_black();	// open cam

	char color = 'n';
	// determine which color is seen
	camera_load_config("red");
	camera_update();	// get a new image
	int c = get_object_count(0);	// channel 0 in green.conf
	int a = get_object_area(0, 0);
	if(c > 0 && a > 5000)
	{
		color = 'r';
		goto pt;
	}

	camera_load_config("green");
	camera_update();	// get a new image
	c = get_object_count(0);	// channel 0 in green.conf
	a = get_object_area(0, 0);
	if(c > 0 && a > 5000)
	{
		color = 'g';
		goto pt;
	}


	if(color == 'n')	// not green/red, then must be yellow
		color = 'y';

pt:
	printf("color: %c\n", color);
	camera_close();	// close connection
	*/

	// End of Program
	return 0;
}
