#include <cstdio>

const long long MOD = 1e9 + 7;

int main() {
	long long A, B;
	scanf("%lld %lld", &A, &B);

	long long result = 0;

	for (long long k = 1; k <= A; k++) {
		long long nice =
			(((B - 1LL) * B) / 2LL % MOD)
			* ((k * B + 1LL) % MOD);

		result += nice;
		result %= MOD;

		/*
		for (long long r = 1; r < B; r++) {
			result += r * (k * B + 1);
			result %= MOD;
		}
		*/
	}

	printf("%lld\n", result);

	return 0;
}
