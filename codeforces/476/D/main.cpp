#include <cstdio>

int main() {
	int N, K;
	scanf("%d %d", &N, &K);

	printf("%d\n", 0);
	for (int n = 0; n < N; n++) {
		for (int i = 0; i < 4; i++) {
			printf("%d ", 0);
		}
		printf("\n");
	}

	return 0;
}
