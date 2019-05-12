#include <iostream>

int N, M;
int edge[102][102];

int main() {
	scanf("%d %d", &N, &M);
	for (int m = 0; m < M; m++) {
		int a, b;
		scanf("%d %d", &a, &b); // a.weight > b.weight
		edge[a][b] = -1;
		edge[b][a] = 1;
	}

	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if (edge[i][j] == 0 && edge[i][k] == edge[k][j])
					edge[i][j] = edge[i][k];

	for (int n = 1; n <= N; n++) {
		int count = 0;
		for (int m = 1; m <= N; m++) {
			if (n == m) continue;
			if (edge[n][m] == 0) count++;
		}
		printf("%d\n", count);
	}

	return 0;
}
