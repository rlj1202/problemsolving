#include <cstdio>

const int MOD = 10007;

using namespace std;

int dp[1003][10];

int main() {
    int N;
    scanf("%d", &N);

    for (int d = 0; d < 10; d++) dp[1][d] = 1;

    for (int w = 2; w <= N + 1; w++) {
        for (int d = 0; d < 10; d++) {
            dp[w][d] = 0;

            for (int i = 0; i <= d; i++) {
                dp[w][d] += dp[w - 1][i];
                dp[w][d] %= MOD;
            }
        }
    }

    printf("%d\n", dp[N + 1][9]);

    return 0;
}
