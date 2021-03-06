#include <AFMotor.h>

AF_DCMotor motorA(1); //Right motor
AF_DCMotor motorB(3); //Left motor

//CALIBRATION
int stridelength = 1000; //time to move forward 1 pace
int turnlength = 1000; //time it takes to rotate 90 degrees
int pause = 2000;
uint8_t i = 200; //data type i

// distance = speed x time, so to calibrate you can change speed or time

// ----------------THESE ARE FUNCTIONS-------------- //
void setup() {
  Serial.begin(9600);

  motorA.setSpeed(200);
  motorB.setSpeed(200);

  motorA.run(RELEASE);
  motorB.run(RELEASE);
  delay(pause);
}

void stride() {
  motorA.run(FORWARD);
  motorB.run(BACKWARD);

  motorA.setSpeed(i);
  motorB.setSpeed(i);

  delay(stridelength); //go forward
  
  motorA.run(RELEASE);
  motorB.run(RELEASE);
}

void turnLeft() {
  motorA.run(FORWARD);
  motorA.setSpeed(i);
  delay(turnlength); //turn
  motorA.run(RELEASE);
  
}

void turnRight() {
  motorB.run(BACKWARD);
  motorB.setSpeed(i);
  delay(turnlength); //turn
  motorB.run(RELEASE);
  
}

// ---------------THESE ARE INSTRUCTIONSS-------------- //
// Change this to make the bot do what you want!
void loop() {
  stride(); 
  delay(pause);
  turnRight();
  delay(pause);
  stride(); 
  delay(pause);
  turnLeft();
  delay(pause);
  stride(); 
  delay(pause);
  turnLeft();
  delay(pause);
  turnLeft();
  delay(pause);
  stride();
  delay(pause);
  turnLeft();
  delay(pause);
  stride(); 
  delay(pause);
  turnLeft();
  delay(pause);
  stride(); 
  delay(pause);

}
