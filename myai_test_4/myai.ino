#include <iostream>
#include <ArduinoEigen.h>
#include "mydnn.h"

using namespace std;
using namespace Eigen;

const int NUM_X = 1;
const int NUM_H = 16;
const int NUM_M = 16;
const int NUM_Y = 1;

MatrixXd X, H, M, Y, YT;
MatrixXd WH(NUM_X, NUM_H), BH(1, NUM_H);
MatrixXd WM(NUM_H, NUM_M), BM(1, NUM_M);
MatrixXd WY(NUM_M, NUM_Y), BY(1, NUM_Y);

double e;
MatrixXd YE, ME, HE;
MatrixXd WYE, BYE;
MatrixXd WME, BME;
MatrixXd WHE, BHE;
double lr = 0.01;

void dnn_learning(double * xs, double * yts, int NUM_LEARNING, int EPOCHS) {

  initialize_weight_He(WH);
  BH.setZero();
  initialize_weight_He(WM);
  BM.setZero();
  initialize_weight_Le(WY);
  BY.setZero();

  int * shuffled_pattern = (int *)malloc(sizeof(int)*NUM_LEARNING);
  for(int pc=0;pc<NUM_LEARNING;pc++) {
    shuffled_pattern[pc] = pc;
  }

  long begin = millis();

  for(int epoch=0;epoch<EPOCHS;epoch++) {

    random_shuffle(&shuffled_pattern[0], &shuffled_pattern[NUM_LEARNING]);
    
    double sumError = 0;

    static long t_prev = millis();

    for(int rc=0;rc<NUM_LEARNING;rc++) {

      int pc = shuffled_pattern[rc];

      X = Map<MatrixXd>(&xs[pc], 1, NUM_X);
      YT = Map<MatrixXd>(&yts[pc], 1, NUM_Y);

      relu_f(H = X*WH + BH);
      relu_f(M = H*WM + BM);
      Y = M*WY + BY; // linear

      e = calculate_MSE(Y, YT);

      sumError += e;

      YE = Y - YT, Y;
      relu_b(ME = YE*WY.transpose(), M);
      relu_b(HE = ME*WM.transpose(), H);

      WYE = M.transpose()*YE;
      BYE = 1*YE;     
      WME = H.transpose()*ME;
      BME = 1*ME;
      WHE = X.transpose()*HE;
      BHE = 1*HE;

      WY -= lr*WYE;
      BY -= lr*BYE;
      WM -= lr*WME;
      BM -= lr*BME;
      WH -= lr*WHE;
      BH -= lr*BHE;

    }
        
    if(epoch%10==9) {
      long t_now = millis();
      long time_taken = t_now - t_prev;
      t_prev = t_now;
      printf("epoch : %5d, sum error : %f ", epoch, sumError);
      printf(", %.3f sec\n", time_taken/1000.0);      
    }

  }
  printf("\n");
  
  long end = millis();
  long time_taken = end - begin;
  printf("\nTotal time taken (in seconds) %.3f\n", time_taken/1000.0);  

  free(shuffled_pattern);
  
}

void dnn_think(double * xs, double * ys, int NUM_THINKING) {
  
  for(int pc=0;pc<NUM_THINKING;pc++) {

      X = Map<MatrixXd>(&xs[pc], 1, NUM_X);

      relu_f(H = X*WH + BH);
      relu_f(M = H*WM + BM);
      Y = M*WY + BY;

      ys[pc] = Y(0,0);
      
  }
  
}
