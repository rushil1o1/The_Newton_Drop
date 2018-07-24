#include "EV3Servo-lib-UW.c"
#include "EV3_FileIO.c"

void rotate(int rotations) //Tanish
{
	nMotorEncoder[motorA]=0;
	if (rotations!=0)
	{
		motor[motorA]=100*rotations/fabs(rotations);
		while (fabs(nMotorEncoder[motorA])<fabs(rotations))
		{}
	}
	motor[motorA]=0;
}

void candy_release(int time_open) //Shashwat
{
	setGripperPosition(S1, 5,0);
	wait1Msec(time_open);
	setGripperPosition(S1,5,70);
	wait1Msec(1000);
	setGripperPosition(S1,5,0);
	wait1Msec(1000);
	setGripperPosition(S1,5,40);
	wait1Msec(1000);
	setGripperPosition(S1,5,0);


}



void setup()
{
	setGripperPosition(S1,5,0);
	rotate(120/2);
}

void readFile(TFileHandle & fin,string name,float cost) //Julia
{
	readTextPC(fin,name);
	readFloatPC(fin,cost);
}

void output_file(TFileHandle & fout, string name, float cost)
{
	writeTextPC(fout,name);
	writeTextPC(fout," - ");
	writeFloatPC(fout,cost);
	bool fileOkay1 = openReadPC(fin,"candy_prices.txt");

	TFileHandle fout;
	bool fileOkay = openWritePC(fout,"sales.txt");
	float costs[3]={0,0,0};
	string names[3];
	if (fileOkay1)
		for (int i=0;i<3;i++)
	{
		readFile(fin,names[i],costs[i]);
	}

	displayString(0,names[0]);
	//displayString(1,costs[0]);
	string hey="hey";
	float x=3.2;
	output_file(fout,hey,x);


	/*setup();
	wait1Msec(1000);
	rotate(120);
	wait1Msec(1000);
	candy_release(2000);
	rotate(-120);*/
	//candy_release(1000);



}
