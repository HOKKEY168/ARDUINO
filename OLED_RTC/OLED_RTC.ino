//RTC with OLED:
#include <Adafruit_SSD1306.h>
#include <splash.h>
#include <DS1307.h>
Adafruit_SSD1306 myoled(13);
DS1307 myrtc (SDA,SCL);
void setup() {
  myrtc.begin();
  myoled.begin(0x3c);
  myoled.clearDisplay();
  myoled.setTextSize(2);
  myoled.setTextColor(WHITE);
  myoled.display();
}

void loop() {
  myoled.setCursor(20,10);
  myoled.print(myrtc.getTimeStr());
  myoled.setCursor(20,20);
  myoled.print(myrtc.getDateStr());
  myoled.setCursor(20,40);
  myoled.print(myrtc.getDOWStr());
  myoled.display();
  delay(1000);
  myoled.clearDisplay();
}
