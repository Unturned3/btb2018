#include <botball.h>
#include <wallaby.h>
#include <unistd.h>
#include <stdio.h>
//#include "fakebt.h"

#ifndef rarm_h
#define rarm_h
class RArm
{
public:
	RArm(int srvPort)
	{
		sp = srvPort;
		on();
		act(defPos);
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
	void toGround()
	{
		act(groundPos);
	}
	void toTopPom()
	{
		act(topPomPos);
	}
	void toTopDtec()
	{
		act(topPomDtecPos);
	}
	void reset()
	{
		act(defPos);
	}
private:
	void act(int tgtpos)
	{
		printf("ARM\n");
		int ip = get_servo_position(sp);	// ip: initPos
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
	int sp;
	int groundPos = 35;
	int topPomPos = 228;
	int topPomDtecPos = 270;
	int defPos = 300;
};

#endif
