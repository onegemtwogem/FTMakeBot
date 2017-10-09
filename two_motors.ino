// Runs both motors forward then backward 

// Based on file>examples>Adafruit Motor Shield Library>MotorTest
// FemTech Make Workshop 1
// Wednesday, 4 October 2017
// Prepared by Holly Stein

#include <AFMotor.h> // This is the library you just installed!

AF_DCMotor motor1(1);
AF_DCMotor motor2(4);
// Now we have two objects (motor1, motor2) from the same class (AF_DCMotor)!

void setup() { // test that it's all working
  Serial.begin(9600); 
  
  // turn on motors
  motor1.setSpeed(200); 
  motor2.setSpeed(200);

  motor1.run(RELEASE); 
  motor2.run(RELEASE);
}

void loop() { // Run our function!
  uint8_t i;
  
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  
  for (i=100; i<200; i++) {
    // Speed up motor!
    motor1.setSpeed(i);
    motor2.setSpeed(i);  
    delay(10);
 }
 
  for (i-200; i>100; i--) {
    // Slow down motor
    motor1.setSpeed(i); 
    motor2.setSpeed(i); 
    delay(10); // 1/100th of a second
 }

  motor1.run(RELEASE);
  motor2.run(RELEASE);
  delay(1000); // 1 second

  motor1.run(BACKWARD); // Same as forward but now backward!
  motor2.run(BACKWARD);
  for (i=100; i<200; i++) {
    motor1.setSpeed(i);  
    motor2.setSpeed(i);
    delay(10);
 }
 
  for (i-200; i>100; i--) {
    motor1.setSpeed(i);  
    motor2.setSpeed(i);
    delay(10);
 }
  
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  delay(1000);
}


