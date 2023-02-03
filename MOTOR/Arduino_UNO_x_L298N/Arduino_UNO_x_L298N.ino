int motor1pin1 = 5;
int motor1pin2 = 6;

int motor2pin1 = 9;
int motor2pin2 = 10;

void setup() {
  // put your setup code here, to run once:
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:   
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
    digitalWrite(motor2pin1, 1);
  digitalWrite(motor2pin2, 0);
  delay (10000);
 
  digitalWrite(motor2pin1, 0);
  digitalWrite(motor2pin2, 1);

  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);
   delay(10000);
  


}
