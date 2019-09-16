#include <cstdio>

int series[131072];
int states[131072];

int main() {
	// read input
	int N, M;
	scanf("%d %d", &N, &M);
	for (int m = 0; m < M; m++) {
		scanf("%d", series + m);
	}

	//
	int log = 0;
	int tmp = N;
	while (tmp >>= 1) log++;

	for (int l = log - 1; l >= 0; l--) {
		for (int m = 0; m < M; m++) {
			states[m] = (states[m] << 1) + series[m] & (1 << l) ? 1 : 0;
		}
	}

	// print result
	printf("%d\n", 0);

	return 0;
}
