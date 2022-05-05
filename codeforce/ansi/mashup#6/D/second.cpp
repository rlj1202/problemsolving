#include <cstdio>
#include <algorithm>

using namespace std;

int lens[3];
long long arr[3][203];

long long dp[203][203][203]; // dp[i][j][k]

int main() {
    for (int i = 0; i < 3; i++) {
        scanf("%d", lens + i);
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 1; j <= lens[i]; j++) {
            scanf("%lld", arr[i] + j);
        }
    }

    for (int i = 0; i < 3; i++) {
        sort(arr[i] + 1, arr[i] + lens[i] + 1);
    }

    for (int i = 0; i <= lens[0]; i++) {
        for (int j = 0; j <= lens[1]; j++) {
            for (int k = 0; k <= lens[2]; k++) {
                dp[i][j][k] = 0;
                if (i && j)
                    dp[i][j][k] = max(dp[i][j][k], arr[0][i]*arr[1][j] + dp[i-1][j-1][k]);
                if (i && k)
                    dp[i][j][k] = max(dp[i][j][k], arr[0][i]*arr[2][k] + dp[i-1][j][k-1]);
                if (j && k)
                    dp[i][j][k] = max(dp[i][j][k], arr[1][j]*arr[2][k] + dp[i][j-1][k-1]);
                if (i)
                    dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k]);
                if (j)
                    dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k]);
                if (k)
                    dp[i][j][k] = max(dp[i][j][k], dp[i][j][k-1]);
                if (i && j && k)
                    dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][k-1]);
            }
        }
    }

    printf("%lld\n", dp[lens[0]][lens[1]][lens[2]]);

    return 0;
}
