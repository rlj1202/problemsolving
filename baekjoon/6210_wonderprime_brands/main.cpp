#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int primes[6003];
int primeslen;

int D;
int N;

int minimum_prime(int digits) {
	int minimum = 1;
	for (int d = 0; d < digits - 1; d++) minimum *= 10;
	return *lower_bound(primes, primes + primeslen, minimum);
}

int digitlen(int n) {
	int len = 0;
	while (n) {
		n /= 10;
		len++;
	}
	return len;
}

bool is_prime(int n) {
	if (n == 1) return false;
	int root = sqrt(n);
	for (int p = 0; p < primeslen && primes[p] <= root; p++) {
		if (n % primes[p] == 0) return false;
	}
	return true;
}

// the distance between the two prime numbers less than 2e9 is about 300.
// so it will take not much time. regard its time complexity as O(1).
//
// if n is already prime number, it will return the next prime number.
int find_next_prime(int n) {
	do n++; while (!is_prime(n));
	return n;
}

int main() {
	// make a lite of prime numbers
	primes[primeslen++] = 2;
	for (int n = 3; n <= 50004; n += 2) { // 50000 is about sqrt(2e9).
		bool is_prime = true;
		int root = sqrt(n);
		for (int p = 0; p < primeslen && primes[p] <= root; p++) {
			if (n % primes[p] == 0) {
				is_prime = false;
				break;
			}
		}
		if (is_prime) primes[primeslen++] = n;
	}

	//printf("primeslen: %d\n", primeslen); // XXX

	// read input
	scanf("%d %d", &D, &N);

	if (digitlen(N) < D * 2) {
		N = 1;
		for (int d = 0; d < D * 2 - 1; d++) N *= 10;
	}

	// find best brand for cows :D
	int left = -1;
	int right;

	int divider = 1;
	for (int d = 0; d < D; d++) divider *= 10;
	int rightlen = D;

	long long min_wonderprime = 0x7fffffffffffffff;

	while (left != 0) {
		left = N / divider;
		right = N % divider;

		int newleft = left;
		int newright = right;

		if (digitlen(newleft) < D) {
			newleft = 1;
			for (int d = 0; d < D - 1; d++) newleft *= 10;
		}
		if (digitlen(newright) < rightlen) {
			newright = 1;
			for (int d = 0; d < rightlen - 1; d++) newright *= 10;
		}

		bool left_changed = false;

		while (!is_prime(newleft)) {
			newleft = find_next_prime(newleft);
			left_changed = true;
		}

		if (left_changed) {
			newright = 1;
			for (int d = 0; d < rightlen - 1; d++) newright *= 10;
		}

		while (!is_prime(newright))
			newright = find_next_prime(newright);

		long long shifter = 1;
		for (int d = 0; d < digitlen(newright); d++) shifter *= 10;

		long long brand = newleft * shifter + newright;
		min_wonderprime = min(min_wonderprime, brand);

		divider *= 10;
		rightlen++;
	}

	// print result
	printf("%lld\n", min_wonderprime);

	return 0;
}
