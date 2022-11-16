#include <iostream> // 문자열 출력을 위해 필요합니다.
#include <ArduinoEigen.h> // 행렬 연산을 위해 필요합니다.

using namespace std; // 문자열 출력을 위해 필요합니다.
using namespace Eigen; // 행렬 연산을 위해 필요합니다.

MatrixXd A(2, 2); // 실수를 원소로 갖는 2x2 행렬 객체를 생성합니다.
MatrixXd B(1, 2); // 실수를 원소로 갖는 1x2 행렬 객체를 생성합니다.
MatrixXd C(2, 1); // 실수를 원소로 갖는 2x1 행렬 객체를 생성합니다.

// Eigen 행렬의 출력 방식을 정하는 객체를 생성합니다.
IOFormat HeavyFmt(StreamPrecision, 0, ", ", ",\n", "[", "]", "[", "]");

void setup() {

	Serial.begin(115200);
	delay(1000);

	A << 1, 2, 3, 4; // A 행렬을 1, 2, 3, 4 값으로 초기화합니다.
	B << 1, 2; // B 행렬을 1, 2 값으로 초기화합니다.
	C << 1, 2; // C 행렬을 1, 2 값으로 초기화합니다.

	cout << A.format(HeavyFmt) << endl; // A 행렬 값 출력
	cout << B.format(HeavyFmt) << endl; // B 행렬 값 출력
	cout << C.format(HeavyFmt) << endl; // C 행렬 값 출력

}

void loop() {}