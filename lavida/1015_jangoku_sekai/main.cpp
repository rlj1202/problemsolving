#include <stdio.h>

int T, N;

int main() {
	scanf("%d", &T);

	while (T--) {
		scanf("%d", &N);

		int day = 0;

		while (N > 1) {
			if (N % 2 == 0) {
				N = N / 2;
			} else if (N % 2 == 1) {
				N = N * 3 + 1;
			}
			
			day++;
		}

		printf("%d\n", day);
	}

	return 0;
}
