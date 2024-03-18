#include <bits/stdc++.h>

using namespace std;

long long dp[102];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    for (int n = 4; n <= N; n++) {
        dp[n] = max(dp[n], dp[n - 1] + 1);

        for (int v = 1; v <= n - 3; v++) {
            dp[n] = max(dp[n], dp[n - 2 - v] * (v + 1));
        }
    }

    cout << dp[N] << '\n';

    return 0;
}
