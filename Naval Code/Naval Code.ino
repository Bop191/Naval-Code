#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial BLE(2, 3); // RX, TX2
Servo servoRotation;
Servo servoSpeed;

void setup() {
  BLE.begin(9600);
  Serial.begin(9600);

  sendCommand("AT");
  sendCommand("AT+ROLE0");
  sendCommand("AT+UUID0xFFE0");
  sendCommand("AT+CHAR0xFFE1");
  sendCommand("AT+NAMELightBlue");

  servoRotation.attach(9);
  servoSpeed.attach(8);
  setRotation(0);
}

void loop() {
  readSerial();
  delay(2000);
}