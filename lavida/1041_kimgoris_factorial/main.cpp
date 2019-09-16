#include <cstdio>

int notfactorial(int n) {
	if (n == 0) return 1;
	
	int prev = notfactorial(n - 1);
	
	if (prev % n == 0) return prev / n;
	else return n * prev;
}

int main() {
	int T;
	scanf("%d", &T);

	while (T--) {
		int N;
		scanf("%d", &N);

		printf("%d\n", notfactorial(N));
	}

	return 0;
}
