#include <gfxfont.h>
#include <Adafruit_GFX.h>

#include <Adafruit_SSD1306.h>
#include <splash.h>

Adafruit_SSD1306 myoled(13);
void setup() {
  // put your setup code here, to run once:
//myoled.begin(0x3c);
//myoled.clearDisplay();
//myoled.drawPixel(64,32,WHITE);
//myoled.drawLine(100,10,100,50,WHITE);
//myoled.drawCircle(64,32,15,WHITE);
//myoled.fillRect(15,10,105,45,WHITE);
//myooled.drawRoundRect(20,15,100,50,,5,BLACK);
//myoled.display();
//delay(5000);
//myoled.clearDisplay();
myoled.drawTriangle(10,15,100,20,90,50,WHITE);
myoled.setTextSize(2);
myoled.setTextColor(WHITE);
myoled.setCursor(20,30);
myoled.print("HH:MM:SS");
myoled.display();


}

void loop() {
  // put your main code here, to run repeatedly:

}
