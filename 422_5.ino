#include <iostream>
#include <ArduinoEigen.h>

using namespace std;
using namespace Eigen;

IOFormat HeavyFmt(StreamPrecision, 0, ", ", ",\n", "[", "]", "[", "]");

void sigmoid_f(MatrixXd& X) {
	X = (1/(1+exp(-X.array()))).matrix();
}

void sigmoid_b(MatrixXd& XE, MatrixXd& X) {
	XE = (X.array()*(1-X.array())*XE.array()).matrix();
}

MatrixXd X(1, 2), H, Y, YT(1, 2);
MatrixXd WH(2, 2), BH(1, 2);
MatrixXd WY(2, 2), BY(1, 2);

MatrixXd E;
double e;
MatrixXd YE, HE;
MatrixXd WYE, BYE;
MatrixXd WHE, BHE;
double lr = 0.01;

void dnn_test() {

	X << 0.05, 0.10;    
	WH << 0.15, 0.25, 0.20, 0.30;    
	BH << 0.35, 0.35;    
	WY << 0.40, 0.50, 0.45, 0.55;
	BY << 0.60, 0.60;
	YT << 0.01, 0.99;

	cout << fixed;
	cout.precision(3);

	for(int epoch=0;epoch<10000;epoch++) {        

		sigmoid_f(H = X*WH + BH);
		sigmoid_f(Y = H*WY + BY);
		
		E = (Y - YT)*(Y - YT).transpose()/2;
		e = E(0, 0);
		
		sigmoid_b(YE = Y - YT, Y);
		sigmoid_b(HE = YE*WY.transpose(), H);
		
		WYE = H.transpose()*YE;
		BYE = 1*YE;		
		WHE = X.transpose()*HE;
		BHE = 1*HE;
		
		WY -= lr*WYE;
		BY -= lr*BYE;
		WH -= lr*WHE;
		BH -= lr*BHE;

		cout << "epoch = " << epoch << endl;
		cout << Y.format(HeavyFmt) << endl;

		if(e<0.0000001) break;

	}
  
}

void setup() {
  
	Serial.begin(115200);
	delay(1000);

	dnn_test();

}

void loop() {}