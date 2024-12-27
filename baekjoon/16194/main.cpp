#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int arr[1002];

int dp[1002][1002];

int main() {
    int N;
    scanf("%d", &N);

    for (int n = 1; n <= N; n++) {
        scanf("%d", arr + n);
    }

    memset(dp, 0x3f, sizeof(dp));

    for (int i = 1; i <= N; i++) {
        dp[i][0] = 0;

        for (int j = 1; j <= N; j++) {
            dp[i][j] = dp[i - 1][j];

            if (j - i >= 0) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - i] + arr[i]);
                dp[i][j] = min(dp[i][j], dp[i][j - i] + arr[i]);
            }
        }
    }

    printf("%d\n", dp[N][N]);

    return 0;
}