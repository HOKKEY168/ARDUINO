  int LED1= 13;
  int LED2= 12;
  int LED3= 11;
  
void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
    

}

void loop() {
  digitalWrite(LED1, HIGH);  // turn on LED1
  delay(300);               // wait for 300ms
  digitalWrite(LED2, HIGH); // turn on LED2
  delay(300);               // wait for 300ms
  digitalWrite(LED3, HIGH); // turn on LED3
  delay(300);               // wait for 300ms
  digitalWrite(LED1, LOW);  // turn on LED1
  delay(400);               // wait for 400ms
  digitalWrite(LED2, LOW);  // turn on LED2
  delay(400);               // wait for 400ms
  digitalWrite(LED3, LOW);  // turn on LED3
  delay(400);               // wait for 400ms befor runing program all over again
}
