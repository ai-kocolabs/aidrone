#include <iostream>
#include <ArduinoEigen.h>

using namespace std;
using namespace Eigen;

MatrixXd A(2, 2);
MatrixXd B(1, 2);
MatrixXd C(2, 1);

void setup() {

	Serial.begin(115200);
	delay(1000);

	A << 1, 2, 3, 4;
	B << 1, 2;
	C << 1, 2;

	cout << A.rows() << "x" << A.cols() << endl; // A 행렬의 행과 열을 출력
	cout << B.rows() << "x" << B.cols() << endl; // B 행렬의 행과 열을 출력
	cout << C.rows() << "x" << C.cols() << endl; // C 행렬의 행과 열을 출

}

void loop() {}