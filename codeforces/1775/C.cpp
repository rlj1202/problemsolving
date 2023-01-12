#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        ll N, X;
        cin >> N >> X;

        if (N == X) {
            cout << N << '\n';
            continue;
        }

        bool possible = (N >= X) && ((X & N) == X);

        int offPos = 0;
        int lower = 0;
        if (possible) {
            ll cur = N ^ X;

            while (cur) {
                offPos++;
                cur >>= 1;
            }

            cur = X;

            while (X > 0 && (cur & 1) == 0) {
                lower++;
                cur >>= 1;
            }

            if ((N >> offPos) & 1) {
                possible = false;
            }

            if (X > 0 && lower < offPos) {
                possible = false;
            }
        }

        if (possible) {
            ll answer = (N ^ (N ^ X)) | ((1LL << offPos) * (N != X));
            cout << answer << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}
