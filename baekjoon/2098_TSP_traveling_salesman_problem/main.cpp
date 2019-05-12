#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 16;
const int INF = 0x3f3f3f3f;

int N;
int mat[MAX][MAX];

int dp[MAX][1 << MAX]; // dp[cur][mask]

int f(int start, int cur, int visited) {
	if (dp[cur][visited] != -1) return dp[cur][visited];

	if (visited == ((1 << N) - 1)) {
		return dp[cur][visited] = mat[cur][start] == 0 ? INF : mat[cur][start];
	} else {
		int result = INF;

		for (int next = 0; next < N; next++) {
			int mask = (1 << next);

			if ((visited & mask) > 0) continue; // already visited
			if (mat[cur][next] == 0) continue; // no edge

			result = min(
					result,
					mat[cur][next] + f(start, next, (visited | mask))
					);
		}

		return dp[cur][visited] = result;
	}
}

int main() {
	scanf("%d", &N);
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			scanf("%d", &mat[r][c]);

	memset(dp, -1, sizeof(dp));
	int start = 0;
	printf("%d\n", f(start, start, (1 << start)));

	return 0;
}
