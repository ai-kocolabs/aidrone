double x1 = 2, x2 = 3;
double w1 = 3, w2 = 4;
double w3 = 5, w4 = 6;
double b1 = 1, b2 = 2;
double y1T = 27, y2T = -30;

void setup() {

	Serial.begin(115200);

	double y1 = x1*w1 + x2*w2 + 1*b1;
	double y2 = x1*w3 + x2*w4 + 1*b2;
	double E = (y1-y1T)*(y1-y1T)/2+(y2-y2T)*(y2-y2T)/2; 
	double y1E = y1 - y1T;
	double y2E = y2 - y2T;
	printf("y1E : %f, y2E : %f\n", y1E, y2E);

}

void loop() {
}