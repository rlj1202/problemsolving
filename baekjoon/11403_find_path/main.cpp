#include <iostream>

int N;
int adj[102][102];

int main() {
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			scanf("%d", &adj[i][j]);

	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				adj[i][j] |= adj[i][k] & adj[k][j];

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			printf("%d ", adj[i][j]);
		printf("\n");
	}

	return 0;
}
