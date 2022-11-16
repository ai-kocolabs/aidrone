#include <iostream>
#include <ArduinoEigen.h>

using namespace std;
using namespace Eigen;

IOFormat HeavyFmt(StreamPrecision, 0, ", ", ",\n", "[", "]", "[", "]");

void setup() {

	Serial.begin(115200);
	delay(1000); 

	cout << fixed;
	cout.precision(2); // 소수점 이하 2자리 출력

	MatrixXd Y(1, 5), YT(1, 5);
	Y << 0.02, 0.90, 0.05, 0.01, 0.02;
	YT << 0, 1, 0, 0, 0; // 크로스 엔트로피는 하나의 목표 값만 1, 나머지는 0

	cout << (YT.array()*log(Y.array())).format(HeavyFmt) << endl;
	cout << -(YT.array()*log(Y.array())).matrix().sum() << endl;

}

void loop() {}