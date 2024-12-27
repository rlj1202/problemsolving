#include <algorithm>
#include <cstdio>

using namespace std;

const int MOD = 1e9 + 9;

int dp[100005][4];

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= 3; i++) {
        dp[i][i] = 1;
    }
    dp[3][1] = 1;
    dp[3][2] = 1;

    for (int n = 4; n <= 100000; n++) {
        for (int i = 1; i <= 3; i++) {
            if (n - i < 0)
                continue;

            for (int j = 1; j <= 3; j++) {
                if (i == j)
                    continue;

                dp[n][i] += dp[n - i][j];
                dp[n][i] %= MOD;
            }
        }
    }

    while (T--) {
        int N;
        scanf("%d", &N);

        int answer = 0;
        for (int i = 1; i <= 3; i++) {
            answer += dp[N][i];
            answer %= MOD;
        }

        printf("%d\n", answer);
    }

    return 0;
}