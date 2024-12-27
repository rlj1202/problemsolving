#include <algorithm>
#include <cstdio>

using namespace std;

int dp[22];

int T[22];
int P[22];

int main() {
    int N;
    scanf("%d", &N);

    for (int n = 0; n < N; n++) {
        scanf("%d %d", T + n, P + n);
    }

    for (int n = N - 1; n >= 0; n--) {
        dp[n] = 0;

        if (n + 1 < N) {
            dp[n] = dp[n + 1];
        }

        int next = n + T[n];
        if (next < N) {
            dp[n] = max(dp[n], dp[next] + P[n]);
        }

        if (next - 1 < N) {
            dp[n] = max(dp[n], P[n]);
        }
    }

    printf("%d\n", dp[0]);

    return 0;
}