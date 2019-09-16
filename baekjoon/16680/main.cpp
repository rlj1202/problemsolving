#include <cstdio>

int main() {
	int T;
	scanf("%d", &T);

	while (T--) {
		int N;
		scanf("%d", &N);

		long long value;
		for (long long m = 10; (value = N * (m - 1)) <= 1e18; m *= 10) {
			int sum = 0;
			long long tmp = value;
			while (tmp) {
				sum += tmp % 10;
				tmp /= 10;
			}

			if (sum % 2 == 1) {
				printf("%lld\n", value);
				break;
			}
		}
	}

	return 0;
}
