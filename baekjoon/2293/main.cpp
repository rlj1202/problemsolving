#include <bits/stdc++.h>

using namespace std;

int arr[102];

int dp[10004];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, K;
    cin >> N >> K;

    for (int n = 1; n <= N; n++) {
        cin >> arr[n];
    }

    dp[0] = 1;

    for (int n = 1; n <= N; n++) {
        for (int k = 0; k <= K; k++) {
            if (k - arr[n] >= 0)
                dp[k] += dp[k - arr[n]];
        }
    }

    cout << dp[K] << '\n';

    return 0;
}
