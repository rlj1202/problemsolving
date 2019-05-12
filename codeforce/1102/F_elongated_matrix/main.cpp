#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int INF = 2000000009;

int N, M;
int mat[16][10004];

int vertdeltas[16][16]; // vertical
//int rdigdeltas[16][16]; // right digonal
int ldigdeltas[16][16]; // left digonal

int dp[16][1 << 16];

int f(int start, int cur, int visited) {
	if (dp[cur][visited] != -1) return dp[cur][visited];

	if (visited == (1 << N) - 1) {
		return dp[cur][visited] = ldigdeltas[cur][start];
	} else {
		int result = -1;

		for (int next = 0; next < N; next++) {
			int mask = 1 << next;
			if ((visited & mask) > 0) continue;

			result = max(
					result,
					min(f(start, next, visited | mask), vertdeltas[cur][next])
					);
		}

		return dp[cur][visited] = result;
	}
}

int main() {
	// read input
	scanf("%d %d", &N, &M);
	for (int n = 0; n < N; n++)
		for (int m = 0; m < M; m++)
			scanf("%d", &mat[n][m]);

	// preprocess
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			int mindelta = INF;
			for (int k = 0; k < M; k++)
				mindelta = min(mindelta, abs(mat[i][k] - mat[j][k]));

			vertdeltas[i][j] = mindelta;
			vertdeltas[j][i] = mindelta;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			//if (i == j) continue; // what if N is equal to 1 ?

			//int rmindelta = INF;
			int lmindelta = INF;
			for (int k = 0; k < M - 1; k++) {
				//rmindelta = min(rmindelta, abs(mat[i][k] - mat[j][k + 1]));
				lmindelta = min(lmindelta, abs(mat[i][k + 1] - mat[j][k]));
			}

			//rdigdeltas[i][j] = rmindelta;
			ldigdeltas[i][j] = lmindelta;
		}
	}

	// dp
	int K = 0;
	for (int n = 0; n < N; n++) {
		memset(dp, -1, sizeof(dp));
		K = max(K, f(n, n, 1 << n));
	}
	
	// print result
	printf("%d\n", K);

	return 0;
}
