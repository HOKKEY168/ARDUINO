void setup()
{
  for ( int x=2; x<=8;x++){
  pinMode(x, OUTPUT);
  
  }
}

void loop()
{
  int k=b0111000; //number 0
  for (int x=2;x<=8;x++){
    digitalWrite(x,bitRead(k,x-2);
  }
 delay (1000);
   k=b0000110; //number1
   for (int x=2;x<=8;x++){
    digitalWrite(x,bitRead(k,x-2);
   }
 delay (1000);
   k=b1011011; //number2
   for (int x=2;x<=8;x++){
    digitalWrite(x,bitRead(k,x-2);
   }
 delay (1000);
   k=b1001111; //number3
   for (int x=2;x<=8;x++){
    digitalWrite(x,bitRead(k,x-2);
   }
 delay (1000);
   k=b1100110; //number4
   for (int x=2;x<=8;x++){
    digitalWrite(x,bitRead(k,x-2);
   }
 
