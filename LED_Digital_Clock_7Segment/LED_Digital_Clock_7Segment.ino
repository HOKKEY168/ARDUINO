#include <TimeLib.h>
int digit1 = 10;
int digit2 = 11; 
int digit3 = 12; 
int digit4 = 13; 


int segA = 2; //Display pin a
int segB = 3; //Dissplay pin b
int segC = 4; //Display pin c
int segD = 5; //Display pin d
int segE = 6; //Display pin e
int segF = 7; //Display pin f
int segG = 8; //Display pin g
int segDP = 9;// Display pin dot

//input pins for push buttons
byte SW0 = A0; //Adjust button
byte SW1 = A1;
byte SW2 = A2;


void setup() {



  pinMode(segA, OUTPUT);
  pinMode(segB, OUTPUT);
  pinMode(segC, OUTPUT);
  pinMode(segD, OUTPUT);
  pinMode(segE, OUTPUT);
  pinMode(segF, OUTPUT);
  pinMode(segG, OUTPUT);
  pinMode(segDP, OUTPUT);

  pinMode(digit1, OUTPUT);
  pinMode(digit2, OUTPUT);
  pinMode(digit3, OUTPUT);
  pinMode(digit4, OUTPUT);

//  pinMode(13, OUTPUT);

 Serial.begin(9600);

  pinMode(SW0, INPUT);  
  pinMode(SW1, INPUT);  
  pinMode(SW2, INPUT);  

  digitalWrite(SW0, HIGH); 
  digitalWrite(SW1, HIGH);
  digitalWrite(SW2, HIGH);
}

void loop() {
   digitalWrite(segDP, HIGH);
   int hr = hour();
  int timp = ( (hr>12)?(hr%12):hr)*100+minute();
  Serial.println(timp);
// display parts
   for(int i = 250 ; i >0  ; i--) {
     if (timp > 100) displayNumber01(timp);
     else displayNumber02(timp);
   }

   for(int i = 250 ; i >0  ; i--) {
     if (timp > 100) displayNumber03(timp);
     else displayNumber04(timp);
   }

  if (!(digitalRead(SW0))) set_time();
}


void set_time()   {
  byte minutes1 = 0;
  byte hours1 = 0;
  byte minutes = minute();
  byte hours = hour();

  while (!digitalRead(SW0)) 
  {
    minutes1=minutes;
    hours1=hours;


    while (!digitalRead(SW1)) 
    {
     minutes++;

    if (minutes > 59) minutes = 0;
     for(int i = 20 ; i >0  ; i--) {
       int timp= hours*100+minutes;
     if (timp > 1000) displayNumber01(timp);
     else displayNumber02(timp);
     }





    delay(150);
    }

    while (!digitalRead(SW2))
    {
     hours++;

     if (hours > 12) hours = 0;

     for(int i = 20 ; i >0  ; i--) {
     int timp= hours*100+minutes;
     if (timp > 1000) displayNumber01(timp);
     else displayNumber02(timp);
     }





     delay(150);
    }



     for(int i = 20 ; i >0  ; i--) {
     displayNumber01(hours*100+minutes);
     }
     setTime(hours,minutes,0,0,0,0);
 //  delay(150);

  }

}



void displayNumber01(int toDisplay) {
#define DISPLAY_BRIGHTNESS  500
//
//#define HIGH  HIGH
//#define LOW  LOW

  for(int digit = 4 ; digit > 0 ; digit--) {

  
    switch(digit) {
    case 1:
     digitalWrite(digit1, HIGH);
     digitalWrite(segDP, LOW);
      break;
   case 2:
      digitalWrite(digit2, HIGH);
      digitalWrite(segDP, LOW);
      break;
    case 3:
      digitalWrite(digit3, HIGH);
      digitalWrite(segDP, LOW);
      break;
    case 4:
      digitalWrite(digit4, HIGH);
      digitalWrite(segDP, LOW);
      break;
    }
    lightNumber(toDisplay % 10);
    toDisplay /= 10;
    delayMicroseconds(DISPLAY_BRIGHTNESS);

  
    lightNumber(10);

    
    digitalWrite(digit1, LOW);
    digitalWrite(digit2, LOW);
    digitalWrite(digit3, LOW);
    digitalWrite(digit4, LOW);
}
}

void displayNumber02(int toDisplay) {
#define DISPLAY_BRIGHTNESS  500

//#define HIGH  HIGH
//#define LOW  LOW

  for(int digit = 4 ; digit > 0 ; digit--) {

   
    switch(digit) {
    case 1:
     lightNumber(10);
     digitalWrite(segDP, LOW);
     break;
   case 2:
      digitalWrite(digit2, HIGH);
      digitalWrite(segDP, LOW);
      break;
    case 3:
      digitalWrite(digit3, HIGH);
      digitalWrite(segDP, LOW);
      break;
    case 4:
      digitalWrite(digit4, HIGH);
      digitalWrite(segDP, LOW);
      break;
    }
    lightNumber(toDisplay % 10);
    toDisplay /= 10;
    delayMicroseconds(DISPLAY_BRIGHTNESS);

    
    lightNumber(10);

    
    digitalWrite(digit1, LOW);
    digitalWrite(digit2, LOW);
    digitalWrite(digit3, LOW);
    digitalWrite(digit4, LOW);
}
}

