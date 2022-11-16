double x1 = 2, x2 = 3;
double w1 = 3, w2 = 4;
double b = 1;
double yT = 27;

void setup() {

	Serial.begin(115200);

	double y = x1*w1 + x2*w2 + 1*b;
	double E = (y - yT)*(y - yT) / 2; 
	double yE = y - yT; 
	printf("yE : %f\n", yE);

}

void loop() {
}