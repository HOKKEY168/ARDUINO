byte button=7;
byte LED=8;
byte pre_state=1;
byte cur_state=1;
byte state=0;
void setup()
{
  pinMode(LED,OUTPUT);
  pinMode(button,INPUT);
}

 

void loop()
{
    cur_state = digitalRead(button);

//    if(cur_state==1){
//      digitalWrite(LED,HIGH);
//    
//    }
//    else {
//      digitalWrite(LED,LOW);
//    }
  if ( cur_state == 0 && pre_state == 1){
    delay(100);
    digitalWrite(LED,state);
    pre_state = cur_state;
    state=!state;
  }
  if ( cur_state==1 && pre_state==0){
    delay(50);
    pre_state = cur_state;
    
  }
}
// this is the reference code
