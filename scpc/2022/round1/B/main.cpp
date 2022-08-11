#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const ll MOD = 1e9 + 7;

ll arr[500005];
ll fact[500005];

ll power(ll n, ll k) {
    ll result = 1;
    ll cur = n;
    while (k) {
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

ll comb(ll n, ll k) {
    ll result = 1;
    result *= fact[n];
    result *= inv(fact[n - k]);
    result %= MOD;
    result *= inv(fact[k]);
    result %= MOD;
    return result;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    
    fact[0] = 1;
    for (int i = 1; i < 500005; i++) {
        fact[i] = fact[i - 1] * i;
        fact[i] %= MOD;
    }

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int N, K;
        cin >> N >> K;

        for (int n = 0; n < N; n++) {
            cin >> arr[n];
        }

        ll total = 0;
        for (int n = 0; n < N; n++) total += arr[n];

        ll answer = 0;
        
        if (total % K == 0) {
            if (total == 0) {
                int zeros = 0;
                ll cur = 0;
                for (int n = 0; n < N; n++) {
                    cur += arr[n];
                    if (cur == 0) zeros++;
                }

                answer = comb(zeros - 1, K - 1);
            } else {
                ll subsum = total / K;
            
                map<ll, ll> counts;
                counts[0] = 1;
            
                ll cur = 0;
                for (int n = 0; n < N; n++) {
                    cur += arr[n];
                    counts[cur] += counts[cur - subsum];
                    counts[cur] %= MOD;
                }
            
                answer = counts[total - subsum];
            }
        }

        cout << "Case #" << t << endl;
        cout << answer << endl;
    }

    return 0;
}
