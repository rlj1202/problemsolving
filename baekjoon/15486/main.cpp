#include <bits/stdc++.h>

using namespace std;

int term[1500006];
long long price[1500006];
long long dp[1500006][2];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;

    for (int n = 1; n <= N; n++) {
        cin >> term[n] >> price[n];
    }

    for (int n = N; n >= 1; n--) {
        if (n + term[n] - 1 > N) {
            dp[n][false] = max(dp[n + 1][false], dp[n + 1][true]);
            continue;
        }

        dp[n][false] = max(dp[n + 1][false], dp[n + 1][true]);
        dp[n][true] = price[n] + max(dp[n + term[n]][false], dp[n + term[n]][true]);
    }

    cout << max(dp[1][false], dp[1][true]) << '\n';

    return 0;
}
