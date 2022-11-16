#include <iostream>
#include <ArduinoEigen.h>
#include "mydnn.h"
#include "model_data.h"

using namespace std;
using namespace Eigen;

IOFormat HeavyFmt(StreamPrecision, 0, ", ", ",\n", "[", "]", "[", "]");

const int NUM_X = 6;
const int NUM_H = 16;
const int NUM_M = 16;
const int NUM_Y = 3;

MatrixXd X, H, M, Y;
MatrixXd WH(NUM_X, NUM_H), BH(1, NUM_H);
MatrixXd WM(NUM_H, NUM_M), BM(1, NUM_M);
MatrixXd WY(NUM_M, NUM_Y), BY(1, NUM_Y);

void dnn_test() {

  WH = Map<Matrix<double,NUM_X,NUM_H,RowMajor>>(_WH);
  BH = Map<MatrixXd>(_BH, 1, NUM_H);  
  WM = Map<Matrix<double,NUM_H,NUM_M,RowMajor>>(_WM);
  BM = Map<MatrixXd>(_BM, 1, NUM_M);
  WY = Map<Matrix<double,NUM_M,NUM_Y,RowMajor>>(_WY);
  BY = Map<MatrixXd>(_BY, 1, NUM_Y);

  double x_test[] = {
    -0.2296142578125, -0.1058349609375, 0.54541015625, 
    0.01397705078125, -0.0621337890625, 0.009613037109375
  };
  
  X = Map<MatrixXd>(x_test, 1, NUM_X);

  relu_f(H = X*WH + BH);
  relu_f(M = H*WM + BM);
  Y = M*WY + BY;

  cout << fixed;
  cout.precision(8);
  
  cout << Y.format(HeavyFmt) << endl;
    
}

void setup() {
  
  Serial.begin(115200);
  delay(1000);

  dnn_test();

}

void loop() {}
