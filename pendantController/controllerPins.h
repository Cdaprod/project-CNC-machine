

// Define the pins that will be used for the CNC controller
const int pin1 = 2;
const int pin2 = 3;
const int pin3 = 4;
const int pin4 = 5;
const int pin5 = 6;
const int pin6 = 7;
const int pin7 = 8;
const int pin8 = 9;
const int pin9 = 10;
const int pin10 = 11;
const int pin11 = 12;
const int pin12 = 13;
const int pin13 = A0;
const int pin14 = A1;
const int pin15 = A2;
const int pin16 = A3;
const int pin17 = A4;
const int pin18 = A5;
const int pin19 = A6;
const int pin20 = A7;
const int groundPin = A8;
const int voltagePin = A9;

void setup() {
  // Set the CNC controller pins as outputs
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin5, OUTPUT);
  pinMode(pin6, OUTPUT);
  pinMode(pin7, OUTPUT);
  pinMode(pin8, OUTPUT);
  pinMode(pin9, OUTPUT);
  pinMode(pin10, OUTPUT);
  pinMode(pin11, OUTPUT);
  pinMode(pin12, OUTPUT);
  pinMode(pin13, OUTPUT);
  pinMode(pin14, OUTPUT);
  pinMode(pin15, OUTPUT);
  pinMode(pin16, OUTPUT);
  pinMode(pin17, OUTPUT);
  pinMode(pin18, OUTPUT);
  pinMode(pin19, OUTPUT);
  pinMode(pin20, OUTPUT);
  
  // Set the ground and voltage pins as outputs and set the voltage pin to HIGH
  pinMode(groundPin, OUTPUT);
  pinMode(voltagePin, OUTPUT);
  digitalWrite(voltagePin, HIGH);
}

void loop() {
  // Sample code for controlling the CNC controller pins
  digitalWrite(pin1, HIGH);
  delay(1000);
  digitalWrite(pin1, LOW);
  delay(1000);
}
