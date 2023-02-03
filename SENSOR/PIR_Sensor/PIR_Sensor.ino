int LED = 10;             // the pin that the LED is atteched to
int UV  =11;
int PIR1=2;
int PIR2=3;              // the pin that the sensor is atteched to

void setup() {
  pinMode(LED, OUTPUT);   // initalize LED as an output
  pinMode(UV, OUTPUT);
  pinMode(PIR1, INPUT);    // initialize sensor as an input
  pinMode(PIR2, INPUT);
  Serial.begin(9600);     // initialize serial
}

void loop(){
  if (digitalRead(PIR1) == HIGH) { // check if the sensor is HIGH
    digitalWrite(LED, HIGH);      // turn LED ON 
    Serial.println("Motion detected!"); 
    delay(100);                   // delay 100 milliseconds 
  } 
  else if {
   digitalWrite(LED, LOW);       // turn LED OFF
    Serial.println("Motion stopped!");
    delay(100); 
  }
  else if{ digitalRead(PIR2) = HIGH;  
    digitalWrite(UV, HIGH);      
    Serial.println("Motion detected!"); 
    delay(100);                  
    }
  else  {
    digitalWrite(UV, LOW);       
    Serial.println("Motion stopped!");
    delay(100);                   
  }
}
