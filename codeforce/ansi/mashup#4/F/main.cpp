#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int arr[100005];

int dp[100005][6][2];

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, K, Z; // 1e5, 1e5, 5
        scanf("%d %d %d", &N, &K, &Z);
        for (int n = 1; n <= N; n++) {
            scanf("%d", arr + n); // 1e4
        }

        memset(dp, 0, sizeof(dp));

        int result = 0;

        dp[1][0][false] = arr[1];
        dp[1][0][true] = arr[1];

        for (int z = 0; z <= Z; z++) {
            for (int n = 1; n <= N; n++) {
                int remains = K - z*2 - (n - 1);
                if (remains < 0) continue;

                if (n > 1)
                    dp[n][z][false] = max(dp[n - 1][z][true], dp[n - 1][z][false]) + arr[n];

                if (z)
                    dp[n][z][true] = dp[n + 1][z - 1][false] + arr[n];

                if (remains == 0) {
                    result = max(result, max(dp[n][z][false], dp[n][z][true]));
                }
            }
        }

        printf("%d\n", result);
    }

    return 0;
}
