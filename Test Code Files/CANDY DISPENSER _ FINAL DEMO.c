//Team 8 74: Candy Dispenser
/*
S1: Tetrix
S2: Color
S3: Ultrasonic
S4: Touch

Motor A: Rotator

Colors:

RED: 5
Black: 1
GREEN: 3
BLUE: 2

Tetrix:

SV5: Gripper
SV8: Battery

Candies:

0 Blue= M&Ms = $0.75
1 Green= Skittles = $ 1.00
2 Red= Gum Balls = $ 0.50

BLUE 		GREEN


S   RED

Constants:
minimum time for consumer recognition= 1500 ms
distance for consumer recognition= 40 cm
angle of rotation= deg 120
time interval for open gripper= 1500 ms

*/

/*

Problems:
<1> Parallel Music Play
<2> Parallel Consumer Recognition
<3> File Re initialization.
*/

#include "EV3Servo-lib-UW.c"
#include "EV3_FileIO.c"

//Constants Initialization

const int time_wait=1500,dist=40,theta=120,time_open=1500;

void MissionImpossible()
{
	//        100 = Tempo
	//          6 = Default octave
	//    Quarter = Default note length
	//        10% = Break between notes
	//
	playTone(  880,    7); wait1Msec(  75);  // Note(D, Duration(32th))
	playTone(  933,    7); wait1Msec(  75);  // Note(D#, Duration(32th))
	playTone(  880,    7); wait1Msec(  75);  // Note(D, Duration(32th))
	playTone(  933,    7); wait1Msec(  75);  // Note(D#, Duration(32th))
	playTone(  880,    7); wait1Msec(  75);  // Note(D, Duration(32th))
	playTone(  933,    7); wait1Msec(  75);  // Note(D#, Duration(32th))
	playTone(  880,    7); wait1Msec(  75);  // Note(D, Duration(32th))
	playTone(  933,    7); wait1Msec(  75);  // Note(D#, Duration(32th))
	playTone(  880,    7); wait1Msec(  75);  // Note(D, Duration(32th))
	playTone(  880,    7); wait1Msec(  75);  // Note(D, Duration(32th))
	playTone(  933,    7); wait1Msec(  75);  // Note(D#, Duration(32th))
	playTone(  988,    7); wait1Msec(  75);  // Note(E, Duration(32th))
	playTone( 1047,    7); wait1Msec(  75);  // Note(F, Duration(32th))
	playTone( 1109,    7); wait1Msec(  75);  // Note(F#, Duration(32th))
	playTone( 1175,    7); wait1Msec(  75);  // Note(G, Duration(32th))
	playTone( 1175,   14); wait1Msec( 150);  // Note(G, Duration(16th))
	playTone(    0,   27); wait1Msec( 300);  // Note(Rest, Duration(Eighth))
	playTone( 1175,   14); wait1Msec( 150);  // Note(G, Duration(16th))
	playTone(    0,   27); wait1Msec( 300);  // Note(Rest, Duration(Eighth))
	playTone( 1398,   14); wait1Msec( 150);  // Note(A#, Duration(16th))
	playTone(    0,   14); wait1Msec( 150);  // Note(Rest, Duration(16th))
	playTone(  784,   14); wait1Msec( 150);  // Note(C, Duration(16th))
	playTone(    0,   14); wait1Msec( 150);  // Note(Rest, Duration(16th))
	playTone( 1175,   14); wait1Msec( 150);  // Note(G, Duration(16th))
	playTone(    0,   27); wait1Msec( 300);  // Note(Rest, Duration(Eighth))
	playTone( 1175,   14); wait1Msec( 150);  // Note(G, Duration(16th))
	playTone(    0,   27); wait1Msec( 300);  // Note(Rest, Duration(Eighth))
	playTone( 1047,   14); wait1Msec( 150);  // Note(F, Duration(16th))
	playTone(    0,   14); wait1Msec( 150);  // Note(Rest, Duration(16th))
	playTone( 1109,   14); wait1Msec( 150);  // Note(F#, Duration(16th))
	playTone(    0,   14); wait1Msec( 150);  // Note(Rest, Duration(16th))
	playTone( 1175,   14); wait1Msec( 150);  // Note(G, Duration(16th))
	playTone(    0,   27); wait1Msec( 300);  // Note(Rest, Duration(Eighth))
	playTone( 1175,   14); wait1Msec( 150);  // Note(G, Duration(16th))
	playTone(    0,   27); wait1Msec( 300);  // Note(Rest, Duration(Eighth))
	playTone( 1398,   14); wait1Msec( 150);  // Note(A#, Duration(16th))
	playTone(    0,   14); wait1Msec( 150);  // Note(Rest, Duration(16th))
	playTone(  784,   14); wait1Msec( 150);  // Note(C, Duration(16th))
	playTone(    0,   14); wait1Msec( 150);  // Note(Rest, Duration(16th))
	playTone( 1175,   14); wait1Msec( 150);  // Note(G, Duration(16th))
	playTone(    0,   27); wait1Msec( 300);  // Note(Rest, Duration(Eighth))
	playTone( 1175,   14); wait1Msec( 150);  // Note(G, Duration(16th))
	playTone(    0,   27); wait1Msec( 300);  // Note(Rest, Duration(Eighth))
	playTone( 1047,   14); wait1Msec( 150);  // Note(F, Duration(16th))
	playTone(    0,   14); wait1Msec( 150);  // Note(Rest, Duration(16th))
	playTone( 1109,   14); wait1Msec( 150);  // Note(F#, Duration(16th))
	playTone(    0,   14); wait1Msec( 150);  // Note(Rest, Duration(16th))
	playTone( 1398,   14); wait1Msec( 150);  // Note(A#, Duration(16th))
	playTone( 1175,   14); wait1Msec( 150);  // Note(G, Duration(16th))
	playTone(  880,  108); wait1Msec(1200);  // Note(D, Duration(Half))
	playTone(    0,    7); wait1Msec(  75);  // Note(Rest, Duration(32th))
	playTone( 1398,   14); wait1Msec( 150);  // Note(A#, Duration(16th))
	playTone( 1175,   14); wait1Msec( 150);  // Note(G, Duration(16th))
	playTone(  831,  108); wait1Msec(1200);  // Note(C#, Duration(Half))
	playTone(    0,    7); wait1Msec(  75);  // Note(Rest, Duration(32th))
	playTone( 1398,   14); wait1Msec( 150);  // Note(A#, Duration(16th))
	playTone( 1175,   14); wait1Msec( 150);  // Note(G, Duration(16th))
	playTone(  784,  108); wait1Msec(1200);  // Note(C, Duration(Half))
	playTone(    0,   14); wait1Msec( 150);  // Note(Rest, Duration(16th))
	playTone(  932,   14); wait1Msec( 150);  // Note(A#5, Duration(16th))
	playTone(  784,   14); wait1Msec( 150);  // Note(C, Duration(16th))
	return;
}

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
	setGripperPosition(S1, 5,40);
	wait1Msec(time_open);
	setGripperPosition(S1,5,10);
	wait1Msec(1000);
}

