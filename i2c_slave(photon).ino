/*
  Arduino Slave for Raspberry Pi Master
  i2c_slave(photon).ino
  Connects to Raspberry Pi via I2C
 
*/

// Include the Wire library for I2C
#include <Wire.h>

// LED on pin D6 of photon particle
const int ledPin = D6; 

void setup() {
  // Join I2C bus as slave with address 0x08
  Wire.begin(8);
  
  // Call receiveEvent when data received                
  Wire.onReceive(receiveEvent);
  
  // Setup pin D6 as output and turn LED off
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
}

// Function that executes whenever data is received from master
void receiveEvent(int howMany) {
  while (Wire.available()) { // loop through all but the last
    char c = Wire.read(); // receive byte as a character
    digitalWrite(ledPin, c);
  }
}
void loop() {
  delay(100);
}