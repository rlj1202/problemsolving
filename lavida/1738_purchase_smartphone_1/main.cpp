#include <stdio.h>

int T, N;

int main() {
	scanf("%d", &T);

	while (T--) {
		scanf("%d", &N);

		int days = 0;
		int earned = 0;

		while (earned < N) {
			earned +=
				5000
				+ (days / 10) * 200;
			days++;
		}

		printf("%d\n", days);
	}

	return 0;
}
