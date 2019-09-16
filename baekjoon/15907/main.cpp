#include <cstdio>
#include <algorithm>

using namespace std;

const int PRIME_MAX = 2000000;

bool isNotPrime[PRIME_MAX + 1];
int primes[200005];
int primeslen;

int N;
int time[1003];

int temp[1003];
int remainders[PRIME_MAX + 1];

int main() {
	// make list of prime numbers
	isNotPrime[0] = true;
	isNotPrime[1] = true;
	for (int n = 2; n <= PRIME_MAX; n++) {
		if (isNotPrime[n]) continue;

		primes[primeslen++] = n;

		int m = n + n;
		while (m <= PRIME_MAX) {
			isNotPrime[m] = true;
			m += n;
		}
	}

	// read input
	scanf("%d", &N);
	for (int n = 0; n < N; n++)
		scanf("%d", time + n);

	// test for prime numbers
	int result = 0;

	for (int pi = 0; pi < primeslen; pi++) {
		int cur = primes[pi];

		for (int n = 0; n < N; n++) {
			int remainder = time[n] % cur;
			remainders[remainder]++;
			temp[n] = remainder;
			result = max(result, remainders[remainder]);
		}

		for (int n = 0; n < N; n++)
			remainders[temp[n]] = 0;
	}

	// print result
	printf("%d\n", result);

	return 0;
}
