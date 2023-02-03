byte pin =A0;
uint16_t Val;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(3,OUTPUT);
   pinMode(4,OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  Val =analogRead(pin);
  float voltage= (Val/1023.0)*5.0;
  int pwm =map (Val,0,1023,0,255);
  analogWrite(3,pwm);
  analogWrite(4,pwm);

  Serial.print(Val);
  Serial.print("=");
  Serial.println(voltage);
  delay(100);


}
