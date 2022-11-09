#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

char strs[22][52];

int arr[22];
int lens[22];

int powers[52];

ll fact[22];
ll dp[1 << 15][102];

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;

    for (int n = 0; n < N; n++) {
        cin >> strs[n];
        lens[n] = strlen(strs[n]);
    }

    int K;
    cin >> K;

    fact[0] = 1;
    for (int n = 1; n <= N; n++) {
        fact[n] = fact[n - 1] * n;
    }

    powers[0] = 1;
    for (int i = 1; i <= 50; i++) {
        powers[i] = powers[i - 1] * 10;
        powers[i] %= K;
    }

    for (int n = 0; n < N; n++) {
        int cur = 0;

        for (int i = 0; strs[n][i]; i++) {
            int digit = strs[n][i] - '0';
            cur *= 10;
            cur += digit;
            cur %= K;
        }

        arr[n] = cur;
    }

    dp[0][0] = 1;

    for (int i = 1; i < (1 << N); i++) {
        for (int j = 0; (1 << j) <= i; j++) {
            if ((i & (1 << j)) == 0) continue;

            if ((i ^ (1 << j)) == 0) {
                dp[i][arr[j]] = 1;
                continue;
            }

            int b = 1 << j;
            int a = i - b;

            for (int u = 0; u < K; u++) {
                int r = arr[j] + u * powers[lens[j]];
                r %= K;

                dp[i][r] += dp[a][u] * dp[b][arr[j]];
            }
        }
    }

    ll p = dp[(1 << N) - 1][0];
    ll q = fact[N];

    ll divider = gcd(p, q);
    p /= divider;
    q /= divider;

    if (!p) q = 1;

    cout << p << '/' << q << '\n';

    return 0;
}
