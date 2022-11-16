#include <iostream>
#include <ArduinoEigen.h>

using namespace std;
using namespace Eigen;

MatrixXd A(1, 2); // 1x2 행렬 A
MatrixXd B(2, 2); // 2x2 행렬 B
MatrixXd C(2, 1); // 2x1 행렬 C
MatrixXd D(1, 2); // 1x2 행렬 D

IOFormat HeavyFmt(StreamPrecision, 0, ", ", ",\n", "[", "]", "[", "]");

void setup() {

	Serial.begin(115200);
	delay(1000);

	A << 1, 2;
	B << 3, 4, 5, 6;
	C << 1, 2;
	D << 3, 4;

	cout << (A*B).format(HeavyFmt) << endl; // 1x2 행렬과 2x2 행렬의 곱셈
	cout << (C*D).format(HeavyFmt) << endl; // 2x1 행렬과 1x2 행렬의 곱셈
	cout << (A*C).format(HeavyFmt) << endl; // 1x2 행렬과 2x1 행렬의 곱셈

}

void loop() {}