#include <cstdio>
#include <algorithm>

using namespace std;

char arr[1003];

int dp[1003];

int main() {
    int N;
    scanf("%d", &N);
    scanf("%s", arr);

    for (int i = 1; i < N; i++) {
        dp[i] = 0x3f3f3f3f;

        char target;
        if (arr[i] == 'B') target = 'J';
        if (arr[i] == 'O') target = 'B';
        if (arr[i] == 'J') target = 'O';

        for (int j = 0; j < i; j++) {
            if (arr[j] != target) continue;

            int delta = i - j;

            dp[i] = min(dp[i], dp[j] + delta * delta);
        }
    }

    printf("%d\n", dp[N - 1] == 0x3f3f3f3f ? -1 : dp[N - 1]);

    return 0;
}
