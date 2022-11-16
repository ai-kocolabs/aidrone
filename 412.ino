#include <iostream>
#include <ArduinoEigen.h>

using namespace std;
using namespace Eigen;

IOFormat HeavyFmt(StreamPrecision, 0, ", ", ",\n", "[", "]", "[", "]");

MatrixXd X(1, 2); // 입력 행렬
MatrixXd W(2, 2); // 가중치 행렬
MatrixXd B(1, 2); // 편향 행렬

void setup() {

	Serial.begin(115200);
	delay(1000);

	X << 2, 3;    
	W << 3, 5, 4, 6;    
	B << 1, 2;

	MatrixXd Y; // 행렬의 크기를 지정하지 않아도 됩니다.
	Y = X*W + B;
	cout << Y.format(HeavyFmt) << endl;

}

void loop() {}