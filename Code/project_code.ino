#include <Servo.h>

// Pin definitions
const int button1 = 2; // Move up
const int button2 = 3; // Move down
const int button3 = 4; // Close claw
const int button4 = 5; // Open claw
const int motorPin1 = 6; // Motor control 1
const int motorPin2 = 7; // Motor control 2
const int servoPin = 9; // Servo motor

Servo clawServo;
const int openAngle = 0;



const int closeAngle = 90;

void setup() {
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  
  clawServo.attach(servoPin);
  clawServo.write(openAngle); // Initialize claw as open
}

void loop() {
  // Motor control
  if (digitalRead(button1) == LOW) {
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
  } 
  else if (digitalRead(button2) == LOW) {
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
  } 
  else {
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
  }

  // Claw control
  if (digitalRead(button3) == LOW) {
    clawServo.write(closeAngle);
  } 
  else if (digitalRead(button4) == LOW) {
    clawServo.write(openAngle);
  }
}

}

void loop() {
  // put your main code here, to run repeatedly:

}
