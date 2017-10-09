// Welcome to the first program we will run on our bot!
// Any line that begins with '//' is a comment. 
// Comments are ignored by the computer. Comments tell you what is going on in the code.

// This program runs motor forward then backward 

// Based on file>examples>Adafruit Motor Shield Library>MotorTest
// FemTech Make Bot, Workshop 2

// INSTRUCTIONS
// Read through the code, especially the comments

#include <AFMotor.h> // This is the library you installed before class!

AF_DCMotor motor(1);
// The previous line defines name of motor and which port it's connected to
// If you change this to AF_DCMotor jerry(3) your motor's new 
// name would be 'jerry' and would be connected to port 3
// Make sure you choose one of the ports that align with your hardware setup
// See hardware configuration: https://learn.adafruit.com/adafruit-motor-shield/af-dcmotor-class 
/*   OPTIONAL COMMENT - you don't have to read/understand this
 *   OBJECTS AND CLASSES (this is a multi-line comment)
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

void setup() { // This is a function called 'setup'
  // This function tests that program is working on arduino board
  Serial.begin(9600); // Communicate with board

  motor.setSpeed(200);
  // This function turns on motor 
  // Can set motor speed between 0 and 255 (some speeds are not powerful enough to move motor!)

  motor.run(RELEASE); 
  // This function removes power from motor (but does not apply breaks)
}

void loop() { 
  // The main function for our board!
  // A loop means this program will keep repeating until something stops it 
  // (In this case when we turn off the battery pack and unplug the USB - no power supply)
  
  uint8_t i; // Defines data type i, don't worry about this
  
  motor.run(FORWARD); // Tell motor which direction to move
  
  for (i=100; i<200; i++) {
    // Increase speed, i, of motor - start at 100, steps i to 200
    motor.setSpeed(i);  
    delay(10); // Hold speed for 10 thousanths of a second
 }
 
  for (i=200; i>100; i--) {
    // Slow down motor
    motor.setSpeed(i);  
    // Decrease speed, i, of motor - start at __, steps i to __
    delay(10);
 }

  motor.run(RELEASE);
  // Remove power from motor (does not apply breaks)
  delay(1000);

  motor.run(BACKWARD); // Same as forward but now backward!
  
  for (i=100; i<200; i++) {
    motor.setSpeed(i);  
    // Increase speed of motor
    delay(10);
 }
 
  for (i=200; i>100; i--) {
    motor.setSpeed(i);  
    // Decrease speed of motor
    delay(10);
 }
  
  motor.run(RELEASE);
  // Remove power from motor (does not apply breaks)
  delay(1000);
}

/* Now that you have an idea of what this code does, let's run it.
 *  Press the check mark at the top left (verify). This makes sure you have no errors.
 *  If you have no errors, connect your board to your computer with a USB.
 *  Under 'Tools', make sure 'Board' is set to 'Arduino/Genuino Uno'.
 *  Under 'Tools', select the correct port (should be obvious, otherwise trial and error).   
 *  Press the arrow at the top left (upload).
 *  Allow program to upload onto board, wait until you see 'Done uplading.'
 *  You may feel motors attempting to move, or move weakly, this is from the power
 *  the board is getting from the USB. Turn on the battery pack to get the motors moving properly!
 *  Now try setting up two_motors program.
 */

