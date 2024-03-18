#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

ll dp[5003];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    dp[0] = 1;

    for (int l = 2; l <= 5000; l += 2) {
        for (int left = 2; left <= l; left += 2) {
            dp[l] += dp[left - 2] * dp[l - left];
            dp[l] %= MOD;
        }
    }

    int T;
    cin >> T;

    while (T--) {
        int L;
        cin >> L;

        cout << dp[L] << '\n';
    }

    return 0;
}
