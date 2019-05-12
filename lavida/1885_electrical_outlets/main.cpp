#include <cstdio>

int N;

int main() {
	scanf("%d", &N);

	while (N--) {
		int K;
		scanf("%d", &K);

		int result = 0;

		for (int k = 0; k < K; k++) {
			int outlet;
			scanf("%d", &outlet);

			result += outlet;
		}

		result -= K - 1;

		printf("%d\n", result);
	}

	return 0;
}
