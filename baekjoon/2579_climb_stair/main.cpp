#include <iostream>
#include <algorithm>

using namespace std;

int N;
int points[302];

// dp[n][k] : n 번째 계단에 왔을 때 바로 앞 계단이 밟혔을 때(k = 1) 최대,
//            앞 계단이 밟히지 않았을 때 (k = 0) 최대 점수.
int dp[302][2];

int main() {
	scanf("%d", &N);

	for (int n = 1; n <= N; n++)
		scanf("%d", points + n);

	dp[1][0] = points[1]; // 첫번째 계단은 앞 계단이 밣혀있든 밟혀있지 않든
	dp[1][1] = points[1]; // 밟을 수 있다.

	for (int n = 2; n <= N; n++) {
		dp[n][1] = dp[n - 2][0] + points[n];
		dp[n][0] = max(dp[n - 1][1], dp[n - 2][0]) + points[n];
	}

	printf("%d\n", dp[N][0]);

	return 0;
}
