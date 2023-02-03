int ledRed=3;
int ledGreen=4;
int ledBlue=5;
void setup() {
  // put your setup code here, to run once:
  for(int i=3; i<=5; i++){
pinMode(i, OUTPUT);
  }
}

void loop() {
  setColor(255, 255, 0);
}
void setColor(byte R, byte G, byte B){
  
analogWrite(ledRed, R);
analogWrite(ledGreen, G);
analogWrite(ledBlue, B);
}
