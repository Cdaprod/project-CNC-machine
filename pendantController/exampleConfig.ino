// Define the pins that will be used for the CNC controller
const int xPin = 2; // assign pin 2 to X-axis
const int yPin = 3; // assign pin 3 to Y-axis
const int zPin = 4; // assign pin 4 to Z-axis
const int groundPin = A8;
const int voltagePin = A9;

void setup() {
  // Set the axis pins as outputs
  pinMode(xPin, OUTPUT);
  pinMode(yPin, OUTPUT);
  pinMode(zPin, OUTPUT);
  
  // Set the ground and voltage pins as outputs and set the voltage pin to HIGH
  pinMode(groundPin, OUTPUT);
  pinMode(voltagePin, OUTPUT);
  digitalWrite(voltagePin, HIGH);
}

void loop() {
  // Sample code for controlling the CNC controller axes
  digitalWrite(xPin, HIGH);
  delay(1000);
  digitalWrite(xPin, LOW);
  delay(1000);
}
