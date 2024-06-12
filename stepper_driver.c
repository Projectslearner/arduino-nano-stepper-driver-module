/*
    Project name : Stepper Driver Module
    Modified Date: 12-06-2024
    Code by : Projectslearner
    Website : https://projectslearner.com/learn/arduino-nano-stepper-driver-module
*/

// Define the pins connected to the stepper driver module
const int stepPin = 2;
const int dirPin = 3;

void setup() {
  // Set the step and direction pins as outputs
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
}

void loop() {
  // Rotate the motor clockwise for 100 steps
  rotateClockwise(100);
  delay(1000); // Delay for 1 second
  
  // Rotate the motor counterclockwise for 100 steps
  rotateCounterclockwise(100);
  delay(1000); // Delay for 1 second
}

void rotateClockwise(int steps) {
  digitalWrite(dirPin, HIGH); // Set direction to clockwise
  for (int i = 0; i < steps; i++) {
    stepMotor(); // Step the motor one step
    delay(5); // Delay to control the speed of rotation
  }
}

void rotateCounterclockwise(int steps) {
  digitalWrite(dirPin, LOW); // Set direction to counterclockwise
  for (int i = 0; i < steps; i++) {
    stepMotor(); // Step the motor one step
    delay(5); // Delay to control the speed of rotation
  }
}

void stepMotor() {
  digitalWrite(stepPin, HIGH); // Trigger one step
  delayMicroseconds(500); // Delay to control the speed of rotation
  digitalWrite(stepPin, LOW); // Complete the step
  delayMicroseconds(500); // Delay to control the speed of rotation
}
