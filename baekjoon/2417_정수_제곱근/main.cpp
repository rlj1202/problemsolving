#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    ull N;
    cin >> N;

    ull l = 0;
    ull r = (1ULL << 32) - 1;

    while (l < r) {
        ull mid = (l + r) / 2;

        if (mid * mid >= N) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << l << '\n';

    return 0;
}
