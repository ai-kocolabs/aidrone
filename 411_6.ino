#include <iostream>
#include <ArduinoEigen.h>

using namespace std;
using namespace Eigen;

MatrixXd A(1, 2);

IOFormat HeavyFmt(StreamPrecision, 0, ", ", ",\n", "[", "]", "[", "]");

void setup() {

	Serial.begin(115200);
	delay(1000);

	A << 1, 2;

	cout << A.format(HeavyFmt) << endl;
	cout << A.transpose().format(HeavyFmt) << endl;
	cout << (A*A.transpose()).format(HeavyFmt) << endl;

}

void loop() {}