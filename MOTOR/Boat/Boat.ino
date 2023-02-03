#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>
int MotorLeft1 = 5;
int MotorLeft2 = 6;
int MotorRight3 = 9;
int MotorRight4 = 10;

void setup() 
{
  pinMode(MotorLeft1, OUTPUT); 
  pinMode(MotorLeft2, OUTPUT);
  pinMode(MotorRight3, OUTPUT); 
  pinMode(MotorRight4, OUTPUT);
  Serial.begin(250000);    // Set your Serial Monitor is set at 250000
  Dabble.begin(9600);      // This is the baude rate of the HM-10
}

void loop() {
Dabble.processInput();  // This line is crucial in grabbing our data  
  
  if (GamePad.isUpPressed())       
  {
    Serial.println("Forward");
    digitalWrite(MotorLeft1, HIGH);
    digitalWrite(MotorLeft2, LOW);
    digitalWrite(MotorRight3, HIGH);
    digitalWrite(MotorRight4, LOW);
  }

  else if (GamePad.isLeftPressed())
  {
    Serial.println("Left");
    digitalWrite(MotorLeft1, LOW);
    digitalWrite(MotorLeft2, LOW);
    digitalWrite(MotorRight3, HIGH);
    digitalWrite(MotorRight4, LOW);
  }

  else if (GamePad.isRightPressed())
  {
    Serial.println("Right");
    digitalWrite(MotorLeft1, HIGH);
    digitalWrite(MotorLeft2, LOW);
    digitalWrite(MotorRight3, LOW);
    digitalWrite(MotorRight4, LOW);
  }
  else 
  {
    Serial.println("Stopped");
    digitalWrite(MotorLeft1, LOW);
    digitalWrite(MotorLeft2, LOW);
    digitalWrite(MotorRight3, LOW);
    digitalWrite(MotorRight4, LOW);
  }
}
