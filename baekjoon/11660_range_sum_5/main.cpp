#include <iostream>

int N, M;
int sum[1100][1100];

int main() {
	scanf("%d %d", &N, &M);

	for (int n = 1; n <= N; n++) {
		for (int m = 1; m <= N; m++) {
			int value;
			scanf("%d", &value);

			sum[n][m] = value;
			sum[n][m] += sum[n - 1][m];
			sum[n][m] += sum[n][m - 1];
			sum[n][m] -= sum[n - 1][m - 1];
		}
	}

	while (M--) {
		int x, y, z, w;
		scanf("%d %d %d %d", &x, &y, &z, &w);

		int result = sum[z][w];
		result -= sum[x - 1][w];
		result -= sum[z][y - 1];
		result += sum[x - 1][y - 1];

		printf("%d\n", result);
	}

	return 0;
}
