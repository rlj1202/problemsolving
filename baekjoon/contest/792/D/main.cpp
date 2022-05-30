#include <cstdio>

using namespace std;

int arr[1003];

int dp[1003][1003 * 7];

int main() {
    int N;
    scanf("%d", &N);
    for (int n = 1; n <= N; n++) {
        scanf("%d", arr + n);
        arr[n] %= 7;
    }

    dp[0][0] = true;

    for (int n = 1; n <= N; n++) {
        for (int i = 0; i < 1003 * 7; i++) {
            dp[n][i] |= dp[n - 1][i];
            if (i >= arr[n]) dp[n][i] |= dp[n - 1][i - arr[n]];
        }
    }

    bool result = false;
    for (int i = 0; i < 1003 * 7; i++) {
        if (i % 7 == 4 && dp[N][i]) {
            result = true;
            break;
        }
    }

    printf("%s\n", result ? "YES" : "NO");

    return 0;
}
