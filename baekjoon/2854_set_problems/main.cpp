#include <iostream>
#include <cstring>

using namespace std;

const int MOD = 1e9 + 7;

int N;
int problems[100005];
int amb_problems[100005];

int dp[2][100005];

long long f(bool prev_amb_choosed, int index) {
	if (dp[prev_amb_choosed][index] != -1) return dp[prev_amb_choosed][index];

	if (index == N + 1) return 1;

	long long result = problems[index] + amb_problems[index - 1];
	if (prev_amb_choosed) result--;
	result *= f(false, index + 1);

	result += amb_problems[index] * f(true, index + 1);
	result %= MOD;

	return dp[prev_amb_choosed][index] = result;
}

int main() {
	scanf("%d", &N);
	for (int n = 1; n <= N; n++) scanf("%d", problems + n);
	for (int n = 1; n <= N - 1; n++) scanf("%d", amb_problems + n);

	memset(dp, -1, sizeof(dp));
	printf("%lld\n", f(false, 1));

	return 0;
}
