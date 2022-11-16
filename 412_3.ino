#include <iostream>
#include <ArduinoEigen.h>

using namespace std;
using namespace Eigen;

MatrixXd X(1, 2);
MatrixXd W(2, 2);
MatrixXd B(1, 2);
MatrixXd YT(1, 2);

void setup() {

	Serial.begin(115200);
	delay(1000);

	X << 2, 3;    
	W << 3, 5, 4, 6;    
	B << 1, 2;
	YT << 27, -30;

	MatrixXd Y;
	Y = X*W + B;

	MatrixXd E;
	E = (Y - YT)*(Y - YT).transpose()/2;
	double e = E(0, 0);// E 행렬의 (0, 0)항목 값을 얻어옵니다.
	cout << e << endl;

}

void loop() {}