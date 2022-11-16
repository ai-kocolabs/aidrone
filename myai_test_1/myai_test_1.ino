#include "myplot.h"

const long RANDMAX = 2147483647;

const int NUM_SAMPLES = 1000;
const double MIN_X = -2;
const double MAX_X = 0.5;

double xs[NUM_SAMPLES];
double ys[NUM_SAMPLES];

double f(double x) {
  return 2*x*x + 3*x + 5;
}

void setup() {
  
  Serial.begin(115200);
  lcdSetup();
  
  randomSeed(time(NULL));

  for(int n=0;n<NUM_SAMPLES;n++) {
    xs[n] = (double)random(RANDMAX)/RANDMAX*(MAX_X - MIN_X)+MIN_X;
    if(n<5) Serial.println(xs[n]);
  }

  for(int n=0;n<NUM_SAMPLES;n++) {
    ys[n] = f(xs[n]);
    if(n<5) Serial.println(ys[n]);
  }

  lcdSetPlotArea(xs, ys, NUM_SAMPLES);

  lcdClear(TFT_BLACK);
  lcdPlot(xs, ys, TFT_GREEN, NUM_SAMPLES);
  
}

void loop() {
  
}
