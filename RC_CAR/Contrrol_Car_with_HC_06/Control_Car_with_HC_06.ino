/**
  ******************************************************************************
  * @file           : main.ino
  * @brief          : Main program body for Arduino
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2021 HOKKEY.
  * All rights reserved.
  *
  * This code thia used to control RC CAR with bluetooth HC-06 via RC Remote App
  *
  ******************************************************************************
  */
char cmd;
void setup() {
// put your setup code here, to run once:
Serial.begin(9600);  
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
}
void loop() {
while(Serial.available()>0){
cmd = Serial.read();
Serial.println(cmd);
    //Change pin mode only if new cmd is different from previous.   
    //Serial.println(cmd);
    switch(cmd){
    case 'F':  
      analogWrite(6,0);
      analogWrite(5,255); // go forward 
      analogWrite(9,255);
      analogWrite(10,0);
      break;
    case 'B':  
       analogWrite(6,255);
       analogWrite(5,0); // go backward 
       analogWrite(9,0);
       analogWrite(10,255);
      break;
    case 'L':  
      analogWrite(6,0);
      analogWrite(5,255); // turn left
      analogWrite(9,0);
      analogWrite(10,255);
      break;
    case 'R':
      analogWrite(6,255);
      analogWrite(5,0); // turn right
      analogWrite(9,255);
      analogWrite(10,0);
      break;
    case 'S':
      analogWrite(6,0);
      analogWrite(5,0); // turn left
      analogWrite(9,0);
      analogWrite(10,0); 
    }
  } 
}
