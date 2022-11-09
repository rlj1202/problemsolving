#include <bits/stdc++.h>

using namespace std;

const int MOD = 10'007;

int comb[1003][1003];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, K;
    cin >> N >> K;

    comb[0][0] = 1;
    for (int n = 1; n <= N; n++) {
        comb[n][0] = 1;

        for (int k = 1; k <= K; k++) {
            comb[n][k] = comb[n - 1][k - 1] + comb[n - 1][k];
            comb[n][k] %= MOD;
        }
    }

    cout << comb[N][K] << '\n';

    return 0;
}
