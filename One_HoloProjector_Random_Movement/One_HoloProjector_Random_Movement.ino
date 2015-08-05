/*
* SARLACC For Holo Projectors v 0.3a
*
* - Simple
* - Arduino
* - Random Holoprojector
* - Location for
* - AstroMech Builders
* - Club
* - Control
*
* Micke Askernäs, 2012
*
*/

#include <Servo.h>

/*
* User defined constants
* change these for finetuning your servos
* *NOTE* These values are set for my servos.
* In order to get your system running smooth, you need to
* set your own values. See test code at the bottom of code.
*/

const int Min1X = 45; // Min value for X1 
const int Max1X = 150; // Max value for X1
const int Min1Y = 0; // Min value for Y1
const int Max1Y = 130; // Max value for Y1

const int MinTime = 1000; // Minimum time to wait before another servo movement.
const int MaxTime = 6000; // Maximum time to wait before another servo movement.

/*
* Arduino Pin Configuration
* Change these if needed
*/

const int servo1Xpin = 8; // PIN on Arduino used for Servo1X
const int servo1Ypin = 9; // PIN on Arduino used for Servo1Y

/*
* End Arduino Pin Configuration
*/

/*
* End constants
*/


/* No more changes should be needed below this line. */ 

Servo servo1X; // Define X-Servo 1 (Front)
Servo servo1Y; // Define Y-Servo 1 (Front) 

unsigned long currentTime;
unsigned long loopTime;

void setup()
{
servo1X.attach(servo1Xpin); // Attaching servo to defined pin.
servo1Y.attach(servo1Ypin); // Attaching servo to defined pin.

randomSeed(analogRead(0)); // Feed unhooked analog input as seed for randomizer. Can be set to static number.
// randomSeed(3141592653); // Static number random Seed (for explanantion only)

currentTime = millis();
loopTime = currentTime;
}

void loop()
{
currentTime = millis();

/* Loop 1 for Servo1 */
if (currentTime >= (loopTime + random(MinTime,MaxTime))) {
servo1X.write(random(Min1X,Max1X)); // Turn X-Servo to random X value (0-180)
servo1Y.write(random(Min1Y,Max1Y)); // Turn Y-Servo to random X value (0-180)
loopTime = currentTime; 
}

/* 
* Loop for testing max and min values - Comment this out or remove for working program
* Recommended to take one servo at the time and test out the min/max values on X first, then Y
* and then move on to next servo.
*/

// servo1X.write(Min1X); // Turn Servo 1 to Min X value
// servo2X.write(Min2X); // Turn Servo 2 to Min X value
// servo3X.write(Min3X); // Turn Servo 3 to Min X value
//
// servo1Y.write(Min1Y); // Turn Servo 1 to Min Y value
// servo2Y.write(Min2Y); // Turn Servo 2 to Min Y value 
// servo3Y.write(Min3Y); // Turn Servo 3 to Min Y value
//
// delay (1000);
//
// servo1.write(Max1X); // Turn Servo 1 to Max X value
// servo1.write(Max2X); // Turn Servo 2 to Max X value
// servo1.write(Max3X); // Turn Servo 3 to Max X value
//
// servo1Y.write(Max1Y); // Turn Servo 1 to Max Y value
// servo2Y.write(Max2Y); // Turn Servo 2 to Max Y value 
// servo3Y.write(Max3Y); // Turn Servo 3 to Max Y value
//
// delay (1000);
}
