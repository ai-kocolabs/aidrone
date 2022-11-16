#include <iostream>
#include <ArduinoEigen.h>

using namespace std;
using namespace Eigen;

IOFormat HeavyFmt(StreamPrecision, 0, ", ", ",\n", "[", "]", "[", "]");

MatrixXd X(1, 2);
MatrixXd H(1, 2);
MatrixXd Y(1, 2);
MatrixXd WH(2, 2);
MatrixXd BH(1, 2);
MatrixXd WY(2, 2);
MatrixXd BY(1, 2);
MatrixXd YT(1, 2);

MatrixXd E;
double e;
MatrixXd YE;
MatrixXd HE;
MatrixXd WYE;
MatrixXd BYE;
MatrixXd WHE;
MatrixXd BHE;
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

	for(int epoch=0;epoch<2000;epoch++) {        

		H = X*WH + BH;
		Y = H*WY + BY;
		E = (Y - YT)*(Y - YT).transpose()/2;
		e = E(0, 0);
		YE = Y - YT;
		WYE = H.transpose()*YE;
		BYE = 1*YE;
		HE = YE*WY.transpose(); // 여기서 구한 HE는
		WHE = X.transpose()*HE; // 여기와 
		BHE = 1*HE; // 여기서 사용됩니다.
		WY -= lr*WYE;
		BY -= lr*BYE;
		WH -= lr*WHE;
		BH -= lr*BHE;

		cout << "epoch = " << epoch << endl;
		cout << Y.format(HeavyFmt) << endl;
		cout << WY.format(HeavyFmt) << endl;
		cout << BY.format(HeavyFmt) << endl;
		cout << WH.format(HeavyFmt) << endl;
		cout << BH.format(HeavyFmt) << endl;

		if(e<0.0000001) break;

	}

}
void setup() {

	Serial.begin(115200);
	delay(1000);

	dnn_test();

}

void loop() {}