#include <cstdio>

int main() {
	int N, K;
	while (scanf("%d %d", &N, &K) != EOF) {
		int result = 0;

		int coupons = N;
		int stamps = 0;

		while (coupons) {
			result += coupons;
			stamps += coupons;

			coupons = stamps / K;
			stamps %= K;
		}

		printf("%d\n", result);
	}

	return 0;
}
