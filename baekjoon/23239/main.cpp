#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll W, H, L;
int squares[100005];

ll dots(ll r) {
    ll result = 0;

    // x^2 + y^2 <= r^2
    // y^2 <= r^2 - x^2
    for (ll i = 0; i <= r; i++) {
        ll max = r*r - i*i;

        int cnt = upper_bound(squares, squares + L + 1, max) - squares;
        result += cnt;
    }

    return result;
}

ll full_dots(ll r) {
    ll result = dots(r);

    return result * 4 - 4*r - 3;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> W >> H >> L;

    for (int r = 1; r <= L; r++) {
        squares[r] = r * r;
    }

    ll answer = 0;

    ll A = min(W, H);
    ll B = max(W, H);

    if (L <= A) {
        answer += full_dots(L) - dots(L);
    } else if (L <= B) {
        answer += full_dots(L) - dots(L);
        answer += dots(L - A) - (L - A + 1);
    } else if (L <= A + B) {
        answer += full_dots(L) - dots(L);
        answer += dots(L - A) - (L - A + 1);
        answer += dots(L - B) - (L - B + 1);
    } else {
        answer += full_dots(L) - dots(L);
        answer += dots(L - A) - (L - A + 1);
        answer += dots(L - B) - (L - B + 1);
        answer -= dots(L - A - B) - (L - A - B + 1) * 2 + 1;
    }

    cout << answer << '\n';

    return 0;
}
