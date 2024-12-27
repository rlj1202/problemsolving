#include <algorithm>
#include <cstdio>

using namespace std;

const int MOD = 1e9 + 9;

int dp[1000006];

int main() {
    int T;
    scanf("%d", &T);

    dp[0] = 1;
    for (int n = 1; n <= 1000000; n++) {
        for (int i = 1; i <= 3; i++) {
            if (n - i < 0)
                continue;

            dp[n] += dp[n - i];
            dp[n] %= MOD;
        }
    }

    while (T--) {
        int N;
        scanf("%d", &N);

        printf("%d\n", dp[N]);
    }

    return 0;
}