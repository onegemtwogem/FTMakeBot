// Runs motor forward then backward 

// Based on file>examples>Adafruit Motor Shield Library>MotorTest
// FemTech Make Workshop 1
// Wednesday, 4 October 2017
// Prepared by Holly Stein

#include <AFMotor.h> // This is the library you just installed!

AF_DCMotor motor(1);
// Define name of motor and which port it's connected to
// If you change this to AF_DCMotor jerry(3) your motor's new 
// name would be 'jerry' and would be connected to port 3
/*  OBJECTS AND CLASSES
 *   Once we define 'motor', it is an OBJECT. An object is a specific 
 *   version of a CLASS. A class is like a powerpoint template. An object
 *   is like the specific presentation you make based on that template. You 
 *   could make multiple different presentations with the same template, and 
 *   they would have the same parts, but with their own specific values and 
 *   attributes.
 *   
 *   Our class is named 'AF_DCMotor'. This class gives 
 *   us a bunch of useful functions, like 'setSpeed' and 'run'. If we didn't
 *   have this class defined for us, we would have to figure out how to
 *   communicate directly to the board on our own. Adafruit gives us a
 *   template that we can modify for our own specific needs.
 */

void setup() { // test that it's all working
  Serial.begin(9600); // Communicate with board

  // turn on motor
  motor.setSpeed(200); 
  // Can set between 0 and 255 (some speeds are not powerful enough to move motor!)

  motor.run(RELEASE); // Remove power from motor (but does not apply breaks)
}

void loop() { // Run our function!
  uint8_t i; // Defines data type of i
  
  motor.run(FORWARD);
  for (i=100; i<200; i++) {
    // Start speed at 100, steps i to 200
    // Speed up motor!
    motor.setSpeed(i);  
    delay(10);
 }
 
  for (i=200; i>100; i--) {
    // Slow down motor
    motor.setSpeed(i);  
    delay(10);
 }

  motor.run(RELEASE);
  delay(1000);

  motor.run(BACKWARD); // Same as forward but now backward!
  for (i=100; i<200; i++) {
    motor.setSpeed(i);  
    delay(10);
 }
 
  for (i=200; i>100; i--) {
    motor.setSpeed(i);  
    delay(10);
 }
  
  motor.run(RELEASE);
  delay(1000);
}


