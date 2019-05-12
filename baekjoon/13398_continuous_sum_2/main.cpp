#include <iostream>

using namespace std;

const int INF = (1 << 31) - 1;

int N;
int arr[100005];

int dp[100005][2]; // dp[index][jumped]

int f(int index, bool jumped) {
	if (dp[index][jumped] != INF) return dp[index][jumped];
	if (index == N) return arr[index];

	int result = max(0, f(index + 1, jumped));
	if (!jumped && index + 2 <= N) result = max(result, f(index + 2, true));

	return dp[index][jumped] = arr[index] + result;
}

int main() {
	scanf("%d", &N);
	for (int n = 1; n <= N; n++) scanf("%d", arr + n);

	for (int i = 0; i < 2; i++)
		for (int n = 1; n <= N; n++)
			dp[n][i] = INF;

	int result = -INF;
	for (int n = 1; n <= N; n++)
		result = max(result, f(n, false));
	printf("%d\n", result);

	return 0;
}
