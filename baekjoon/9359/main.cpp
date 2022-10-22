#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        ll A, B, N;
        cin >> A >> B >> N;

        vector<ll> comp;

        // factorization
        ll temp = N;
        for (int i = 2; i * i <= N; i++) {
            if (temp % i == 0) { // i is prime
                comp.push_back(i);

                while (temp % i == 0) temp /= i;
            }
        }
        if (temp != 1) comp.push_back(temp);

        ll total = B - A + 1;
        ll sub = 0;

        for (int i = 1; i < (1 << comp.size()); i++) {
            int mul = 1;
            int cnt = 0;

            for (int j = 0; j < (int) comp.size(); j++) {
                if (i & (1 << j)) {
                    cnt++;
                    mul *= comp[j];
                }
            }

            if (!cnt) continue;

            int sign = (cnt % 2 == 1) ? 1 : -1;
            sub += sign * ((B / mul) - ((A - 1) / mul));
        }

        ll answer = total - sub;

        cout << "Case #" << t << ": " << answer << '\n';
    }

    return 0;
}
