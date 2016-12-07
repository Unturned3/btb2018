#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#ifndef fakebt_h
#define fakebt_h

// variables supportying dummy functions
int servoPos[4] = {0};
bool servoEnable[4] = {0};

// useless dummy functions
void ao() {}
int get_motor_done(int port) {return 0;}
void bmd(int port) {}
void mav(int port, int speed) {}
int gmpc(int port) {return 0;}
void cmpc(int port) {}
void mtp(int port, int speed, int position) {};
void mrp(int port, int speed, int position) {};
void off(int port) {}
int analog(int port) {return 0;}


void msleep(int ms)
{
	usleep(ms*1000);
}

int get_servo_position(int port)
{
	if(port < 0 || port > 3)
	{
		printf("error: servo port out of range!\n");
		return -1;
	}
	return servoPos[port];
}

int set_servo_position(int port, int position)
{
	if(position > 2047 || position < 0)
	{
		printf("error: servo position out of range!\n");
		return -1;
	}
	if(port < 0 || port > 3)
	{
		printf("error: servo port out of range!\n");
		return -1;
	}
	servoPos[port] = position;
	return 0;
}

int enable_servo(int port)
{
	if(port < 0 || port > 3)
	{
		printf("error: servo port out of range!\n");
		return -1;
	}
	servoEnable[port] = true;
	return 0;
}

int disable_servo(int port)
{
	if(port < 0 || port > 3)
	{
		printf("error: servo port out of range!\n");
		return -1;
	}
	servoEnable[port] = false;
	return 0;
}

#endif

/* end of file */
