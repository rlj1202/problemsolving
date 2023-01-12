#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;

        bool result = (a == b + c) || (b == a + c) || (c == a + b);

        cout << (result ? "YES" : "NO") << '\n';
    }

    return 0;
}
