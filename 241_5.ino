double x1 = 2, x2 = 3;
double w1 = 3, w2 = 4;
double b = 1;
double yT = 27;
double lr  = 0.01;

void setup() {

	Serial.begin(115200);

	double y = x1*w1 + x2*w2 + 1*b;
	double E = (y - yT)*(y - yT) / 2; 
	double yE = y - yT;
	double w1E = yE*x1;
	double w2E = yE*x2;
	double bE = yE*1;
	w1 -= lr*w1E;
	w2 -= lr*w2E;
	b -= lr*bE;
	printf("w1 : %f, w2 : %f, b : %f\n", w1, w2, b);

}

void loop() {
}