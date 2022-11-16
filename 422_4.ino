#include <iostream>
#include <ArduinoEigen.h>

using namespace std;
using namespace Eigen;

IOFormat HeavyFmt(StreamPrecision, 0, ", ", ",\n", "[", "]", "[", "]");

void relu_f(MatrixXd& X) {
	X = ((X.array()>0).cast<double>()*X.array()).matrix();
}

void relu_b(MatrixXd& XE, MatrixXd& X) {
	XE = ((X.array()>0).cast<double>()*1*XE.array()).matrix();
}

void setup() {

	Serial.begin(115200);
	delay(1000);
	
	cout << fixed;
	cout.precision(3);

	MatrixXd X(1, 2);
	X << -5, 10;

	relu_f(X);
	cout << X.format(HeavyFmt) << endl;

	MatrixXd XE(1, 2);
	XE << 2, 1;

	relu_b(XE, X);
	cout << XE.format(HeavyFmt) << endl;

}

void loop() {}