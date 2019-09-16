#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;

int N;

int A[2003];
int B[2003];

long long dp[2003][2003];

long long dtw(int i, int j) {
	if (i >= N || j >= N) return INF;
	if (dp[i][j] != -1) return dp[i][j];

	long long mindistance = INF;
	mindistance = min(mindistance, dtw(i + 1, j));
	mindistance = min(mindistance, dtw(i, j + 1));
	mindistance = min(mindistance, dtw(i + 1, j + 1));

	if (i == N - 1 && j == N - 1) mindistance = 0;

	long long delta = A[i] - B[j];

	return dp[i][j] = mindistance + delta * delta;
}

int main() {
	scanf("%d", &N);
	for (int n = 0; n < N; n++) scanf("%d", A + n);
	for (int n = 0; n < N; n++) scanf("%d", B + n);

	memset(dp, -1, sizeof(dp));
	long long result = dtw(0, 0);

	printf("%lld\n", result);

	return 0;
}
