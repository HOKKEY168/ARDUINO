void setup()
{
  for ( int x=2; x<=8;x++){
  pinMode(x, OUTPUT);
  
  }
}
int k[]={0x3f,0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x6f};
void loop()
{
  for (int z=0; z<=9;z++){
    for (int x=2;x<=8;x++){
    digitalWrite(x,bitRead(k[z],x-2));
  }
  delay(1000);
   }
}
