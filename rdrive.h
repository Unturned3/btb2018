#include <botball.h>
#include <wallaby.h>
#include <stdio.h>
//#include "fakebt.h"

class RDrive
{
public:
	RDrive(int p1,int p2)
	{
		lp = p1;
		rp = p2;
		ao();
	}

	void mov(float dist, float seconds)
	{
		mav(lp, dist/seconds*(cmt-5));
		mav(rp, dist/seconds*(cmt-5));
		msleep(int(seconds) * 1000);
		ao();
	}

	// warning: this is a non-blocking function
	void speed(int ls, int rs)
	{
		mav(lp, ls);
		mav(rp, rs);
	}

	void tiltRight(int dir)
	{
		smov(lp, dir*3, 1);
		msleep(200);
		ao();
	}

	void tiltLeft(int dir)
	{
		smov(rp, dir*3, 1);
		msleep(200);
		ao();
	}

private:

	void smov(int port, float dist, float seconds)
	{
		mav(port, dist/seconds*(cmt-5));
		msleep(int(seconds) * 1000);
		ao();
	}

private:
	int lp;
	int rp;
	/*
	move 15 cm: 1305 ticks
	move 1 cm: 1305/15 = 87 ticks
	*/
	int cmt = 84;	/* 84 ticks = 1 cm */
};
