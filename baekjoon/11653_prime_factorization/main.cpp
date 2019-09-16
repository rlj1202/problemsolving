#include <cstdio>

bool notPrime[10000007];
int primes[1000006];
int plen;

int main() {
	notPrime[0] = true;
	notPrime[1] = true;
	for (int n = 2; n <= 10000000; n++) {
		if (notPrime[n]) continue;
		primes[plen++] = n;

		for (int m = n + n; m <= 10000000; m += n)
			notPrime[m] = true;
	}

	int N;
	scanf("%d", &N);

	int pi = 0;

	while (N != 1 && pi < plen) {
		if (N % primes[pi] == 0) {
			N /= primes[pi];
			printf("%d\n", primes[pi]);
		} else {
			pi++;
		}
	}

	return 0;
}
