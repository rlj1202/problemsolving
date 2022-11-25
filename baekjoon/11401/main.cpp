#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

ll fact(ll n) {
    ll result = 1;

    for (int i = 1; i <= n; i++) {
        result *= i;
        result %= MOD;
    }

    return result;
}

ll pow(ll n, ll k) {
    ll result = 1;

    ll remains = k;
    ll cur = n;
    while (remains) {
        if (remains & 1) {
            result *= cur;
            result %= MOD;
        }

        remains >>= 1;
        cur = cur * cur;
        cur %= MOD;
    }

    return result;
}

ll inv(ll n) {
    return pow(n, MOD - 2);
}

ll comb(ll n, ll k) {
    ll result = fact(n);

    result *= inv(fact(n - k));
    result %= MOD;
    result *= inv(fact(k));
    result %= MOD;

    return result;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    ll N, K;
    cin >> N >> K;

    cout << comb(N, K) << '\n';

    return 0;
}
