double x1 = 2, x2 = 3;
double w1 = 3, w2 = 4;
double w3 = 5, w4 = 6;
double b1 = 1, b2 = 2;

void setup() {

	Serial.begin(115200);

	double y1 = x1*w1 + x2*w2 + 1*b1; 
	double y2 = x1*w3 + x2*w4 + 1*b2;
	printf("y1 : %f, y2 : %f\n", y1, y2);

}

void loop() {
}