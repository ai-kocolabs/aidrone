#include "dnn_display.h"

TFT_eSPI tft = TFT_eSPI();

void drawLine_circle_to_circle(
  point& pt1, int r1, 
  point& pt2, int r2,
  double weight_now, double weight_prev) {
    int x1 = pt1.x + r1*cos(atan2(pt2.y-pt1.y, pt2.x-pt1.x));
    int y1 = pt1.y + r1*sin(atan2(pt2.y-pt1.y, pt2.x-pt1.x)); 
    int x2 = pt2.x - r2*cos(atan2(pt2.y-pt1.y, pt2.x-pt1.x));
    int y2 = pt2.y - r2*sin(atan2(pt2.y-pt1.y, pt2.x-pt1.x));

    uint16_t colorLine = TFT_RED;
    if(weight_now<0) colorLine = TFT_BLUE;

    weight_now = pow(weight_now, 2)/4;
    weight_prev = pow(weight_prev, 2)/4;

    if(abs(weight_prev)>abs(weight_now)) {
      if(abs(weight_now)>6)tft.drawLine(x1+1,y1-3,x2-1,y2-3,TFT_BLACK);
      else if(abs(weight_now)>5)tft.drawLine(x1+1,y1+3,x2-1,y2+3,TFT_BLACK);      
      else if(abs(weight_prev)>4)tft.drawLine(x1+1,y1-2,x2-1,y2-2,TFT_BLACK);
      else if(abs(weight_prev)>3)tft.drawLine(x1+1,y1+2,x2-1,y2+2,TFT_BLACK);
      else if(abs(weight_prev)>2)tft.drawLine(x1+1,y1-1,x2-1,y2-1,TFT_BLACK);
      else if(abs(weight_prev)>1)tft.drawLine(x1+1,y1+1,x2-1,y2+1,TFT_BLACK);
      else if(abs(weight_prev)>0) tft.drawLine(x1,y1,x2,y2,TFT_BLACK);
    }
    
    if(abs(weight_now)>0) tft.drawLine(x1,y1,x2,y2,colorLine);
    if(abs(weight_now)>1)tft.drawLine(x1+1,y1+1,x2-1,y2+1,colorLine);
    if(abs(weight_now)>2)tft.drawLine(x1+1,y1-1,x2-1,y2-1,colorLine);
    if(abs(weight_now)>3)tft.drawLine(x1+1,y1+2,x2-1,y2+2,colorLine);
    if(abs(weight_now)>4)tft.drawLine(x1+1,y1-2,x2-1,y2-2,colorLine);
    if(abs(weight_now)>5)tft.drawLine(x1+1,y1+3,x2-1,y2+3,colorLine);
    if(abs(weight_now)>6)tft.drawLine(x1+1,y1-3,x2-1,y2-3,colorLine);
}

void tft_setup() {
  
  tft.begin();
  tft.setRotation(3);

  tft.fillScreen(TFT_BLACK);
  
}

void drawText(point &pt, char * nodeName) {
  int x = pt.x;
  int y = pt.y;
  
  tft.setCursor(x, y);
  tft.setTextFont(1);
  tft.setTextColor(TFT_YELLOW, TFT_BLACK);
  tft.setTextSize(1);
  tft.printf("%s", nodeName);
}

void drawText(point &pt, double weight) {
  int x = pt.x;
  int y = pt.y;
  
  tft.setCursor(x, y);
  tft.setTextFont(2);
  tft.setTextColor(TFT_YELLOW, TFT_BLACK);
  tft.setTextSize(1);
  tft.printf(" %.3f ", weight);
}

void draw_dnn(
  double w1,
  double w2,
  double b) {

  static bool circleDrawn = false;
  if(!circleDrawn) {
    circleDrawn = true;    
    tft.drawCircle(10,10,10,TFT_CYAN);
    tft.drawCircle(10,40,10,TFT_CYAN);
    tft.drawCircle(10,69,10,TFT_CYAN);
    tft.drawCircle(149,40,10,TFT_CYAN);

    point pt_x1 = {5, 7};
    point pt_x2 = {5, 37};
    point pt__1 = {8, 66};
    point pt__y = {147, 36};
  
    drawText(pt_x1, "x1");
    drawText(pt_x2, "x2");
    drawText(pt__1, "1");
    drawText(pt__y, "y");
  }

  point pt_x1 = {10, 10};
  point pt_x2 = {10, 40};
  point pt__1 = {10, 69};
  point pt__y = {149, 40};

  static double w1_prev, w2_prev, b_prev;
  
  drawLine_circle_to_circle(pt_x1, 12, pt__y, 12, w1, w1_prev);
  drawLine_circle_to_circle(pt_x2, 12, pt__y, 12, w2, w2_prev);
  drawLine_circle_to_circle(pt__1, 12, pt__y, 12, b, b_prev);
  
  w1_prev = w1;
  w2_prev = w2;
  b_prev = b;

  point pt_w1 = {70, 4};
  point pt_w2 = {50, 32};
  point pt__b = {70, 60};
  drawText(pt_w1, w1);
  drawText(pt_w2, w2);
  drawText(pt__b, b);
  
}
