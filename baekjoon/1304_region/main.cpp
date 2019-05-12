#include <cstdio>

int N, M;
int adj[3003][3003];
int cnt;

int main() {
	scanf("%d %d", &N, &M);

	for (int m = 1; m <= M; m++) {
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a][b] = 1;
	}

	for (int i = 1; i < N; i++)
		adj[i][i + 1] = 1;

	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				adj[i][j] |= adj[i][k] & adj[k][j];

	for (int i = 2; i <= N; i++)
		if (adj[i][i - 1] == 0) cnt++;

	printf("%d\n", cnt + 1);

	return 0;
}
