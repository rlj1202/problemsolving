#include <iostream>

int M, N;

int counts[10];

int main() {
	scanf("%d %d", &M, &N);

	for (int n = M; n <= N; n++) {
		int tmp = n;
		while (tmp) {
			counts[tmp % 10]++;
			tmp /= 10;
		}
	}

	for (int d = 0; d < 10; d++) printf("%d ", counts[d]);
	printf("\n");

	return 0;
}
