#include <wallaby.h>
#include <botball.h>
#include <stdio.h>

class RSweeper
{
public:
	RSweeper(int port)
	{
		sp = port;
		act(rpos);	// initialize it to right side
		off();
	}
	RSweeper(int port, int leftPos, int rightPos)
	{
		sp = port;
		lpos = leftPos;
		rpos = rightPos;
		act(rpos);	// initialize it to right side
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
	void mov(int dir)
	{
		if(dir == 1)	// swing right
			act(rpos);
		else if(dir == -1)	// swing left
			act(lpos);
		else
			printf("RSweeper::mov() : dir must be 1 or -1\n");
	}
private:
	void act(int tgtpos)
	{
		int ip = get_servo_position(sp);	// ip: initPos
		while(ip > tgtpos)
		{
			ip-=5;
			set_servo_position(sp, ip);
			msleep(1);
		}
		while(ip < tgtpos)
		{
			ip+=5;
			set_servo_position(sp, ip);
			msleep(1);
		}
	}

private:
	int sp;	// servo port
	int lpos = 695;
	int rpos = 1900;
};
