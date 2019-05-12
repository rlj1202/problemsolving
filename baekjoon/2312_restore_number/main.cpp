#include <iostream>

int primes[10004];
int plen;

int T;

int N;

int main() {
	primes[plen++] = 2;
	for (int n = 3; n < 100005; n++) {
		int pi = 0;
		for (; pi < plen; pi++) if (n % primes[pi] == 0) break;
		if (pi == plen) primes[plen++] = n;
	}

	/* XXX */ for (int pi = 0; pi < plen; pi++) printf("%d ", primes[pi]); printf("\nprimes: %d\n", plen);

	scanf("%d", &T);

	while (T--) {
		scanf("%d", &N);

		for (int pi = 0; pi < plen; pi++) {
			if (N == 1) break;

			int prime = primes[pi];

			int count = 0;
			while (N % prime == 0) {
				count++;
				N /= prime;
			}

			if (count > 0) printf("%d %d\n", prime, count);
		}
	}

	return 0;
}
