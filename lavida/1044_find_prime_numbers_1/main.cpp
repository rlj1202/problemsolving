#include <stdio.h>

int T, N;

int main() {
	scanf("%d", &T);

	while (T--) {
		scanf("%d", &N);

		bool isPrime = true;

		for (int i = 2; i < N; i++) {
			if (N % i == 0) {
				isPrime = false;
				break;
			}
		}

		if (isPrime) printf("Prime\n");
		else printf("Not Prime\n");
	}

	return 0;
}
