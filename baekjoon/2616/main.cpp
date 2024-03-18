#include <bits/stdc++.h>

using namespace std;

int arr[50004];
int sum[50004];

int dp[50004][4];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;

    for (int n = 1; n <= N; n++) {
        cin >> arr[n];
        sum[n] = sum[n - 1] + arr[n];
    }

    int len;
    cin >> len;

    for (int n = 1; n <= N; n++) {
        for (int i = 0; i <= 3; i++) {
            dp[n][i] = dp[n - 1][i];

            if (i == 0) continue;
            if (n - len < 0) continue;
            dp[n][i] = max(dp[n][i], dp[n - len][i - 1] + sum[n] - sum[n - len]);
        }
    }

    cout << dp[N][3] << '\n';

    return 0;
}
