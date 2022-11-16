#include <iostream>
#include <ArduinoEigen.h>

using namespace std;
using namespace Eigen;

IOFormat HeavyFmt(StreamPrecision, 0, ", ", ",\n", "[", "]", "[", "]");

void setup() {

	Serial.begin(115200);
	delay(1000);
	
	cout << fixed;
	cout.precision(2); // 소수점 이하 2자리 출력

	MatrixXd Y(1, 5); // 그림에서 Y 행렬
	Y << 1.3, 5.1, 2.2, 0.7, 1.1; // 그림에서 Y 행렬의 값

	cout << exp(Y.array()).format(HeavyFmt) << endl;

	double sumY = exp(Y.array()).matrix().sum(); // 전체 항목 값 더하기
	cout << sumY << endl;

	Y.array() = exp(Y.array())/sumY; // 각 항목을 전체 항목 값의 합으로 나누기
	cout << Y.format(HeavyFmt) << endl;  

}

void loop() {}