#include "dnn_display.h"

double x = 2;
double w = 3;
double b = 1;
double yT = 10;
double lr  = 0.01;

void dnn_test() {

  for(int epoch=0;epoch<200;epoch++) {

    double y = x*w + 1*b;
    double E = (y - yT)*(y - yT) / 2;
    double yE = y - yT;
    double wE = yE*x;
    double bE = yE*1;
    w -= lr*wE;
    b -= lr*bE;

    printf("epoch = %d\n", epoch);
    printf("y  = %6.3f\n", y);
    printf("wE = %6.3f, bE = %6.3f\n", wE, bE);
    printf("w  = %6.3f, b  = %6.3f\n", w, b);
    
    if(E< 0.0000001) break;

    draw_dnn(w,b);

    delay(100);
    
  }

} 

void setup() {

  tft_setup();
  
  Serial.begin(115200);
  delay(1000);
  
  dnn_test();
  
}

void loop() {

}
