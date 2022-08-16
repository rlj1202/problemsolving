#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int number;
    char op;

    cin >> number;

    int cur = number;

    bool neg = false;

    while (cin >> op) {
        cin >> number;

        if (op == '+') {
            if (neg) cur -= number;
            else cur += number;
        } else if (op == '-') {
            cur -= number;
            neg = true;
        }
    }

    cout << cur << '\n';

    return 0;
}
