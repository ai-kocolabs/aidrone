#include <iostream>
#include <ArduinoEigen.h>

using namespace std;
using namespace Eigen;

IOFormat HeavyFmt(StreamPrecision, 0, ", ", ",\n", "[", "]", "[", "]");

const int NUM_PATTERN = 10;
const int NUM_X = 7;
const int NUM_H = 8;
const int NUM_Y = 4;

double xs[NUM_PATTERN][NUM_X] = {
	{ 1, 1, 1, 1, 1, 1, 0 },  // 0
	{ 0, 1, 1, 0, 0, 0, 0 },  // 1
	{ 1, 1, 0, 1, 1, 0, 1 },  // 2
	{ 1, 1, 1, 1, 0, 0, 1 },  // 3
	{ 0, 1, 1, 0, 0, 1, 1 },  // 4
	{ 1, 0, 1, 1, 0, 1, 1 },  // 5
	{ 0, 0, 1, 1, 1, 1, 1 },  // 6
	{ 1, 1, 1, 0, 0, 0, 0 },  // 7 
	{ 1, 1, 1, 1, 1, 1, 1 },  // 8
	{ 1, 1, 1, 0, 0, 1, 1 }   // 9
};
double yts[NUM_PATTERN][NUM_Y] = {
	{ 0, 0, 0, 0 },  
	{ 0, 0, 0, 1 }, 
	{ 0, 0, 1, 0 }, 
	{ 0, 0, 1, 1 }, 
	{ 0, 1, 0, 0 }, 
	{ 0, 1, 0, 1 }, 
	{ 0, 1, 1, 0 }, 
	{ 0, 1, 1, 1 }, 
	{ 1, 0, 0, 0 }, 
	{ 1, 0, 0, 1 } 
};
 
MatrixXd X, H, Y, YT;
MatrixXd WH(NUM_X, NUM_H), BH(1, NUM_H);
MatrixXd WY(NUM_H, NUM_Y), BY(1, NUM_Y);

double e;
MatrixXd YE, HE;
MatrixXd WYE, BYE;
MatrixXd WHE, BHE;
double lr = 0.01;

void dnn_test() {

	initialize_weight_He(WH);
	BH.setZero();
	initialize_weight_Le(WY);
	BY.setZero();
  
	X = Map<MatrixXd>(xs[2], 1, NUM_X);
	YT = Map<MatrixXd>(yts[2], 1, NUM_Y);

	cout << fixed;
	cout.precision(3);

	for(int epoch=0;epoch<10000;epoch++) {        

		relu_f(H = X*WH + BH);
		sigmoid_f(Y = H*WY + BY);
		
		e = calculate_MSE(Y, YT);
		
		sigmoid_b(YE = Y - YT, Y);
		relu_b(HE = YE*WY.transpose(), H);
		
		WYE = H.transpose()*YE;
		BYE = 1*YE;		
		WHE = X.transpose()*HE;
		BHE = 1*HE;
		
		WY -= lr*WYE;
		BY -= lr*BYE;
		WH -= lr*WHE;
		BH -= lr*BHE;

		if(epoch%100==99) cout << "epoch = " << epoch << endl;
		if(epoch%100==99) cout << Y.format(HeavyFmt) << endl;

		if(e<0.0000001) break;

	}
  
}

void setup() {
  
	Serial.begin(115200);
	delay(1000);

	dnn_test();

}

void loop() {}