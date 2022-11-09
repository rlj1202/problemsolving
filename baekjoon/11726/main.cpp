#include <bits/stdc++.h>

using namespace std;

const int MOD = 10'007;

int dp[1003];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;

    dp[1] = 1;
    dp[2] = 2;

    for (int l = 3; l <= N; l++) {
        dp[l] = dp[l - 1] + dp[l - 2];
        dp[l] %= MOD;
    }

    cout << dp[N] << '\n';

    return 0;
}
