double x = 2; // 일반적으로 딥러닝 변수는 실수입니다.
double w = 3;
double b = 1;

void setup() {

	Serial.begin(115200);

	double y = x*w + 1*b; // 딥러닝 제 1 공식 : 순전파 
	printf("y : %f\n", y); // ESP32 아두이노는 printf 함수를 지원합니다.

}

void loop() {
}