#include <iostream>
#include <ArduinoEigen.h>

using namespace std;
using namespace Eigen;

IOFormat HeavyFmt(StreamPrecision, 0, ", ", ",\n", "[", "]", "[", "]");

void relu_f(MatrixXd& X) {
	X = ((X.array()>0).cast<double>()*X.array()).matrix();
}

void relu_b(MatrixXd& XE, MatrixXd& X) {
	XE = ((X.array()>0).cast<double>()*1*XE.array()).matrix();
}

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

void initialize_weight_He(MatrixXd& W) {
  W.setRandom();
  W = W*sqrt(6.0/W.rows());
}


void initialize_weight_Le(MatrixXd& W) {
  W.setRandom();
  W = W*sqrt(3.0/W.rows());
}
 
MatrixXd X(1, 2), H, Y, YT(1, 2);
MatrixXd WH(2, 2), BH(1, 2);
MatrixXd WY(2, 2), BY(1, 2);

double e;
MatrixXd YE, HE;
MatrixXd WYE, BYE;
MatrixXd WHE, BHE;
double lr = 0.01;

void dnn_test() {

	X << 0.05, 0.10;    
	initialize_weight_He(WH);
	BH.setZero();
	initialize_weight_Le(WY);
	BY.setZero();
	YT << 0, 1; // 크로스 엔트로피는 하나의 목표 값만 1, 나머지는 0

	cout << fixed;
	cout.precision(3);

	for(int epoch=0;epoch<10000;epoch++) {        

		relu_f(H = X*WH + BH);
		softmax_f(Y = H*WY + BY);
		
		e = -(YT.array()*log(Y.array())).matrix().sum();
		
		softmax_b(YE = Y - YT, Y);
		relu_b(HE = YE*WY.transpose(), H);
		
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