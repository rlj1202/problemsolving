#include <bits/stdc++.h>

using namespace std;

int arr[2003];

int dp[2003][2003];

bool query(int s, int e) {
    if (dp[s][e] != -1) {
        return dp[s][e];
    }

    int len = e - s + 1;

    bool result = false;

    if (len == 1) {
        result = true;
    } else if (len == 2) {
        result = arr[s] == arr[e];
    } else {
        if (arr[s] == arr[e]) {
            result = query(s + 1, e - 1);
        }
    }

    return dp[s][e] = result;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    memset(dp, -1, sizeof(dp));

    int N;
    cin >> N;

    for (int n = 1; n <= N; n++) {
        cin >> arr[n];
    }

    int M;
    cin >> M;

    for (int m = 0; m < M; m++) {
        int s, e;
        cin >> s >> e;

        cout << query(s, e) << '\n';
    }

    return 0;
}
