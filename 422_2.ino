#include <iostream>
#include <ArduinoEigen.h>

using namespace std;
using namespace Eigen;

IOFormat HeavyFmt(StreamPrecision, 0, ", ", ",\n", "[", "]", "[", "]");

void setup() {

	Serial.begin(115200);
	delay(1000);
	
	cout << fixed;
	cout.precision(3);

	MatrixXd X(1, 2);
	X << -5, 10;

	MatrixXd Xd; // X dash
	Xd = ((X.array()>0).cast<double>()*X.array()).matrix(); // relu 순전파
	cout << Xd.format(HeavyFmt) << endl;

	MatrixXd XdE(1, 2); // X dash Error
	XdE << 2, 1;

	MatrixXd XE; 
	XE = ((Xd.array()>0).cast<double>()*1*XdE.array()).matrix(); // relu 역전파
	cout << XE.format(HeavyFmt) << endl;

}

void loop() {}