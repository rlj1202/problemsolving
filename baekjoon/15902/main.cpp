#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007LL;

vector<ll> A, B;

ll fac[3003];
ll dp[3003];

ll power(ll n, ll k) {
    ll result = 1;

    ll cur = n % MOD;
    while (k > 0) {
        if (k & 1) {
            result *= cur;
            result %= MOD;
        }

        k >>= 1;
        cur *= cur;
        cur %= MOD;
    }

    return result;
}

ll inv(ll n) {
    return power(n, MOD - 2);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    // input
    ll L, N, M;
    cin >> L;
    cin >> N; A.resize(N); for (ll &a : A) cin >> a;
    cin >> M; B.resize(M); for (ll &b : B) cin >> b;

    // factorial
    fac[0] = 1;
    for (ll i = 1; i <= L; i++) {
        fac[i] = fac[i - 1] * i;
        fac[i] %= MOD;
    }

    // calc dp
    dp[1] = 1;
    dp[2] = 1;

    for (ll length = 3; length <= L; length++) {
        for (ll left = 1; left < length; left += 2) {
            ll right = length - left;

            ll cur = 1;
            cur *= dp[left];
            cur %= MOD;
            cur *= dp[right];
            cur %= MOD;
            cur *= fac[length - 2];
            cur %= MOD;
            cur *= inv(fac[left - 1]);
            cur %= MOD;
            cur *= inv(fac[right - 1]);
            cur %= MOD;

            dp[length] += cur;
            dp[length] %= MOD;
        }
    }

    // split blocks
    ll mincnt = 0;
    ll lsum = 0, rsum = 0;

    vector<ll> blocks;

    while (!B.empty()) {
        rsum += B.back(); B.pop_back();

        while (lsum < rsum && !A.empty()) {
            lsum += A.back(); A.pop_back();
        }

        if (lsum == rsum) {
            blocks.push_back(lsum);
            mincnt += lsum - 1;

            lsum = rsum = 0;
        }
    }

    // calc result
    ll cases = fac[mincnt];

    for (ll block : blocks) {
        cases *= dp[block];
        cases %= MOD;
        cases *= inv(fac[block - 1]);
        cases %= MOD;
    }

    cout << mincnt << ' ' << cases << '\n';

    return 0;
}
