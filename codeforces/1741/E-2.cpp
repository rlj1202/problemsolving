#include <bits/stdc++.h>

using namespace std;

int arr[200005];

int dp[200005];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        for (int n = 1; n <= N; n++) {
            cin >> arr[n];
        }

        memset(dp, -1, sizeof(dp));
        dp[0] = true;

        for (int n = 1; n <= N; n++) {
            // right
            if (n - arr[n] >= 1) {
                dp[n] = dp[n] == true || dp[n - arr[n] - 1] == true;
            }

            // left
            if (dp[n - 1] == true) {
                if (n + arr[n] <= N) {
                    dp[n + arr[n]] = true;
                }
            }
        }

        bool possible = dp[N] == true;

        cout << (possible ? "YES" : "NO") << '\n';
    }

    return 0;
}
