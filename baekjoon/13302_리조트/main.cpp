#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

// 1 day = 10000
// 3 day = 25000, coupon 1
// 5 day = 37000, coupon 2
//
// 3 coupon => 1 day

bool banned[102];

int dp[102][4][102];

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    for (int m = 0; m < M; m++) {
        int day;
        scanf("%d", &day);

        banned[day] = true;
    }

    memset(dp, 0x3f, sizeof(dp));
    dp[0][0][0] = 0;

    for (int d = 1; d <= N; d++) {
        for (int t = 0; t < 102; t++) {
            for (int type = 0; type < 4; type++) {
                if (banned[d]) dp[d][0][t] = min(dp[d][0][t], dp[d - 1][type][t]);

                dp[d][1][t] = min(dp[d][1][t], dp[d - 1][type][t] + 10000);
                if (d >= 3) dp[d][2][t] = min(dp[d][2][t], dp[d - 3][type][t] + 25000);
                if (d >= 5) dp[d][3][t] = min(dp[d][3][t], dp[d - 5][type][t] + 37000);

                if (t + 3 < 102) dp[d][1][t] = min(dp[d][1][t], dp[d - 1][type][t + 3]);
                if (d >= 3 && t - 1 >= 0) dp[d][2][t] = min(dp[d][2][t], dp[d - 3][type][t - 1] + 25000);
                if (d >= 5 && t - 2 >= 0) dp[d][3][t] = min(dp[d][3][t], dp[d - 5][type][t - 2] + 37000);
            }
        }
    }

    // for (int type = 0; type < 4; type++) {
    //     for (int t = 0; t < 102; t++) {
    //         for (int d = 1; d <= N; d++) {
    //             int value = dp[d][type][t];
    //             printf("%6d ", value == 0x3f3f3f3f ? -1 : value);
    //         }
    //         printf("\n");
    //     }
    //     printf("\n\n");
    // }

    int result = 0x3f3f3f3f;

    for (int type = 0; type < 4; type++) {
        for (int t = 0; t < 102; t++) {
            result = min(result, dp[N][type][t]);
            // printf("\t%d %d, %d\n", type, t, dp[N][type][t]);
        }
    }

    printf("%d\n", result);

    return 0;
}
