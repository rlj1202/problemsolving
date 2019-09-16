#include <cstdio>

bool notPrime[4000006];
int primes[300005];
int primeslen;

int main() {
	notPrime[0] = true;
	notPrime[1] = true;
	for (int n = 2; n < 4000006; n++) {
		if (notPrime[n]) continue;
		primes[primeslen++] = n;
		for (int m = n+n; m < 4000006; m += n)
			notPrime[m] = true;
	}

	int N;
	scanf("%d", &N);

	int l = 0, r = 0;
	int cursum = 0;
	int result = 0;

	while (l < primeslen || r < primeslen) {
		if (r < primeslen && cursum <= N) {
			cursum += primes[r++];
		} else if (l < primeslen && cursum > N) {
			cursum -= primes[l++];
		} else {
			break;
		}

		if (cursum == N) result++;
	}

	printf("%d\n", result);

	return 0;
}
