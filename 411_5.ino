#include <iostream>
#include <ArduinoEigen.h>

using namespace std;
using namespace Eigen;

MatrixXd A(1, 2); // 1x2 행렬 A
MatrixXd B(2, 2); // 2x2 행렬 B

IOFormat HeavyFmt(StreamPrecision, 0, ", ", ",\n", "[", "]", "[", "]");

void setup() {

	Serial.begin(115200);
	delay(1000);

	A << 1, 2;
	B << 1, 2, 3, 4;

	cout << A.format(HeavyFmt) << endl;
	cout << A.transpose().format(HeavyFmt) << endl; // 1x2 행렬의 전치=>2x1
	cout << B.format(HeavyFmt) << endl;
	cout << B.transpose().format(HeavyFmt) << endl; // 2x2 행렬의 전치=>2x2

}

void loop() {}