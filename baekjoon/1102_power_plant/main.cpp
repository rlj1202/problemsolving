#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

// ex:
// dp[1][YNN] = 0
int dp[17][2 << 16];

int costs[16][16];

int main() {
    // 16
    int N;
    scanf("%d", &N);
    for (int n = 0; n < N; n++) {
        for (int m = 0; m < N; m++) {
            scanf("%d", &costs[n][m]);
        }
    }

    int mask = 0;
    int count = 0;

    for (int n = 0; n < N; n++) {
        char c;
        scanf(" %c", &c);

        if (c == 'Y') {
            count++;
            mask |= 1 << n;
        }
    }
    int P;
    scanf("%d", &P);

    memset(dp, 0x3f, sizeof(dp));
    dp[count][mask] = 0;

    // O(N^3 * 2^N)
    // = 16^3 * 2^16
    // = ‭268,435,456‬
    // = roughly 3e8
    for (int c = count; c < max(P, count); c++) {
        for (int m = 0; m < (2 << N); m++) {
            for (int from = 0; from < N; from++) {
                if (!(m & (1 << from))) continue;

                for (int to = 0; to < N; to++) {
                    if (m & (1 << to)) continue;

                    dp[c + 1][m | (1 << to)] = min(
                        dp[c + 1][m | (1 << to)],
                        dp[c][m] + costs[from][to]
                    );
                }
            }
        }
    }

    int result = 0x3f3f3f3f;

    for (int m = 0; m < (2 << N); m++) {
        result = min(
            result,
            dp[max(P, count)][m]
        );
    }

    // There is only one impossible case when all power plants are off at first.
    printf("%d\n", result != 0x3f3f3f3f ? result : -1);

    return 0;
}