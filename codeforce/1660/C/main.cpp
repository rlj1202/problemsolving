#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char str[200005];
int dp[200005][2];
int last[26];

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        scanf("%s", str + 1);

        int len = strlen(str + 1);

        memset(dp, 0, sizeof(dp));
        memset(last, 0, sizeof(last));

        for (int i = 1; i <= len; i++) {
            int cur = str[i] - 'a';

            dp[i][false] = max(dp[i - 1][false], dp[i - 1][true]);

            if (last[cur]) {
                dp[i][true] = max(
                    dp[last[cur] - 1][false],
                    dp[last[cur] - 1][true]) + 1;
            }

            last[cur] = i;
        }

        printf("%d\n", len - max(dp[len][false], dp[len][true]) * 2);
    }

    return 0;
}
