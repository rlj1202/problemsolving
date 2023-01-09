#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

using namespace std;

int N, R;

int main() {
	scanf("%d %d", &N, &R);
	
	double result = (R * sin(M_PI / N)) / (1 - sin(M_PI / N));
	printf("%.7f\n", result);
	
	return 0;
}
