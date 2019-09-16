#include <cstdio>
#include <algorithm>

using namespace std;

int sum[3][30004];

int main() {
	int N;
	scanf("%d", &N);
	for (int n = 1; n <= N; n++) {
		int num;
		scanf("%d", &num);
		
		for (int i = 0; i < 3; i++) sum[i][n] = sum[i][n - 1];
		sum[num - 1][n]++;
	}

	int result = 0x3f3f3f3f;

	for (int i = 1; i <= N - 2; i++) {
		for (int j = i + 1; j <= N - 1; j++) {
			int cost;

			cost = 0;

			cost += sum[1][i] - sum[1][0];
			cost += sum[2][i] - sum[2][0];

			cost += sum[0][j] - sum[0][i];
			cost += sum[2][j] - sum[2][i];

			cost += sum[0][N] - sum[0][j];
			cost += sum[1][N] - sum[1][j];

			result = min(result, cost);

			cost = 0;

			cost += sum[0][i] - sum[0][0];
			cost += sum[1][i] - sum[1][0];

			cost += sum[0][j] - sum[0][i];
			cost += sum[2][j] - sum[2][i];

			cost += sum[1][N] - sum[1][j];
			cost += sum[2][N] - sum[2][j];

			result = min(result, cost);
		}
	}

	printf("%d\n", result);

	return 0;
}
