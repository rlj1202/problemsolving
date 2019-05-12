#include <iostream>
#include <cstring>

using namespace std;

const int MOD = 1000000000;

int N;

int dp[102][10];

int f(int len, int digit) {
	if (dp[len][digit] != -1) return dp[len][digit];
	if (len == N) return 1;

	int result = 0;
	if (digit + 1 <= 9) result += f(len + 1, digit + 1);
	if (digit - 1 >= 0) result += f(len + 1, digit - 1);
	result %= MOD;

	return dp[len][digit] = result;
}

int main() {
	scanf("%d", &N);

	memset(dp, -1, sizeof(dp));
	int result = 0;
	for (int d = 1; d <= 9; d++) {
		result += f(1, d);
		result %= MOD;
	}
	printf("%d\n", result);

	return 0;
}
