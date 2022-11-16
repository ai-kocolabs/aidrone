#include <SPI.h>
#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();

void setup() {
  
	tft.begin();
	tft.setRotation(3);

	tft.fillScreen(TFT_BLACK);

	tft.drawLine(0,0,159,79,TFT_RED);
	tft.drawFastHLine(0,40,159,TFT_BLUE);
	tft.drawRect(10,50,20,10,TFT_GREEN);
	tft.drawCircle(70,60,10,TFT_CYAN);
	tft.fillCircle(100,20,10,TFT_PURPLE);
  
}

void loop() {

}