#include <cstdio>

int fibo(int n) {
	if (n <= 1) return n;
	return fibo(n - 1) + fibo(n - 2);
}

int main() {
	int T;
	scanf("%d", &T);

	while (T--) {
		int N;
		scanf("%d", &N);

		printf("%d\n", fibo(N));
	}

	return 0;
}
