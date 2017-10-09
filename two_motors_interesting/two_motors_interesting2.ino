// Does something interesting - what does it do?
// What would the bot do if the motors drove wheels on either side?

// Based on file>examples>Adafruit Motor Shield Library>MotorTest
// FemTech Make Workshop 1
// Wednesday, 4 October 2017
// Prepared by Holly Stein

#include <AFMotor.h> // This is the library you just installed!

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
int pause = 2000;
int motor_speed = 150;
// Now we have two objects (motor1, motor2) from the same class (AF_DCMotor)!

void setup() { // test that it's all working
  Serial.begin(9600); 
  
  // turn on motors
  motor1.setSpeed(200); 
  motor2.setSpeed(200);

  motor1.run(RELEASE); 
  motor2.run(RELEASE);
  delay(pause); // 1 second
}

void loop() { // Run our function!
  uint8_t i;
  
  motor1.run(FORWARD);
  
  motor1.setSpeed(motor_speed);
  delay(pause);

  motor1.run(RELEASE);

  motor2.run(FORWARD);

  motor2.setSpeed(motor_speed);
  delay(pause);

  motor2.run(RELEASE);
  delay(pause);
  

  motor2.run(BACKWARD); // Same as forward but now backward!
  
  motor2.setSpeed(motor_speed);
  delay(pause);

  motor2.run(RELEASE);

  motor1.run(BACKWARD);

  motor1.setSpeed(motor_speed);
  delay(pause);

  motor1.run(RELEASE);
  delay(pause);

}
