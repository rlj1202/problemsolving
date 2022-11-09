#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int arr[102];

int dp[102][10004];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, K;
    cin >> N >> K;

    for (int n = 1; n <= N; n++) {
        cin >> arr[n];
    }

    memset(dp, INF, sizeof(dp));

    dp[0][0] = 0;

    for (int n = 1; n <= N; n++) {
        for (int k = 0; k <= K; k++) {
            dp[n][k] = dp[n - 1][k];
            if (k - arr[n] >= 0)
                dp[n][k] = min(dp[n][k], dp[n][k - arr[n]] + 1);
        }
    }

    if (dp[N][K] != INF) cout << dp[N][K] << '\n';
    else cout << -1 << '\n';

    return 0;
}
