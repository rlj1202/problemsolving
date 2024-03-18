#include <bits/stdc++.h>

using namespace std;

int dp[2][42];

void recur(int n) {
    if (n < 2) {
        return;
    }

    if (dp[0][n] != -1 && dp[1][n] != -1) {
        return;
    }

    recur(n - 1);
    recur(n - 2);

    dp[0][n] = dp[0][n - 1] + dp[0][n - 2];
    dp[1][n] = dp[1][n - 1] + dp[1][n - 2];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    memset(dp, -1, sizeof(dp));

    dp[0][0] = 1;
    dp[1][0] = 0;

    dp[0][1] = 0;
    dp[1][1] = 1;

    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;

        recur(N);

        cout << dp[0][N] << ' ' << dp[1][N] << '\n';
    }

    return 0;
}
