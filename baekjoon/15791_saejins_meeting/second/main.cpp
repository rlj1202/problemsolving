#include <iostream>

const int PRIME = 1000000007;

int N, M;

long long result = 1;

int main() {
	scanf("%d %d", &N, &M);

	long long a = 1;
	for (int n = 1; n <= N; n++) {
		a *= n;
		a %= PRIME;
	}
	result *= a;

	long long b = 1;
	for (int m = 1; m <= M; m++) {
		b *= m;
		b %= PRIME;
	}
	for (int i = 1; i <= N - M; i++) {
		b *= i;
		b %= PRIME;
	}

	int p = PRIME - 2;
	while (p > 0) {
		if ((p & 1) == 1) {
			result *= b;
			result %= PRIME;
		}
		p >>= 1;
		b = b * b;
		b %= PRIME;
	}

	printf("%lld\n", result);

	return 0;
}
