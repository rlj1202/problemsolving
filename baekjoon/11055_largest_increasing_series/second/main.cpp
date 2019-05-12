#include <iostream>
#include <cstring>

using namespace std;

int N;
int series[1003];

int dp[1003];

int f(int index) {
	if (dp[index] != -1) return dp[index];

	int result = 0;

	for (int next = index + 1; next <= N; next++) {
		if (series[index] >= series[next]) continue;

		result = max(result, f(next));
	}

	return dp[index] = series[index] + result;
}

int main() {
	scanf("%d", &N);
	for (int n = 1; n <= N; n++) scanf("%d", series + n);

	memset(dp, -1, sizeof(dp));
	printf("%d\n", f(0));

	return 0;
}
