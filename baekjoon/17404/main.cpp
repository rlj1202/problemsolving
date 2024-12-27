#include <algorithm>
#include <cstdio>

using namespace std;

const int INF = 0x3f3f3f3f;

int costs[1003][3];

int dp[3][1003][3];

int main() {
    int N;
    scanf("%d", &N);

    for (int n = 0; n < N; n++) {
        for (int i = 0; i < 3; i++) {
            scanf("%d", &costs[n][i]);
        }
    }

    int answer = INF;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j)
                dp[i][0][j] = costs[0][i];
            else
                dp[i][0][j] = INF;
        }

        for (int n = 1; n < N; n++) {
            for (int cur = 0; cur < 3; cur++) {
                dp[i][n][cur] = INF;

                for (int prev = 0; prev < 3; prev++) {
                    if (cur == prev) {
                        continue;
                    }
                    if (n == N - 1 && i == cur) {
                        continue;
                    }

                    dp[i][n][cur] =
                        min(dp[i][n][cur], dp[i][n - 1][prev] + costs[n][cur]);
                }
            }
        }

        for (int j = 0; j < 3; j++) {
            answer = min(answer, dp[i][N - 1][j]);
        }
    }

    printf("%d\n", answer);

    return 0;
}
