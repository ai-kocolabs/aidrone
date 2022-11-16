#include <SPI.h>
#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();

void setup() {
  
	tft.begin();
	tft.setRotation(3);

	tft.fillScreen(TFT_BLACK);

	for(int y=0;y<80;y++) {
		for(int x=0;x<160;x++) {
			tft.drawPixel(x, y, TFT_GREEN);
			delay(1);
		}
	}
  
}

void loop() {

}