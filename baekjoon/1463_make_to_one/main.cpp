#include <iostream>
#include <algorithm>

using namespace std;

const static int INF = 2000000009;

int N;
int dp[1000006];

int solve(int n) {
	if (dp[n] != 0) return dp[n];
	if (n == 1) return 0;
	return (dp[n] = min(
				min(
					n % 3 == 0 ? solve(n / 3) : INF,
					n % 2 == 0 ? solve(n / 2) : INF
				   ),
				solve(n - 1)
				) + 1);
}

int main() {
	scanf("%d", &N);

	printf("%d", solve(N));

	return 0;
}
