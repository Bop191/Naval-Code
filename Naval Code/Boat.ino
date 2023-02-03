#include <Servo.h>

void setRotation(int degrees){
  servoRotation.write(degrees);
  delay(500);
}

void setSpeed(int speed){
  servoSpeed.write(speed);
}