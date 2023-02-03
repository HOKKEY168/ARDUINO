  #include <Servo.h> //accesses the Arduino Servo Library

Servo myservo;  // creates servo object to control a servo

int val;    // variable to read the value from the analog pin

void setup()
{
  myservo.attach(7);  // ensures output to servo on pin 9
}

void loop() 
{ 

 
  val = analogRead(1);            // reads the value of the potentiometer from A1 (value between 0 and 1023) 
  val = map(val, 0, 1023, 0,180);     // converts reading from potentiometer to an output value in degrees of rotation that the servo can understand 
  myservo.write(val);                  // sets the servo position according to the input from the potentiometer 
                             // waits 15ms for the servo to get to set position  
} 
