#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        // 1 2 3 4 5 6 7 8
        // 7 8 1 2 3 4 5 6

        // 1 2 3 4 5
        // 4 5 1 2 3

        if (N == 3) {
            cout << -1 << '\n';
            continue;
        }

        for (int n = 0; n < 2; n++) {
            cout << (N - 2 + (1 - n) + 1) << ' ';
        }
        for (int n = 0; n < N - 2; n++) {
            cout << (n + 1) << ' ';
        }
        cout << '\n';
    }

    return 0;
}
