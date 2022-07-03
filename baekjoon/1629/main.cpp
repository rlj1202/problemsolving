#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    ll A, B, C;
    cin >> A >> B >> C;

    ll result = 1;
    ll cur = A;
    while (B) {
        if (B & 1) {
            result *= cur;
            result %= C;
        }

        B >>= 1;
        cur *= cur;
        cur %= C;
    }

    cout << result << '\n';

    return 0;
}
