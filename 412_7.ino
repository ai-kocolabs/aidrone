#include <iostream>
#include <ArduinoEigen.h>

using namespace std;
using namespace Eigen;

IOFormat HeavyFmt(StreamPrecision, 0, ", ", ",\n", "[", "]", "[", "]");

MatrixXd X(1, 2);
MatrixXd W(2, 2);
MatrixXd B(1, 2);
MatrixXd YT(1, 2);

MatrixXd Y;
MatrixXd E;
double e;
MatrixXd YE;
MatrixXd WE;
MatrixXd BE;
double lr = 0.01;

void dnn_test() {

	X << 2, 3;    
	W << 3, 5, 4, 6;    
	B << 1, 2;
	YT << 27, -30;
	
	cout << fixed; // 소수점을 고정시켜 출력
	cout.precision(3); // 소수점 이하 3자리 출력

	for(int epoch=0;epoch<200;epoch++) {

		Y = X*W + B; // 순전파
		E = (Y - YT)*(Y - YT).transpose()/2; // 오차 계산
		e = E(0, 0);
		YE = Y - YT; // 역전파 오차
		WE = X.transpose()*YE; // 가중치 역전파
		BE = 1*YE; // 편향 역전파
		W -= lr*WE; // 가중치 학습
		B -= lr*BE; // 편향 학습

		cout << "epoch = " << epoch << endl;
		cout << Y.format(HeavyFmt) << endl;
		cout << WE.format(HeavyFmt) << endl;
		cout << BE.format(HeavyFmt) << endl;
		cout << W.format(HeavyFmt) << endl;
		cout << B.format(HeavyFmt) << endl;

		if(e<0.0000001) break;
		
	}

}

void setup() {
	
	Serial.begin(115200);
	delay(1000);

	dnn_test();
}

void loop() {}