#include <iostream>

long long N;

int main() {
	scanf("%lld", &N);

	if (N == 1) {
		printf("1\n");
		return 0;
	}

	long long n = N;
	long long cnt = 0;
	if (n % 2 != 0) { // odd number
		long long prime = 3;
		for (; prime <= N; prime++) {
			if (n % prime == 0) {
				bool notPrime = false;
				for (long long i = 2; i < prime; i++) {
					if ((notPrime = (prime % i == 0))) {
						break;
					}
				}

				if (!notPrime)
					break;
			}
		}

		n -= prime;
		cnt++;
	}

	cnt += n / 2;
	printf("%lld\n", cnt);

	return 0;
}
