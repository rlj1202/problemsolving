#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int dp[100005];

int main() {
    int N;
    scanf("%d", &N);

    memset(dp, 0x3f, sizeof(dp));

    for (int i = 1; i * i <= N; i++) {
        dp[i * i] = 1;

        for (int n = 1; n <= N; n++) {
            if (n - i * i < 1) {
                continue;
            }

            dp[n] = min(dp[n], dp[n - i * i] + 1);
        }
    }

    printf("%d\n", dp[N]);

    return 0;
}
