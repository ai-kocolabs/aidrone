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

	MatrixXd W(2,2);
	W.setRandom(); // -1~1사이에서 uniform random number 생성

	cout << W.format(HeavyFmt) << endl;
	cout << (W*sqrt(6.0/W.rows())).format(HeavyFmt) << endl; //He 초기화
	cout << (W*sqrt(3.0/W.rows())).format(HeavyFmt) << endl; //Lecun 초기화

}

void loop() {}