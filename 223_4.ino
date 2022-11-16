#include <SPI.h>
#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();

void setup() {
  
	tft.begin();
	tft.setRotation(3);

	tft.fillScreen(TFT_BLACK);

	for(int y=0;y<10;y++) {
		for(int x=0;x<10;x++) {
			tft.drawPixel(x, y, TFT_RED);
		}
	}

	for(int y=70;y<80;y++) {
		for(int x=0;x<10;x++) {
			tft.drawPixel(x, y, TFT_GREEN);
		}
	}

	for(int y=70;y<80;y++) {
		for(int x=150;x<160;x++) {
			tft.drawPixel(x, y, TFT_BLUE);
		}
	}

	for(int y=0;y<10;y++) {
		for(int x=150;x<160;x++) {
			tft.drawPixel(x, y, TFT_YELLOW);
		}
	}
  
}

void loop() {

}