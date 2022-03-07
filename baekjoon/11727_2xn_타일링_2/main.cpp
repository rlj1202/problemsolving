#include <cstdio>

using namespace std;

const int MOD = 10007;

int dp[1003][3];

int main() {
    int N;
    scanf("%d", &N);

    dp[1][0] = 1;
    dp[2][0] = 1;
    dp[2][1] = 1;
    dp[2][2] = 1;

    for (int w = 3; w <= N + 1; w++) {
        dp[w][0] = dp[w - 1][0] + dp[w - 1][1] + dp[w - 1][2];
        dp[w][1] = dp[w - 2][0] + dp[w - 2][1] + dp[w - 2][2];
        dp[w][2] = dp[w - 2][0] + dp[w - 2][1] + dp[w - 2][2];

        dp[w][0] %= MOD;
        dp[w][1] %= MOD;
        dp[w][2] %= MOD;
    }

    printf("%d\n", dp[N + 1][0]);

    return 0;
}
