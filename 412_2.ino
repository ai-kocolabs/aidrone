#include <iostream>
#include <ArduinoEigen.h>

using namespace std;
using namespace Eigen;

IOFormat HeavyFmt(StreamPrecision, 0, ", ", ",\n", "[", "]", "[", "]");

MatrixXd X(1, 2);
MatrixXd W(2, 2);
MatrixXd B(1, 2);
MatrixXd YT(1, 2); // 목표 행렬 YT

void setup() {

	Serial.begin(115200);
	delay(1000);

	X << 2, 3;    
	W << 3, 5, 4, 6;    
	B << 1, 2;
	YT << 27, -30;

	MatrixXd Y;
	Y = X*W + B;

	cout << (Y - YT).format(HeavyFmt) << endl; 
	cout << (Y - YT).transpose().format(HeavyFmt) << endl; 
	cout << ((Y - YT)*(Y - YT).transpose()).format(HeavyFmt) << endl;
	cout << ((Y - YT)*(Y - YT).transpose()/2).format(HeavyFmt) << endl;

}

void loop() {}