#include "myplot.h"

TFT_eSPI tft = TFT_eSPI();

void lcdSetup() {  
  tft.begin();
  tft.setRotation(3);
}

void lcdClear(uint32_t color) {
  tft.fillScreen(color);
}

double xs_min = 1000, xs_max = -1000;
double ys_min = 1000, ys_max = -1000;

void lcdSetPlotArea(double xs[], double ys[], int howMany) {
  for(int n=0;n<howMany;n++) {
    if(xs[n]<xs_min) xs_min = xs[n];
    else if(xs[n]>xs_max) xs_max = xs[n];
    
    if(ys[n]<ys_min) ys_min = ys[n];
    else if(ys[n]>ys_max) ys_max = ys[n];
  }
}

void lcdPlot(double xs[], double ys[], uint32_t color, int howMany) {

  uint8_t * dx = (uint8_t *)malloc(howMany*sizeof(uint8_t));
  uint8_t * dy = (uint8_t *)malloc(howMany*sizeof(uint8_t));

  for(int n=0;n<howMany;n++) {
    dx[n] = DX_MIN + (DX_MAX-DX_MIN)*(xs[n]-xs_min)/(xs_max-xs_min);
    dy[n] = DY_MIN + (DY_MAX-DY_MIN)*(ys[n]-ys_min)/(ys_max-ys_min);
  }

  for(int n=0;n<howMany;n++) {
    tft.drawPixel(dx[n], dy[n], color);
  }
    
}
