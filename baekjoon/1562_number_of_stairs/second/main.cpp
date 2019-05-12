#include <iostream>
#include <cstring>

using namespace std;

const int MOD = 1000000000;
const int delta[] = {-1, 1};

int N;

long long dp[102][10][(1 << 10) - 1];

long long f(int len, int digit, int mask) {
	if (len > N) return 0;
	if (dp[len][digit][mask] != -1) return dp[len][digit][mask];

	if (len == N) {
		return dp[len][digit][mask] = mask == (1 << 10) - 1;
	} else {
		long long result = 0;

		for (int i = 0; i < 2; i++) {
			int next = digit + delta[i];
			if (next < 0 || 9 < next) continue;

			int digitmask = 1 << next;
			result += f(len + 1, next, mask | digitmask);
			result %= MOD; // XXX
		}

		return dp[len][digit][mask] = result;
	}
}

int main() {
	memset(dp, -1, sizeof(dp));

	scanf("%d", &N);

	long long result = 0;
	for (int d = 1; d <= 9; d++) {
		result += f(1, d, 1 << d);
		result %= MOD; // XXX
	}

	printf("%lld\n", result);

	return 0;
}
