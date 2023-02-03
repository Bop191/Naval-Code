#include <SoftwareSerial.h>

void sendCommand(const char * command) {
  Serial.print("Command: ");
  Serial.println(command);
  BLE.println(command);
  delay(100); // Delay is needed!

  char reply[100];
  int i = 0;
  while (BLE.available()) {
    reply[i] = BLE.read();
    i += 1;
  }

  reply[i] = '\0';
  if(strlen(reply) > 0){
    Serial.print(reply);
  } else {
    Serial.println("There was no reply!");
  }
  delay(500);
}

void readSerial(){
  int input = BLE.read();
  if(input > -1 && input < 181){
    Serial.print(input);
    Serial.println("°");
    setRotation(input);
  }
  else if(input > 180 && input < 202){
    if(input == 181){
      Serial.println("0% speed");
      setSpeed(0);
    }
    if(input == 182){
      Serial.println("5% speed");
      setSpeed(5);
    }
    if(input == 183){
      Serial.println("10% speed");
      setSpeed(10);
    }
    if(input == 184){
      Serial.println("15% speed");
      setSpeed(15);
    }
    if(input == 185){
      Serial.println("20% speed");
      setSpeed(20);
    }
    if(input == 186){
      Serial.println("25% speed");
      setSpeed(25);
    }
    if(input == 187){
      Serial.println("30% speed");
      setSpeed(30);
    }
    if(input == 188){
      Serial.println("35% speed");
      setSpeed(35);
    }
    if(input == 189){
      Serial.println("40% speed");
      setSpeed(40);
    }
    if(input == 190){
      Serial.println("45% speed");
      setSpeed(45);
    }
    if(input == 191){
      Serial.println("50% speed");
      setSpeed(50);
    }
    if(input == 192){
      Serial.println("55% speed");
      setSpeed(55);
    }
    if(input == 193){
      Serial.println("60% speed");
      setSpeed(60);
    }
     if(input == 194){
      Serial.println("65% speed");
      setSpeed(65);
    }
    if(input == 195){
      Serial.println("70% speed");
      setSpeed(70);
    }
    if(input == 196){
      Serial.println("75 speed");
      setSpeed(75);
    }
    if(input == 197){
      Serial.println("80% speed");
      setSpeed(80);
    }
    if(input == 198){
      Serial.println("85% speed");
      setSpeed(85);
    }
    if(input == 199){
      Serial.println("90% speed");
      setSpeed(90);
    }
    if(input == 200){
      Serial.println("95% speed");
      setSpeed(95);
    }
    if(input == 201){
      Serial.println("100% speed");
      setSpeed(100);
    }
  }
  else if(input != -1){
    Serial.println("Wrong BLE signal received!");
    Serial.println(input);
  }
}

void writeToBLE(char value) {
  Serial.print("Writing hex :");
  Serial.println(value, HEX);
  BLE.write(value);
}