void setup()
{
	setGripperPosition(S1,5,5);
	wait1Msec(1000);
}

void readFile(TFileHandle & fin,string name,float cost) //Julia
{
	readTextPC(fin,name);
	readFloatPC(fin,cost);
}

void output_file(TFileHandle & fout, string name, float cost)
{
	//writeTextPC(fout,fixed);
	//writeTextPC(fout,setprecision(2));
	writeTextPC(fout,name);
	writeTextPC(fout," - ");
	writeFloatPC(fout,cost);
	writeEndlPC(fout);
}

bool coin_recognition(int & rotations,TFileHandle & fout,float & total_sales,string name_blue,
string name_green,string name_red,float cost_blue,float cost_green,float cost_red)
{
	int curr_color=SensorValue[S2];

	while (SensorValue[S2]==(int)curr_color)
	{}

	if (SensorValue[S2]==(int)colorGreen)
	{
		output_file(fout,name_green,cost_green);
		rotations=theta;
		total_sales+=cost_green;
		playSoundFile("Green_Coin_Received");
		playSoundFile("Dispensing_Skittles");
	}

	else if (SensorValue[S2]==(int)colorBlue)
	{
		output_file(fout,name_blue,cost_blue);
		rotations=-1*theta;
		total_sales+=cost_blue;
		playSoundFile("Blue_Coin_Received");
		playSoundFile("Dispensing_M_and_Ms");

	}

	else if (SensorValue[S2]==(int)colorRed)
	{
		output_file(fout,name_red,cost_red);
		rotations=0*theta;
		total_sales+=cost_red;
		playSoundFile("Red_Coin_Received");
		playSoundFile("Dispensing_Gum_Balls");
	}

	else
		return false;
	return true;
}

void consumer_recognition()
{
	bool status=true;
	while (status && !SensorValue[S4])
	{
		while (SensorValue[S3]>dist)
		{}

		clearTimer(T1);

		while (time1[T1]<time_wait && SensorValue[S3]<=dist)
		{}

		if (time1[T1]>=time_wait)
			status=false;
	}
}

task main()
{
	//Set System Volume
	setSoundVolume(100);
	//Sensor Initialization

	SensorType[S1]=sensorI2CCustom9V;
	SensorType[S3]=sensorEV3_Ultrasonic;
	SensorType[S2]=sensorEV3_Color;
	SensorType[S4]=sensorEV3_Touch;
	wait1Msec(50);
	SensorMode[S2]=modeEV3Color_Color;
	wait1Msec(50);
	//MissionImpossible();
	//Variables Initialization

	int rotations=0;
	float total_sales=0;
	bool coin_status=false;

	//File Handling

	TFileHandle fin;
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

	setup();

	while (!SensorValue[S4])
	{
		consumer_recognition();

		while (SensorValue[S3]<=dist && !SensorValue[S4])
		{
			//sound insert coin
			playSoundFile("Insert_Coin");

			coin_status=coin_recognition(rotations,fout,total_sales,names[0],
			names[1],names[2],costs[0],costs[1],costs[2]);
			if (coin_status)
			{
				rotate(rotations);
				motor[motorA]=0;
				candy_release(time_open);
				rotations*=-1;
				rotate(rotations);
				//Sound for dispensing candy

				//Sound: thank you
				playSoundFile("Thank_you");
				playSoundFile("Remove_Bowl");
			}
			else
			{
				playSoundFile("Incorrect_Coin");
			}
		}
	}

	playSound(soundBeepBeep);
	wait1Msec(1000);
	string totalsales="TOTAL SALES ($)";
	output_file(fout,totalsales,total_sales);
	displayBigTextLine(1,"TOTAL SALES= $ %.2f",total_sales);
	MissionImpossible();
	wait1Msec(30000);
	eraseDisplay();
	closeFilePC(fin);
	closeFilePC(fout);
}
