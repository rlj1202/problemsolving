#include <cstdio>

int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	int result = -1;

	for (int m = M; m <= 10000; m += M) {
		bool possible = false;

		for (int i = 0; i <= m; i++) {
			if (2 * i + (m - i) == N) {
				possible = true;
				break;
			}
		}
		
		if (possible) {
			result = m;
			break;
		}
	}

	printf("%d\n", result);

	return 0;
}
