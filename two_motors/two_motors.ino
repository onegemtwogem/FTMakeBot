// Runs both motors forward then backward 

// Based on file>examples>Adafruit Motor Shield Library>MotorTest
// FemTech Make Workshop 2

#include <AFMotor.h> // This is the library you installed!

AF_DCMotor motorA(1);
AF_DCMotor motorB(4);
// Now we have two objects (motor1, motor2) from the same class (AF_DCMotor)!
// Make sure you choose the ports that align with your hardware setup

void setup() { // test that it's all working
  Serial.begin(9600); 
  
  // turn on motors
  motorA.setSpeed(200); 
  motorB.setSpeed(200);

  motorA.run(RELEASE); 
  motorB.run(RELEASE);
  // Remove power from motors
}

void loop() { // Run our function!
  uint8_t i;
  
  motorA.run(FORWARD);
  motorB.run(FORWARD);
  // Now we are doing things for both motors, not just one motor
  
  for (i=100; i<200; i++) {
    // Speed up motors
    motorA.setSpeed(i);
    motorB.setSpeed(i);  
    delay(10);
 }
 
  for (i-200; i>100; i--) {
    // Slow down motors
    motorA.setSpeed(i); 
    motorB.setSpeed(i); 
    delay(10); // 1/100th of a second
 }

  motorA.run(RELEASE);
  motorB.run(RELEASE);
  // Remove power from motors
  delay(1000); // 1 second

  motorA.run(BACKWARD); // Same as forward but now backward!
  motorB.run(BACKWARD);
  
  for (i=100; i<200; i++) {
    // Speed up motors
    motorA.setSpeed(i);  
    motorB.setSpeed(i);
    delay(10);
 }
 
  for (i-200; i>100; i--) {
    // Slow down motors
    motorA.setSpeed(i);  
    motorB.setSpeed(i);
    delay(10);
 }
  
  motorA.run(RELEASE);
  motorB.run(RELEASE);
  // Remove power from motors
  delay(1000);
}


