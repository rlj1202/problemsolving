#include <cstdio>

int primes[10004];
int plen;

int main() {
	primes[plen++] = 2;
	for (int i = 3; i <= 10004; i += 2) {
		int pi;
		for (pi = 0; pi < plen; pi++) if (i % primes[pi] == 0) break;
		if (pi == plen) primes[plen++] = i;
	}
	
	int T;
	scanf("%d", &T);

	while (T--) {
		int N;
		scanf("%d", &N);

		while (N > 1) {
			for (int i = 0; i < plen;) {
				if (N % primes[i] == 0) {
					printf("%d ", primes[i]);
					N /= primes[i];
				} else {
					i++;
				}
			}
		}
		printf("\n");
	}

	return 0;
}
