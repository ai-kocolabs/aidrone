const int NUM_PATTERN = 10;
const int NUM_X = 4;
const int NUM_H = 16;
const int NUM_M = 16;
const int NUM_Y = 7;

double xs[NUM_PATTERN][NUM_X] = {
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
double yts[NUM_PATTERN][NUM_Y] = {
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
double ys[NUM_PATTERN][NUM_Y] = {0,};
 
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

int shuffled_pattern[NUM_PATTERN];

void dnn_test() {

	initialize_weight_He(WH);
	BH.setZero();
	initialize_weight_He(WM);
	BM.setZero();
	initialize_weight_Le(WY);
	BY.setZero();
	
	for(int pc=0;pc<NUM_PATTERN;pc++) {
		shuffled_pattern[pc] = pc;
	}

	cout << fixed;
	cout.precision(3);

	int epoch;
	for(epoch=0;epoch<10000;epoch++) {
		
		if(epoch%100==99) cout << "epoch = " << epoch << endl;
		
		random_shuffle(begin(shuffled_pattern), end(shuffled_pattern));

		double sumE = 0;
		
		for(int rc=0;rc<NUM_PATTERN;rc++) {
			
			int pc = shuffled_pattern[rc];
  
			X = Map<MatrixXd>(xs[pc], 1, NUM_X);
			YT = Map<MatrixXd>(yts[pc], 1, NUM_Y);

			relu_f(H = X*WH + BH);
			relu_f(M = H*WM + BM);
			sigmoid_f(Y = M*WY + BY);
			
			e = calculate_MSE(Y, YT);
			sumE += e;

			sigmoid_b(YE = Y - YT, Y);
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

			Map<MatrixXd>(ys[pc], 1, NUM_Y) = Y;

		}
		
		if(sumE<0.0000001) break;

	}

	cout << "epoch = " << epoch << endl;    
	for(int pc=0;pc<NUM_PATTERN;pc++) {
		Y = Map<MatrixXd>(ys[pc], 1, NUM_Y);
		cout << pc << ":" << Y.format(HeavyFmt) << endl;
	}
  
}

void setup() {
  
	Serial.begin(115200);
	delay(1000);

	dnn_test();

}

void loop() {}