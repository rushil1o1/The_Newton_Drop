//Team 8 74: Candy Dispenser
/*
S1: Tetrix
S2: Color
S3: Ultrasonic
S4: Touch

Motor A: Rotator

Colors:

INVALID: 0
RED: 5
Black: 1
GREEN: 3
BLUE: 2
WHITE: 6


Tetrix:

SV5: Gripper
SV8: Battery

Candies:

0 Blue = M&Ms = $0.75
1 Green = Skittles = $ 1.00
2 Red = Smarties = $ 0.50

BLUE 		GREEN


S    RED

Constants:
minimum time for consumer recognition = 1000 ms
distance for consumer recognition = 150 cm
angle of rotation = deg 116
time interval for open gripper = 700 ms

*/

#include "EV3Servo-lib-UW.c"
#include "EV3_FileIO.c"

//Constants Initialization

const int CONSUMER_WAIT_TIME=1000,CONSUMER_DISTANCE=150,THETA=116,
			CANDY_RELEASE_TIME=700,NUM_CANDY=3,ROTATE_SPEED=100;

//Copied from Robot C Audio Example
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

//Emergency Exit Check
void statusCheck_Touch(int & touchStatus) //DONE BY RUSHIL
{
	if (SensorValue[S4])	//Checks if touch sensor is pressed
		touchStatus=1;
}

//Plays a particular sound file for "time" seconds
void play_sound(const string text, const int time)//DONE BY TANISH
{
	setSoundVolume(100); 	//Sets sound volume to maximum volume size
	playSoundFile(text); //Text is the name of the sound file
	wait1Msec(time*1000); //Allows the sound file to play for the given seconds
}

//Rotates the motor by the given angle
void rotateCandy(int rotations,int & touchStatus) //DONE BY TANISH
{
	statusCheck_Touch(touchStatus);
	nMotorEncoder[motorA]=0; //Reset Encoders
	if (rotations!=0 && touchStatus!=1) //To avoid 0/0
	{
		//Determines direction of rotation
		motor[motorA]=ROTATE_SPEED*rotations/fabs(rotations); 
		statusCheck_Touch(touchStatus);
		if (touchStatus!=1)
		{ //The loop below waits until the rotation angle is satisfied
			while ((fabs(nMotorEncoder[motorA])<fabs(rotations)) 
					&& (touchStatus!=1))
			{
				statusCheck_Touch(touchStatus);
			}
		}
	}
	motor[motorA]=0; //Stops Motors
}

//Opens gripper to release candy for given time
void candy_release(int & touchStatus, int & candywait) //DONE BY SHASHWAT
{
	statusCheck_Touch(touchStatus);
	if (touchStatus!=1)
	{
		setGripperPosition(S1, 5,40); //Opens the gripper
		wait1Msec(candywait); //Waits for Candy to fall down
	}
	statusCheck_Touch(touchStatus);
	if (touchStatus!=1)
	{
		setGripperPosition(S1,5,5); //Closes the gripper
		wait1Msec(1000); 
	}
}

//Setup function for initial calibrations
void setup(int & touchStatus) //DONE BY SHASHWAT
{
	statusCheck_Touch(touchStatus);
	if (!touchStatus)
	{
		setGripperPosition(S1,5,0); //Experimentally proven steps for the 
		wait1Msec(1000);			// gripper to function well enough
		setGripperPosition(S1,5,5);
		wait1Msec(1000);
	}
}

//Reads candy data from the existing file.
void readFile(TFileHandle & fin,string & name,float & cost) //DONE BY JULIA
{
	readTextPC(fin,name); //Extracts the name of the candy
	readFloatPC(fin,cost); //Extracts the cost of the candy
}

//Outputs the candy sales data onto the output file
void output_file(TFileHandle & fout, string name, float cost) //DONE BY JULIA
{
	writeTextPC(fout,name); //Stores the name of the candy
	writeTextPC(fout," - "); 
	writeFloatPC(fout,"%.2f", cost); //Stores the cost of the candy
	writeEndlPC(fout); //Next line
}

//A coin recognition function that returns True or False based on the 
//legitimacy of the coin.

//The function also identifies the color of the coin and carries out the 
//appropriate actions.

