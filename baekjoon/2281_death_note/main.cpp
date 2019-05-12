#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M;
int names[1003];

int dp[1003];

int f(int nameidx) {
	if (dp[nameidx] != -1) return dp[nameidx];

	int result = 0x3f3f3f3f;

	int remainspaces = M - names[nameidx];
	int next = nameidx + 1;

	while (remainspaces >= 0) {
		if (next >= N) {
			result = 0;
			break;
		}

		result = min(result, f(next) + remainspaces * remainspaces);

		remainspaces -= names[next] + 1;
		next++;
	}

	return dp[nameidx] = result;
}

int main() {
	scanf("%d %d", &N, &M);
	for (int n = 0; n < N; n++) scanf("%d", names + n);

	memset(dp, -1, sizeof(dp));
	printf("%d\n", f(0));

	return 0;
}
