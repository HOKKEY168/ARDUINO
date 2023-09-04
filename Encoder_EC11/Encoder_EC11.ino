
/*
 *  Created on: August 30, 2023
 *  Author    : HOKKEY
 *  This is code is for read Encoder_EC11 2channel.
 *  Copyright (C) 2023 HOKKEY
 */

#define ENC_A 8
#define ENC_B 7

int counter=0;
int aState;
int aLastState;

void setup() {
  // put your setup code here, to run once:
pinMode (ENC_A, INPUT);
pinMode (ENC_B, INPUT);

Serial.begin(9600);

aLastState = digitalRead(ENC_A);
}

void loop() {
  // put your main code here, to run repeatedly:
  aState=digitalRead(ENC_A);
  if(aState != aLastState){
    if(digitalRead(ENC_B) != aState){
      counter++;

    }else{
      counter--;
    }
   Serial.print("Position: ");
   Serial.println(counter);
  }
  aLastState = aState;
}
