#include <cstdio>
#include <unistd.h>
#include <cstring>
#include <algorithm>

using namespace std;

// 1e4 1e4
int N, W;

int circle[2][10004];

//
// dp[c][i]
//
// i
//       c   N
// 0: ###----|
//    ###----|
//       c   N
// 1: ####---|
//    ###----|
//       c   N
// 2: ###----|
//    ####---|
//
int dp[10004][3];

void do_dp(int col = 0) {
    for (int c = col; c < N; c++) {
        dp[c + 1][0] = min(dp[c][1] + 1, dp[c][2] + 1);
        if (circle[0][c] + circle[1][c] <= W)
            dp[c + 1][0] = min(dp[c + 1][0], dp[c][0] + 1);
        if (c - 1 >= col && circle[0][c] + circle[0][c - 1] <= W &&
                      circle[1][c] + circle[1][c - 1] <= W)
            dp[c + 1][0] = min(dp[c + 1][0], dp[c - 1][0] + 2);

        dp[c + 1][1] = dp[c + 1][0] + 1;
        if (circle[0][c + 1] + circle[0][c] <= W)
            dp[c + 1][1] = min(dp[c + 1][1], dp[c][2] + 1);

        dp[c + 1][2] = dp[c + 1][0] + 1;
        if (circle[1][c + 1] + circle[1][c] <= W)
            dp[c + 1][2] = min(dp[c + 1][2], dp[c][1] + 1);
    }
}

int main() {
    // if (!freopen("input2.txt", "r", stdin)) {
    //     printf("File not opened.\n");
    //     return 0;
    // }

    int T;
    scanf("%d", &T);

    while (T--) {
        scanf("%d %d", &N, &W);
        for (int r = 0; r < 2; r++) {
            for (int c = 0; c < N; c++) {
                scanf("%d", &circle[r][c]);
            }
        }

        dp[0][0] = 0;
        dp[0][1] = 1;
        dp[0][2] = 1;

        int result = 0x3f3f3f3f;

        // case0: no tangles
        do_dp();
        result = min(result, dp[N][0]);

        // case1: 0th row tangled
        if (N > 1 && circle[0][0] + circle[0][N - 1] <= W) {
            dp[1][0] = 2;
            dp[1][1] = 3;
            dp[1][2] = (circle[1][0] + circle[1][1] <= W) ? 2 : 3;
            do_dp(1);
            result = min(result, dp[N - 1][2]);
        }

        // case2: 1th row tangled
        if (N > 1 && circle[1][0] + circle[1][N - 1] <= W) {
            dp[1][0] = 2;
            dp[1][1] = (circle[0][0] + circle[0][1] <= W) ? 2 : 3;
            dp[1][2] = 3;
            do_dp(1);
            result = min(result, dp[N - 1][1]);
        }

        // case3: two rows tangled
        if (N > 1 && (circle[0][0] + circle[0][N - 1] <= W) &&
                     (circle[1][0] + circle[1][N - 1] <= W)) {
            dp[1][0] = 2;
            dp[1][1] = 3;
            dp[1][2] = 3;
            do_dp(1);
            result = min(result, dp[N - 1][0]);
        }

        // printf("\t%d %d\n", N, W);
        // for (int i = 0; i < 3; i++) {
        //     for (int c = 0; c <= N; c++) {
        //         printf("%2d ", dp[c][i]);
        //     }
        //     printf("\n");
        // }

        printf("%d\n", result);
    }

    return 0;
}