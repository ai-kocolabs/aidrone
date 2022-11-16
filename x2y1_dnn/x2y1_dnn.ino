#include "dnn_display.h"

double x1 = 2, x2 = 3;
double w1 = 3, w2 = 4;
double b = 1;
double yT = 27;
double lr  = 0.01;

void dnn_test() {

  for(int epoch=0;epoch<200;epoch++) {
    
    double y = x1*w1 + x2*w2 + 1*b;
    double E = (y - yT)*(y - yT) / 2;
    double yE = y - yT;
    double w1E = yE*x1;
    double w2E = yE*x2;
    double bE = yE*1;
    w1 -= lr*w1E;
    w2 -= lr*w2E;
    b -= lr*bE;
    
    printf("epoch = %d\n", epoch);
    printf("y  = %6.3f\n", y);
    printf("w1E = %6.3f, w2E = %6.3f, bE = %6.3f\n", w1E, w2E, bE);
    printf("w1  = %6.3f, w2  = %6.3f, b  = %6.3f\n", w1, w2, b);

    if(E< 0.0000001) break;

    draw_dnn(w1,w2,b);

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
