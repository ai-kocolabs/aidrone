#include <iostream>
#include <ArduinoEigen.h>

using namespace std;
using namespace Eigen;

IOFormat HeavyFmt(StreamPrecision, 0, ", ", ",\n", "[", "]", "[", "]");

void initialize_weight_He(MatrixXd& W) {
	W.setRandom();
	W = W*sqrt(6.0/W.rows());
}

void initialize_weight_Le(MatrixXd& W) {
	W.setRandom();
	W = W*sqrt(3.0/W.rows());
}

void setup() {

	Serial.begin(115200);
	delay(1000);
	
	cout << fixed;
	cout.precision(3);

	MatrixXd W(2,2);

	initialize_weight_He(W);
	cout << W.format(HeavyFmt) << endl;
	initialize_weight_Le(W);
	cout << W.format(HeavyFmt) << endl; 

}

void loop() {}