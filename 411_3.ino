#include <iostream>
#include <ArduinoEigen.h>

using namespace std;
using namespace Eigen;

MatrixXd A(1, 2); // 1x2 행렬 A
MatrixXd B(1, 2); // 1x2 행렬 B
MatrixXd C(2, 2); // 2x2 행렬 C
MatrixXd D(2, 2); // 2x2 행렬 D

IOFormat HeavyFmt(StreamPrecision, 0, ", ", ",\n", "[", "]", "[", "]");

void setup() {

	Serial.begin(115200);
	delay(1000);

	A << 1, 2;
	B << 3, 4;
	C << 1, 2, 3, 4;
	D << 5, 6, 7, 8;

	cout << (A + B).format(HeavyFmt) << endl; // 1x2 행렬 A와 B의 합
	cout << (A - B).format(HeavyFmt) << endl; // 1x2 행렬 A와 B의 차
	cout << (C + D).format(HeavyFmt) << endl; // 2x2 행렬 C와 D의 합
	cout << (C - D).format(HeavyFmt) << endl; // 2x2 행렬 C와 D의 차
	cout << (2*C).format(HeavyFmt) << endl; // 스칼라 값 2와 2x2 행렬 C의 곱

}

void loop() {}