void displayNumber03(int toDisplay) {
#define DISPLAY_BRIGHTNESS  500

//#define HIGH  HIGH
//#define LOW  LOW

  for(int digit = 4 ; digit > 0 ; digit--) {

    
    switch(digit) {
    case 1:
     digitalWrite(digit1, HIGH);
     digitalWrite(segDP, HIGH);
      break;
   case 2:
      digitalWrite(digit2, HIGH);
      digitalWrite(segDP, HIGH);
      break;
    case 3:
      digitalWrite(digit3, HIGH);
      digitalWrite(segDP, HIGH);
      break;
    case 4:
      digitalWrite(digit4, HIGH);
      digitalWrite(segDP, HIGH);
      break;
    }
    lightNumber(toDisplay % 10);
    toDisplay /= 10;
    delayMicroseconds(DISPLAY_BRIGHTNESS);

    
    lightNumber(10);

   
    digitalWrite(digit1, LOW);
    digitalWrite(digit2, LOW);
    digitalWrite(digit3, LOW);
    digitalWrite(digit4, LOW);
}
}

void displayNumber04(int toDisplay) {
#define DISPLAY_BRIGHTNESS  500

//#define HIGH  HIGH
//#define LOW  LOW

  for(int digit = 4 ; digit > 0 ; digit--) {

    
    switch(digit) {
    case 1:
     lightNumber(10);
     digitalWrite(segDP, HIGH);
     break;
   case 2:
      digitalWrite(digit2, HIGH);
      digitalWrite(segDP, HIGH);
      break;
    case 3:
      digitalWrite(digit3, HIGH);
      digitalWrite(segDP, HIGH);
      break;
    case 4:
      digitalWrite(digit4, HIGH);
      digitalWrite(segDP, HIGH);
      break;
    }
    lightNumber(toDisplay % 10);
    toDisplay /= 10;
    delayMicroseconds(DISPLAY_BRIGHTNESS);

     //Turn off all segments
    lightNumber(10);

    //Turn off all digits
    digitalWrite(digit1, LOW);
    digitalWrite(digit2, LOW);
    digitalWrite(digit3, LOW);
    digitalWrite(digit4, LOW);
}
}

void lightNumber(int numberToDisplay) {

//#define HIGH  LOW
//#define LOW HIGH

  switch (numberToDisplay){

  case 0:
    digitalWrite(segA, HIGH);
    digitalWrite(segB, HIGH);
    digitalWrite(segC, HIGH);
    digitalWrite(segD, HIGH);
    digitalWrite(segE, HIGH);
    digitalWrite(segF, HIGH);
    digitalWrite(segG, LOW);
    break;

  case 1:
    digitalWrite(segA, LOW);
    digitalWrite(segB, HIGH);
    digitalWrite(segC, HIGH);
    digitalWrite(segD, LOW);
    digitalWrite(segE, LOW);
    digitalWrite(segF, LOW);
    digitalWrite(segG, LOW);
    break;

  case 2:
    digitalWrite(segA, HIGH);
    digitalWrite(segB, HIGH);
    digitalWrite(segC, LOW);
    digitalWrite(segD, HIGH);
    digitalWrite(segE, HIGH);
    digitalWrite(segF, LOW);
    digitalWrite(segG, HIGH);
    break;

  case 3:
    digitalWrite(segA, HIGH);
    digitalWrite(segB, HIGH);
    digitalWrite(segC, HIGH);
    digitalWrite(segD, HIGH);
    digitalWrite(segE, LOW);
    digitalWrite(segF, LOW);
    digitalWrite(segG, HIGH);
    break;

  case 4:
    digitalWrite(segA, LOW);
    digitalWrite(segB, HIGH);
    digitalWrite(segC, HIGH);
    digitalWrite(segD, LOW);
    digitalWrite(segE, LOW);
    digitalWrite(segF, HIGH);
    digitalWrite(segG, HIGH);
    break;

  case 5:
    digitalWrite(segA, HIGH);
    digitalWrite(segB, LOW);
    digitalWrite(segC, HIGH);
    digitalWrite(segD, HIGH);
    digitalWrite(segE, LOW);
    digitalWrite(segF, HIGH);
    digitalWrite(segG, HIGH);
    break;

  case 6:
    digitalWrite(segA, HIGH);
    digitalWrite(segB, LOW);
    digitalWrite(segC, HIGH);
    digitalWrite(segD, HIGH);
    digitalWrite(segE, HIGH);
    digitalWrite(segF, HIGH);
    digitalWrite(segG, HIGH);
    break;

  case 7:
    digitalWrite(segA, HIGH);
    digitalWrite(segB, HIGH);
    digitalWrite(segC, HIGH);
    digitalWrite(segD, LOW);
    digitalWrite(segE, LOW);
    digitalWrite(segF, LOW);
    digitalWrite(segG, LOW);
    break;

  case 8:
    digitalWrite(segA, HIGH);
    digitalWrite(segB, HIGH);
    digitalWrite(segC, HIGH);
    digitalWrite(segD, HIGH);
    digitalWrite(segE, HIGH);
    digitalWrite(segF, HIGH);
    digitalWrite(segG, HIGH);
    break;

  case 9:
    digitalWrite(segA, HIGH);
    digitalWrite(segB, HIGH);
    digitalWrite(segC, HIGH);
    digitalWrite(segD, HIGH);
    digitalWrite(segE, LOW);
    digitalWrite(segF, HIGH);
    digitalWrite(segG, HIGH);
    break;

      
    break;

  }
}
