#include <iostream>

int T;

int main() {
	scanf("%d", &T);

	while (T--) {
		long long A, B, K;
		scanf("%lld %lld %lld", &A, &B, &K);

		long long result = (A - B) * (K / 2);
		result += (K % 2) * A;

		printf("%lld\n", result);
	}

	return 0;
}
