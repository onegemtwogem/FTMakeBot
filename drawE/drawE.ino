#include <AFMotor.h>

AF_DCMotor motorA(4); //Right motor
AF_DCMotor motorB(1); //Left motor

//CALIBRATION
int stridelength = 10; //time to move forward 1 pace
int turnlength = 10; //time it takes to rotate 90 degrees
int pause = 2000;
uint8_t i = 200; //data type i

// distance = speed x time, so to calibrate you can change speed or time

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

void loop() {

  stride(); //top of E
  turnLeft();
  stride(); //top, side of E
  turnLeft();
  stride(); //middle of E
  turnLeft();
  turnLeft();
  stride(); //double back on middle of E
  turnLeft();
  stride(); //bottom, side of E
  turnLeft();
  stride(); //bottom of E


  
  

}
