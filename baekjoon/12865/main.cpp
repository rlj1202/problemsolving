#include <cstdio>
#include <algorithm>

using namespace std;

int weights[102];
int values[102];

int dp[102][100005];

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    for (int n = 1; n <= N; n++) {
        int w, v; // 1e5, 1e3
        scanf("%d %d", &w, &v);
        weights[n] = w;
        values[n] = v;
    }

    for (int n = 1; n <= N; n++) {
        int weight = weights[n];
        int value = values[n];

        for (int i = 0; i <= K; i++) {
            dp[n][i] = dp[n - 1][i];
            if (i - weight >= 0) dp[n][i] = max(dp[n][i], dp[n - 1][i - weight] + value);
        }
    }

    printf("%d\n", dp[N][K]);

    return 0;
}
