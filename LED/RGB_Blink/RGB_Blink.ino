byte R=5, G=6, B=3;
void setup() {
  // put your setup code here, to run once:

pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(3,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
mixColor(200,235,255);
}
void mixColor(uint8_t red,uint8_t green,uint8_t blue){
  analogWrite(R,red);
  analogWrite(G,green);
  analogWrite(B,blue);
}
