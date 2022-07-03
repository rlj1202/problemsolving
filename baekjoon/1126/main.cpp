#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll arr[60];
ll dp[60][500005];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;
    for (int n = 1; n <= N; n++) {
        cin >> arr[n];
    }

    for (int n = 1; n <= N; n++) {
        dp[n][arr[n]] = arr[n];

        for (int h = 0; h < 500005; h++) {
            dp[n][h] = max(dp[n][h], dp[n - 1][h]);

            if (h + arr[n] < 500005) {
                dp[n][h] = max(dp[n][h], dp[n - 1][h + arr[n]]);
            }

            if (h < arr[n]) {
                ll prev = dp[n - 1][arr[n] - h];
                if (prev) dp[n][h] = max(dp[n][h], prev + h);
            } else {
                ll prev = dp[n - 1][h - arr[n]];
                if (prev) dp[n][h] = max(dp[n][h], prev + arr[n]);
            }
        }
    }

    cout << (dp[N][0] > 0 ? dp[N][0] : -1) << '\n';

    return 0;
}
