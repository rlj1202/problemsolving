#include <iostream>

int N, M;
int sum[100005];

int main() {
	scanf("%d %d", &N, &M);

	for (int n = 1; n <= N; n++) {
		scanf("%d", sum + n);
		sum[n] += sum[n - 1];
	}

	while (M--) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", sum[b] - sum[a - 1]);
	}

	return 0;
}
