#include <cstdio>

long long factorial(int n) {
	if (n == 0) return 1;
	return n * factorial(n - 1);
}

int main() {
	int T;
	scanf("%d", &T);

	while (T--) {
		int N;
		scanf("%d", &N);

		printf("%lld\n", factorial(N));
	}

	return 0;
}
