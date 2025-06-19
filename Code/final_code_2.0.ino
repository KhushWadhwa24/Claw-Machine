#include <Servo.h>

/*Parameters and Constants*/

const int button1 = 11; // Move up
const int button2 = 12; // Move down
const int button3 = 13; // Claw

Servo clawservo;
int openAngle = 0;
int closeAngle = 75;

int PWM = 5;          // PWM of Motor Driver to Pin 5
int INB = 6;          // INB of Motor Driver to Pin 6
int INA = 7;          // INA of Motor Driver to Pin 7
int SER = 10;

int SPEED = 120;      // PWM value used to control speed of the motor. The value can be varied from 0 to 255

int counter = 0;

void setup() {
  // put your setup code here, to run once:

  clawservo.attach(SER);
  clawservo.write(openAngle);

  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(PWM,OUTPUT);
  pinMode(INA,OUTPUT);
  pinMode(INB,OUTPUT);

    // Direction Control Table:
    // | INA  | INB  | State   |
    // | HIGH | LOW  | Forward |
    // | LOW  | HIGH | Reverse |
    // | HIGH | HIGH | Brake   |
    // | LOW  | LOW  | Brake   |

  analogWrite(PWM, SPEED);  //Turn the motor OFF by default

  Serial.begin(9600);                                 // Initiates the serial to do the monitoring 
  Serial.println("Begin motor control");
//  Serial.println();                                   // Print function list for user selection
//  Serial.println("Enter number for control option:");
//  Serial.println("1. STOP");
//  Serial.println("2. FORWARD");
//  Serial.println("3. REVERSE");
//  Serial.println("4. OPEN CLAW");
//  Serial.println("5. CLOSE CLAW");
  Serial.println();


  Serial.println("Testing servo movement...");
  clawservo.write(openAngle);
  delay(1000);
  clawservo.write(closeAngle);
  delay(1000);
  Serial.println("Servo successfully tested");
}

void loop() {
  
  // Motor control
  if (digitalRead(button1) == HIGH) {
    Serial.println("button 1 press");
    Forward();
  } 
  else if (digitalRead(button2) == HIGH) {
    Serial.println("button 2 press");
    Reverse();
  } 
  else {
    Stop();
  }

  if (digitalRead(button3) == HIGH)
  {
    counter++;
    delay(800);
  }

  if (counter%2 == 1)
  {
    Open();
  }

  else{
    Close();
  }
}

void Stop()
{
//  Serial.println("Stop");
  digitalWrite(INA, LOW);
  digitalWrite(INB, LOW);
}

void Forward()
{
//  Serial.println("Forward");
  digitalWrite(INA, HIGH);
  digitalWrite(INB, LOW);
}

void Reverse()
{
//  Serial.println("Reverse");
  digitalWrite(INA, LOW);
  digitalWrite(INB, HIGH);
}

void Open()
{
  Serial.println("Claw Open");
  clawservo.write(openAngle);
}

void Close()
{
  Serial.println("Claw Close");
  clawservo.write(closeAngle);
}
