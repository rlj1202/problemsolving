#include <iostream>

long long N;

int main() {
	scanf("%lld", &N);

	if (N < 2) {
		printf("%lld\n", N);
	} else {
		int a = 0;
		int b = 1;
		int c;

		N %= 1500000; // XXX

		while (N-- >= 2) {
			c = a + b;
			c %= 1000000;

			a = b;
			b = c;
		}

		printf("%d\n", b);
	}

	return 0;
}
