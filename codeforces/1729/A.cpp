#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T;
    cin >> T;
    
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;

        int x = a;
        int y = abs(b - c) + c;

        if (x < y) {
            cout << 1 << '\n';
        } else if (x > y) {
            cout << 2 << '\n';
        } else {
            cout << 3 << '\n';
        }
    }

    return 0;
}
