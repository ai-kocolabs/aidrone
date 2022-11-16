double x = 2; // 일반적으로 딥러닝 변수는 실수입니다.
double w = 3;
double b = 1;
double yT = 10; // 목표값을 10이라고 가정합니다.

void setup() {

	Serial.begin(115200);

	double y = x*w + 1*b; // 딥러닝 제 1 공식 : 순전파 
	double E = (y - yT)*(y - yT) / 2; // 딥러닝 제 2 공식 : 평균 제곱 오차
	printf("E : %f\n", E);

}

void loop() {
}