#include <iostream>

int N;

int main() {
	scanf("%d", &N);
	for (int n = 1; n <= N; n++) {
		for (int m = 0; m < n - 1; m++) printf(" ");
		for (int m = 0; m < (1 + (N - n) * 2); m++) printf("*");
		printf("\n");
	}

	return 0;
}
