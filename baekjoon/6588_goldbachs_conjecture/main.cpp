#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX_PRIME = 1000006;

const char MSG_ERROR[] = "Goldbach's conjecture is wrong.";

int primes[MAX_PRIME];
int plen;

int N;

int main() {
	// get prime numbers
	primes[plen++] = 2;
	for (int n = 3; n < MAX_PRIME; n++) {
		int bound = sqrt(n);
		int isprime = true;
		for (int pi = 0; pi < plen && primes[pi] <= bound; pi++) {
			if (n % primes[pi] == 0) {
				isprime = false;
				break;
			}
		}
		if (isprime) primes[plen++] = n;
	}

	while (true) {
		scanf("%d", &N);
		if (N == 0) break;

		int l = 1; // primes[1] = 3, which is the first odd prime number.
		int r = lower_bound(primes, primes + plen, N) - primes;

		int sum = 0;
		while (l <= r) {
			sum = primes[l] + primes[r];
			if (sum == N) break;
			else if (sum < N) l++;
			else r--;
		}

		if (sum == N && l <= r) printf("%d = %d + %d\n", N, primes[l], primes[r]);
		else printf("%s\n", MSG_ERROR);
	}

	return 0;
}
