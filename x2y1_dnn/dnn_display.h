#ifndef _DNN_DISPLAY_H_
#define _DNN_DISPLAY_H_

#include <SPI.h>
#include <TFT_eSPI.h>
#include <math.h>

struct point {
  int x;
  int y;
};

void drawLine_circle_to_circle(
  point& pt1, int r1, 
  point& pt2, int r2,
  double weight_now, double weight_prev);
void tft_setup();
void draw_dnn(
  double w1,
  double w2,
  double b);

#endif//_DNN_DISPLAY_H_
