#include <cstdio>

int N, M;

int main() {
	scanf("%d %d", &N, &M);

	long long result = 1;

	for (int n = 0; n < N; n++) {
		long long num;
		scanf("%lld", &num);

		result *= num % M;
		result %= M;
	}

	printf("%lld\n", result);

	return 0;
}
