int led =6;
int brightness=0;
int fadeAmount=5;
void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  
}
void loop() {
  // put your main code here, to run repeatedly:
analogWrite(6,brightness);
brightness=brightness+fadeAmount;
if (brightness>=255 || brightness<=0){
 fadeAmount=-fadeAmount;
}
delay(50);
}
