#include <iostream>
#include <cstring>

using namespace std;

const int MOD = 9901;

int N;

int dp[100005][3];

int f(int index, int flag) {
	if (dp[index][flag] != -1) return dp[index][flag];
	if (index == N) return 1;

	int result = f(index + 1, 0);
	if (flag != 1) result += f(index + 1, 1);
	if (flag != 2) result += f(index + 1, 2);
	result %= MOD;

	return dp[index][flag] = result;
}

int main() {
	scanf("%d", &N);

	memset(dp, -1, sizeof(dp));
	printf("%d\n", f(0, 0));

	return 0;
}
