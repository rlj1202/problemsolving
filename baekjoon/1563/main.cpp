#include <cstdio>

using namespace std;

const int MOD = 1e6;

int dp[1003][2][3];

int main() {
    int N;
    scanf("%d", &N);

    dp[0][0][0] = 1;

    for (int n = 1; n <= N; n++) {
        for (int late = 0; late <= 1; late++) {
            for (int absense = 0; absense <= 2; absense++) {
                // normal
                dp[n][late][0] += dp[n - 1][late][absense];
                dp[n][late][0] %= MOD;

                // late
                if (late - 1 >= 0) dp[n][late][0] += dp[n - 1][late - 1][absense];
                dp[n][late][0] %= MOD;

                // absense
                if (absense - 1 >= 0) dp[n][late][absense] += dp[n - 1][late][absense - 1];
                dp[n][late][absense] %= MOD;
            }
        }
    }

    int answer = 0;

    for (int late = 0; late <= 1; late++) {
        for (int absense = 0; absense <= 2; absense++) {
            answer += dp[N][late][absense];
            answer %= MOD;
        }
    }

    printf("%d\n", answer);

    return 0;
}
