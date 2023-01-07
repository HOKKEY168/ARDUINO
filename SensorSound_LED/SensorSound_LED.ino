int soundsensor = 3;
int led = 7;    
void setup() {
  pinMode (soundsensor, INPUT);
  pinMode (led, OUTPUT);
}
void loop()
{
  int sensorvalue = digitalRead (soundsensor);            //if the sound intensity is higher than threshold which is set by us, 
                                                          //then sensor would return the value as 1
  if (sensorvalue == 1)                                    
  {
    digitalWrite(led, HIGH);
  }
  
  else
  {
    digitalWrite(led, LOW);
  }
  
}
