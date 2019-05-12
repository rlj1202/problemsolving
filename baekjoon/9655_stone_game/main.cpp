#include <iostream>
#include <cstring>

using namespace std;

int N;
int gd[1003];

int mex(int *set) {
	int number = 0;
	for (int i = 0; i < 3; i += 2) {
		if (number != set[i]) break;
		number++;
	}

	return number;
}

void grundy(int n) {
	if (n == 0) gd[n] = 0;
	if (n == 1) gd[n] = 1;
	if (n == 2) gd[n] = 0;
	if (n == 3) gd[n] = 1;
	else if (gd[n] == gd[0]) {
		grundy(n - 3); grundy(n - 1);
		gd[n] = mex(gd + (n - 3));
	}
}

int main() {
	scanf("%d", &N);
	memset(gd, 63, sizeof(gd));

	grundy(N);
	if (gd[N] == 0) printf("CY");
	else printf("SK");
	
	return 0;
}