//DONE BY RUSHIL
bool coin_recognition(int & rotations,TFileHandle & fout,float & totalSales,
			string name_blue, string name_green,string name_red,float cost_blue,
			float cost_green,float cost_red,int & touchStatus, int & candywait)
{
	eraseDisplay(); 
	statusCheck_Touch(touchStatus);
	while (SensorValue[S2]==(int)colorWhite && touchStatus!=1)	
	//Color Change detection loop
	{
		statusCheck_Touch(touchStatus);
		displayTextLine(3,"NO COIN %i",SensorValue[S2]); //Better Visuality
	}
	wait1Msec(60); //Experimental tests show that a delay of 
			//60 milliseconds makes the coin recognition system more efficient
	int color = SensorValue[S2];
	statusCheck_Touch(touchStatus);
	if ((int)color==(int)colorGreen && touchStatus!=1) // If coin is Green
	{
		playSound(soundLowBuzz); //To show that coin is detected
		wait1Msec(1000);
		displayTextLine(3,"GREEN");
		play_sound("/home/root/lms2012/prjs/rc-data/Dispensing_M/Coin_Green",3);
		output_file(fout,name_green,cost_green);
		candywait=CANDY_RELEASE_TIME-200; //Experimentally viable release time
		rotations=-1*THETA; //Sets rotations
		totalSales+=cost_green;
		play_sound("/home/root/lms2012/prjs/rc-data/Dispensing_Skittles",3);
	}

	else if ((int)color==(int)colorBlue && touchStatus!=1) // If coin is Blue
	{
		playSound(soundLowBuzz); //To show that coin is detected
		wait1Msec(1000);
		displayTextLine(3,"BLUE");
		play_sound("/home/root/lms2012/prjs/rc-data/Dispensing_M/Coin_Blue",3);
		output_file(fout,name_blue,cost_blue);
		rotations=THETA;
		candywait=CANDY_RELEASE_TIME+300; //Experimentally viable release time
		totalSales+=cost_blue;
		play_sound("/home/root/lms2012/prjs/rc-data/Dispensing_M",3);

	}

	else if ((int)color==(int)colorRed && touchStatus!=1) // If coin is Red
	{
		playSound(soundLowBuzz); //To show that coin is detected
		wait1Msec(1000);
		displayTextLine(3,"RED %i",color);
		play_sound("/home/root/lms2012/prjs/rc-data/Dispensing_M/Coin_Red",3);
		output_file(fout,name_red,cost_red);
		candywait=CANDY_RELEASE_TIME+500; //Experimentally viable release time
		rotations=0*THETA;
		totalSales+=cost_red;
		play_sound("/home/root/lms2012/prjs/rc-data/Dispensing_Smarties",3);
	}

	else
	{
		//To show that an incorrect coin was detected
		//Plays the sound three times
		for (int index=0;index<3;index++)
		{
			playSound(soundShortBlip);
			wait1Msec(500);
		}
		displayTextLine(5,"ERROR");
		return false; //If invalid coin is entered
	}
	return true; //If valid coin is entered
}

