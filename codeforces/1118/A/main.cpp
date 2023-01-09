#include <iostream>

int Q;

long long N;
int a, b;

int main() {
	scanf("%d", &Q);

	while (Q--) {
		scanf("%lld %d %d", &N, &a, &b);

		long long result = 0;

		if (a * 2 <= b) {
			result = a * N;
		} else {
			result = b * (N / 2);
			if (N % 2 == 1) result += a;
		}

		printf("\t%lld\n", result);
	}

	return 0;
}
