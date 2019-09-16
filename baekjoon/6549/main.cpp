#include <cstdio>

int height[100005];

int main() {
	while (true) {
		int N;
		scanf("%d", &N);
		if (N == 0) break;

		for (int n = 0; n < N; n++) {
			scanf("%d", height + n);
		}

		printf("%d\n", 0);
	}

	return 0;
}
