#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

vector<char> v;

map<pair<ll, ll>, ll> dp;

ll dfs(int l, int r) {
    if (dp.count({ l, r })) {
        return dp[{ l, r }];
    }

    if (r - l == 0) {
        return 1;
    }
    if (r - l == 2) {
        if (v[l] == '?' && v[l + 1] == ':') {
            return 1;
        } else {
            return 0;
        }
    }

    ll result = 0;

    for (int i = l; i < r - 1; i++) {
        if (v[i] != '?') continue;

        for (int j = i + 1; j < r; j++) {
            result += dfs(l, i) * dfs(i + 1, j) * dfs(j + 1, r);
            result %= MOD;
        }
    }

    return dp[{l, r}] = result;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string str;

    cin >> str;
    for (int i = 1; i < str.length(); i += 2) {
        v.push_back(str[i]);
    }

    ll result = dfs(0, v.size());

    cout << result << '\n';

    return 0;
}
