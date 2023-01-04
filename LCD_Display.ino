
const int RS = 2;
const int RW = 3;
const int EN = 4;
const int D0 = 5;
const int D1 = 6;
const int D2 = 7;
const int D3 = 8;
const int D4 = 9;
const int D5 = 10;
const int D6 = 11;
const int D7 = 12;
 
void setup()
{
  // wait for serial port
  Serial.begin(115200);
 
  // instantiate objects
  manager = new OzIDManager;
  manager->_sendACK = true;
  manager->_checksum = true;
   
  OzCommunication::setIDManager(manager);
   
  lcdController = new OzLcdController(RS, RW, EN, D0, D1, D2, D3, D4, D5, D6, D7);
 
  // welcome devices
  int x = 1;
  manager->sendLinkSetup();
  manager->PrintWelcomeLine(lcdController, x++, "MyLCD");
  lcdController->LoginDisplaySize(16, 2);
}
 
void loop()
{
  OzCommunication::communicate();
}
