#include "EV3Servo-lib-UW.c"
#include "EV3_FileIO.c"


void candy_release() //Shashwat
{
	setGripperPosition(S1, 5,0);
	wait1Msec(1000);
	setGripperPosition(S1,5,5);
	wait1Msec(1000);
	setGripperPosition(S1,5,40);
	wait1Msec(1000);
	setGripperPosition(S1,5,5);
	wait1Msec(1000);
	setGripperPosition(S1,5,40);
	wait1Msec(1000);

}


void setup()
{
	setGripperPosition(S1,5,0);
}

task main()
{
	setGripperPosition(S1,5,5);
}
