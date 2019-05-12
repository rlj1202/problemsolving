#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int primes[1000006];
int plen;

int A, B, D;

int main() {
	primes[plen++] = 2;
	for (int n = 3; n <= 4000000; n += 2) {
		bool isprime = true;
		int root = sqrt(n);
		for (int p = 0; p < plen && primes[p] <= root; p++) {
			if (n % primes[p] == 0) {
				isprime = false;
				break;
			}
		}
		if (isprime) primes[plen++] = n;
	}

	scanf("%d %d %d", &A, &B, &D);

	int start = lower_bound(primes, primes + plen, A) - primes;
	int end = upper_bound(primes, primes + plen, B) - primes;

	int count = 0;

	for (int i = start; i < end; i++) {
		int tmp = primes[i];

		while (tmp) {
			if (tmp % 10 == D) {
				count++;
				break;
			}
			tmp /= 10;
		}
	}

	printf("%d\n", count);
	
	return 0;
}
