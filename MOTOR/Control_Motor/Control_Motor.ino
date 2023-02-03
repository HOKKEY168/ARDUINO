void setup() {
  // put your setup code here, to run once:
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
analogWrite(5,100);
analogWrite(6,0);
analogWrite(9,100);
analogWrite(10,0);
}
