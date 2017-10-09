// This program does something interesting - what does it do?
// What would the bot do if the motors drove wheels on either side?

// Based on file>examples>Adafruit Motor Shield Library>MotorTest
// FemTech Make Workshop 1

#include <AFMotor.h> // This is the library you installed!

AF_DCMotor motorA(1);
AF_DCMotor motorB(4);
int pause = 2000; // This is a variable we will use later on
int motor_speed = 150; // This is another variable we will use


void setup() { // test that it's all working
  Serial.begin(9600); 
  
  // turn on motors
  motorA.setSpeed(200); 
  motorB.setSpeed(200);

  motorA.run(RELEASE); 
  motorB.run(RELEASE);
  delay(pause); // Uses our first variable
}

void loop() { // Run our function!
  uint8_t i;
  
  motorA.run(FORWARD);
  
  motorA.setSpeed(motor_speed); // Uses our second variable
  delay(pause);

  motorA.run(RELEASE);

  delay(pause);

  motorB.run(FORWARD);

  motorB.setSpeed(motor_speed);
  delay(pause);

  motorB.run(RELEASE);
  delay(pause);
  

  motorB.run(BACKWARD); // Same as forward but now backward!
  
  motorB.setSpeed(motor_speed);
  delay(pause);

  motorB.run(RELEASE);

  delay(pause);

  motorA.run(BACKWARD);

  motorA.setSpeed(motor_speed);
  delay(pause);

  motorA.run(RELEASE);
  delay(pause);

}

/* What does this function do? Test your guess by uploading to your board and running.
 *  What happens when you change the values of the variables at the beginning?
 */
