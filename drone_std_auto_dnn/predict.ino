#include <ArduinoEigen.h>
#include "mydnn.h"
#include "model_data.h"

using namespace Eigen;

const int NUM_X = 6;
const int NUM_H = 16;
const int NUM_M = 16;
const int NUM_Y = 3;

MatrixXd X, H, M, Y;
MatrixXd WH(NUM_X, NUM_H), BH(1, NUM_H);
MatrixXd WM(NUM_H, NUM_M), BM(1, NUM_M);
MatrixXd WY(NUM_M, NUM_Y), BY(1, NUM_Y);

void dnn_initialize() {

  WH = Map<Matrix<double,NUM_X,NUM_H,RowMajor>>(_WH);
  BH = Map<MatrixXd>(_BH, 1, NUM_H);  
  WM = Map<Matrix<double,NUM_H,NUM_M,RowMajor>>(_WM);
  BM = Map<MatrixXd>(_BM, 1, NUM_M);
  WY = Map<Matrix<double,NUM_M,NUM_Y,RowMajor>>(_WY);
  BY = Map<MatrixXd>(_BY, 1, NUM_Y);

}

void dnn_predict(double x[], const int NUM_X, double y[], const int NUM_Y) {

  X = Map<MatrixXd>(x, 1, NUM_X);

  relu_f(H = X*WH + BH);
  relu_f(M = H*WM + BM);
  Y = M*WY + BY;

  Map<MatrixXd>(y, 1, NUM_Y) = Y;
    
}
