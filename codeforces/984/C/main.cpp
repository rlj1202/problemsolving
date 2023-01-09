#include <cstdio>

long long primes[10000007];
int plen;

long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	int N;
	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		long long p, q, b;
		scanf("%lld %lld %lld", &p, &q, &b);

		long long div = gcd(p, q);
		if (div) {
			p /= div;
			q /= div;
		}

		bool finite = false;

		long long common;
		while ((common = gcd(b, q)) > 1) {
			q /= common;
			b = common;
		}

		finite = q == 1;

		printf("%s\n", finite ? "Finite" : "Infinite");
	}

	return 0;
}
