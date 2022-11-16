#include <iostream>
#include <ArduinoEigen.h>

using namespace std;
using namespace Eigen;

IOFormat HeavyFmt(StreamPrecision, 0, ", ", ",\n", "[", "]", "[", "]");

void softmax_f(MatrixXd& X) {
	double XMax, sumX;
	XMax = X.maxCoeff();
	X.array() -= XMax;
	sumX = exp(X.array()).matrix().sum();
	X.array() = exp(X.array())/sumX;
}

void softmax_b(MatrixXd& XE, MatrixXd& X) {
		// do nothing
}

void setup() {

	Serial.begin(115200);
	delay(1000); 

	cout << fixed;
	cout.precision(2);

	MatrixXd X(1, 5);
	X << 1.3, 5.1, 2.2, 0.7, 1.1;

	softmax_f(X);

	cout << X.format(HeavyFmt) << endl;

}

void loop() {}