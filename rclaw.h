#include <botball.h>
#include <wallaby.h>
#include <stdio.h>
//#include "fakebt.h"	// fake botball header made by Richard

#ifndef rclaw_h
#define rclaw_h

class RClaw
{
public:
	RClaw(int srvPort)
	{
		sp = srvPort;
		on();
		act(widePos);	// init the position
		off();
	}
	void on()
	{
		enable_servo(sp);
	}
	void off()
	{
		disable_servo(sp);
	}
	void grabPom()
	{
		printf("grabPom...\n");
		act(pomPos);
	}
	void looseGrab()
	{
		printf("looseGrab...\n");
		act(loosePos);
	}
	void release()
	{
		printf("releasing...\n");
		act(widePos);
	}
private:
	/*
	act: moves to target position with speed 200 ticks per second
		this is a blocking function, i.e. will not return unless
		the specified job is finished.
	*/
	void act(int tgtpos)
	{
		int ip = get_servo_position(sp);	// ip: initPos
		printf("CLAW\n");
		printf("  servo init position: %d\n", ip);
		while(ip > tgtpos)
		{
			ip--;
			set_servo_position(sp, ip);
			msleep(1);
		}
		while(ip < tgtpos)
		{
			ip++;
			set_servo_position(sp, ip);
			msleep(1);
		}
		printf("  servo final position: %d\n", ip);
	}
private:
	int sp;	// servo port
	// different servo positions for grabbing
	// different stuff
	int pomPos = 585;
	int loosePos = 750;
	int widePos= 1000;
};

#endif

