double x1 = 2, x2 = 3;
double w1 = 3, w2 = 4;
double w3 = 5, w4 = 6;
double b1 = 1, b2 = 2;
double y1T = 27, y2T = -30;
double lr  = 0.01;

void dnn_test() {

  for(int epoch=0;epoch<200;epoch++) {
    
	double y1 = x1*w1 + x2*w2 + 1*b1;
	double y2 = x1*w3 + x2*w4 + 1*b2;
	double E = (y1-y1T)*(y1-y1T)/2 + (y2-y2T)*(y2-y2T)/2;
	double y1E = y1 - y1T;
	double y2E = y2 - y2T;
	double w1E = y1E*x1;
	double w2E = y1E*x2;
	double b1E = y1E*1;
	double w3E = y2E*x1;
	double w4E = y2E*x2;
	double b2E = y2E*1;
	w1 -= lr*w1E;
	w2 -= lr*w2E;
	b1 -= lr*b1E;
	w3 -= lr*w3E;
	w4 -= lr*w4E;
	b2 -= lr*b2E;

	printf("epoch = %d\n", epoch);
	printf("y1  = %6.3f, y2  = %6.3f\n", y1, y2);
	printf("w1E = %6.3f, w2E = %6.3f, b1E = %6.3f\n", w1E, w2E, b1E);
	printf("w3E = %6.3f, w4E = %6.3f, b2E = %6.3f\n", w3E, w4E, b2E);
	printf("w1  = %6.3f, w2  = %6.3f, b1  = %6.3f\n", w1, w2, b1);
	printf("w3  = %6.3f, w4  = %6.3f, b2  = %6.3f\n", w3, w4, b2);

	if(E< 0.0000001) break;
    
  }

} 

void setup() {

	Serial.begin(115200);
	delay(1000);

	dnn_test();
  
}

void loop() {

}