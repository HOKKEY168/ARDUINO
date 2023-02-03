
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>
int Motor_Right1 = 5;
int Motor_Right2 = 6;
int Motor_Right3 = 9;
int Motor_Right4 = 10;

void setup() 
{
  pinMode(Motor_Right1, OUTPUT); 
  pinMode(Motor_Right2, OUTPUT);
  pinMode(Motor_Right3, OUTPUT); 
  pinMode(Motor_Right4, OUTPUT);
  Serial.begin(250000);    // Set your Serial Monitor is set at 250000
  Dabble.begin(9600);      // This is the baude rate of the HM-10
}

void loop() {
Dabble.processInput();  // This line is crucial in grabbing our data  
  
  if (GamePad.isUpPressed())       
  {
    Serial.println("Forward");
    digitalWrite(Motor_Right1, LOW);
    digitalWrite(Motor_Right2, HIGH);
    digitalWrite(Motor_Right3, LOW);
    digitalWrite(Motor_Right4, HIGH);
  }

  else if (GamePad.isDownPressed())
  {
    Serial.println("Backward");
    
    digitalWrite(Motor_Right1, HIGH);
    digitalWrite(Motor_Right2, LOW);
    digitalWrite(Motor_Right3, HIGH);
    digitalWrite(Motor_Right4, LOW);
  }

  else if (GamePad.isLeftPressed())
  {
    Serial.println("Left");
 
    digitalWrite(Motor_Right1, LOW);
    digitalWrite(Motor_Right2, HIGH);
    digitalWrite(Motor_Right3, HIGH);
    digitalWrite(Motor_Right4, LOW);
  }

  else if (GamePad.isRightPressed())
  {
    Serial.println("Right");
 
    digitalWrite(Motor_Right1, HIGH);
    digitalWrite(Motor_Right2, LOW);
    digitalWrite(Motor_Right3, LOW);
    digitalWrite(Motor_Right4, HIGH);
  }
  else 
  {
    Serial.println("Stopped");
    
    digitalWrite(Motor_Right1, LOW);
    digitalWrite(Motor_Right2, LOW);
    digitalWrite(Motor_Right3, LOW);
    digitalWrite(Motor_Right4, LOW);
  }
}