// Intelligent Algorithm devised to prompt consumer when a consumer is present
void consumerRecognition(int & touchStatus)  //DONE BY RUSHIL
{
	eraseDisplay();
	bool consumerStatus=true; //When consumerStatus turns false, it means that 
							  //a Consumer is detected.
	statusCheck_Touch(touchStatus);
	while (consumerStatus && touchStatus!=1)
	{
		//Checks whether there is anyone present within the consumer distance
		while (SensorValue[S3]>CONSUMER_DISTANCE && touchStatus!=1)
		{
			statusCheck_Touch(touchStatus);
		}
		if (touchStatus!=1)
		{
			clearTimer(T1);
			//Code algorithm to ensure that the a consumer passing by is not 
			//prompted to enter a coin
			while (time1[T1]<CONSUMER_WAIT_TIME && 
					SensorValue[S3]<=CONSUMER_DISTANCE)
			{}

			if (time1[T1]>=CONSUMER_WAIT_TIME)
				displayString(5,"CONSUMER DETECTED");
				consumerStatus=false;
			statusCheck_Touch(touchStatus);
		}
	}


}
//Test function to check whether individual functions work or not
void test(int & touchStatus)   // DONE BY RUSHIL
{
	//  input/output file: tested in task main

	//gripper //works
	setGripperPosition(S1,5,40);
	wait1Msec(1000);
	setGripperPosition(S1,5,10);
	wait1Msec(1000);*/

	//touch //works
	while (!SensorValue[S4])
	{}
	displayTextLine(0,"TOUCH RECEIVED");

	//sound //works
	play_sound("/home/root/lms2012/prjs/rc-data/Coin_Insert",3);

	//motors //works

	rotateCandy(120,touchStatus);

	//coin recognition: tested in task main()

	//consumer recognition //works
	consumerRecognition(touchStatus);
	displayTextLine(1,"CONSUMER DETECTED");
	play_sound("Coin_Insert",3);


}
//DONE BY RUSHIL
task main()
{
	//Begin
	setSoundVolume(100); //Set Sound Volume to maximum sound volume
	playSound(soundBeepBeep);

	//Sensor Initialization
	SensorType[S1]=sensorI2CCustom9V;
	SensorType[S3]=sensorEV3_Ultrasonic;
	SensorType[S2]=sensorEV3_Color;
	SensorType[S4]=sensorEV3_Touch;
	wait1Msec(50);
	SensorMode[S2]=modeEV3Color_Color;
	wait1Msec(50);

	//Variables Initialization

	int rotations=0,touchStatus=0,candywait=0;
	float totalSales=0;
	
	bool coinStatus=false;


	//File Handling

	TFileHandle fin;
	bool fileOkay1 = openReadPC(fin,"candy_prices.txt");

	TFileHandle fout;
	bool fileOkay = openWritePC(fout,"sales.txt");
	float costs[NUM_CANDY]={0,0,0};
	string names[NUM_CANDY];
	if (fileOkay1)
		for (int i=0;i<NUM_CANDY;i++) //Reads file data for each candy on the 
									  //list
		{
			readFile(fin,names[i],costs[i]);
		}
	playSound(soundBeepBeep);
	/*
	TESTING CODE BLOCK
	
	test(touchStatus);
	while (true){
	coinStatus=coin_recognition(rotations,fout,totalSales,names[0],
				names[1],names[2],costs[0],costs[1],costs[2],touchStatus);}
	wait1Msec(10000000); 
	
	TEST ENDS*/
	setup(touchStatus); //Setup 
	statusCheck_Touch(touchStatus);
	while (touchStatus!=1) //Infinite Loop until the emergency exit is pressed
	{
		//Waits for consumer recognition
		consumerRecognition(touchStatus);
		statusCheck_Touch(touchStatus);
		
		//Consumer detected
		playSound(soundBeepBeep);
		
		//While the consumer stays within the range, it keeps instructing 
		//consumer.
		
		/*
		Note: 
		On advice of Professor Hulls, I had to add touchStatus checks at regular 
		points in the code. 
		Thats why the code looks a bit destructured.
		This is to ensure that the robot can be stopped immediately in case 
		of emergencies.
		
		*/
		while (SensorValue[S3]<=CONSUMER_DISTANCE && touchStatus!=1)
		{
			//sound insert coin
			statusCheck_Touch(touchStatus);
			if (touchStatus!=1)
			{
				//Instructs the consumer to insert a coin
				play_sound("/home/root/lms2012/prjs/rc-data/Coin_Insert",3);
				//Identifies the coin
				coinStatus=coin_recognition(rotations,fout,totalSales,names[0],
									names[1],names[2],costs[0],costs[1],
									costs[2],touchStatus,candywait);
				statusCheck_Touch(touchStatus);
			}

			if (coinStatus && touchStatus!=1)
			{
				
				statusCheck_Touch(touchStatus);
				if (touchStatus!=1)
				{
					//Candy Release Procedure carried out
					rotateCandy(rotations,touchStatus);
					wait1Msec(50);
					candy_release(touchStatus,candywait);
					wait1Msec(50);
					rotations*=-1; //Reverses the direction
					rotateCandy(rotations,touchStatus);
					statusCheck_Touch(touchStatus);
					if (touchStatus!=1)
					{
						play_sound("/home/root/lms2012/prjs/rc-data/Thank_You",
									3);
					}
					statusCheck_Touch(touchStatus);
					if (touchStatus!=1)
					{
						play_sound("/home/root/lms2012/prjs/rc-data/removeBowl",
									3);
					}
				}
				else
				{
					statusCheck_Touch(touchStatus);
					if(touchStatus!=1)
						play_sound("/home/root/lms2012/prjs/rc-data/Incorrect",
									3);
				}
			}
		}
		statusCheck_Touch(touchStatus);
	}

	//To showboat our amazing robot logo.
	motor[motorA]=100;
	eraseDisplay();
	playSound(soundBeepBeep);
	wait1Msec(1000);
	//Displays and Outputs the total sales
	string totalsales="TOTAL SALES ($)";
	output_file(fout,totalsales,totalSales);
	displayBigTextLine(1,"TOTAL SALES= $");
	displayBigTextLine(3,"%.2f",totalSales);
	MissionImpossible();  //Because we made the impossible possible.
	motor[motorA]=0; //Stops the motors
	wait1Msec(15000); //Shows the data for 15 seconds
	eraseDisplay();
	closeFilePC(fin); //Closes the files
	closeFilePC(fout);
}
