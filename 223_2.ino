#include <SPI.h>
#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();

void setup() {
  
	tft.begin();
	tft.setRotation(3);

	tft.fillScreen(TFT_BLACK);

	tft.fillRect(4,4,56,56,TFT_BLUE);
	tft.drawFastVLine(18,16,44,TFT_BLACK);
	tft.drawFastVLine(32,4,44,TFT_BLACK);
	tft.drawFastVLine(46,16,44,TFT_BLACK);
	tft.fillRect(52,48,4,8,TFT_BLACK);

	tft.setCursor(73, 10);
	tft.setTextFont(2);
	tft.setTextSize(1);
	tft.setTextColor(TFT_BLUE);
	tft.println("MicroPython");
	tft.setCursor(73, 25);
	tft.println("ST7735");
	tft.setCursor(73, 40);
	tft.println("LCD 80x160");
  
}

void loop() {

}