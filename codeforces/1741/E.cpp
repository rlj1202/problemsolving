#include <bits/stdc++.h>

using namespace std;

int arr[200005];
int dp[200005];

int left(int l, int n) {
    int len = arr[l];

    if (l + len + 1 <= n) {
        return l + len + 1;
    }

    return -1;
}

int right(int l, int n, int offset) {
    for (int r = offset; r < n; r++) {
        if (l + arr[r] + 1 == r + 1) {
            return r + 1;
        }
    }

    return -1;
}

bool isPossible(int l, int n) {
    if (l >= n) {
        return true;
    }
    if (dp[l] != -1) {
        return dp[l];
    }

    int r;

    if ((r = left(l, n)) != -1) {
        if (isPossible(r, n)) {
            return true;
        }
    }

    r = l;
    while ((r = right(l, n, r)) != -1) {
        if (isPossible(r, n)) {
            return true;
        }
    }
    
    return (dp[l] = false);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        for (int n = 0; n < N; n++) {
            cin >> arr[n];
        }

        memset(dp, -1, sizeof(dp));

        bool answer = isPossible(0, N);

        cout << (answer ? "YES" : "NO") << '\n';
    }

    return 0;
}
