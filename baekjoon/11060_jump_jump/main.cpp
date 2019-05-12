#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;

int N;
int arr[1003];

int dp[1003];

int f(int index) {
	if (dp[index] != INF) return dp[index];

	if (index >= N) return INF;
	if (index == N - 1) return 0;

	int cur = arr[index];

	int result = INF;
	for (int d = 1; d <= cur; d++)
		result = min(result, f(index + d) + 1);

	return dp[index] = result;
}

int main() {
	scanf("%d", &N);
	for (int n = 0; n < N; n++)
		scanf("%d", arr + n);

	memset(dp, INF, sizeof(dp));
	int result = f(0);
	printf("%d\n", result == INF ? -1 : result);

	return 0;
}
