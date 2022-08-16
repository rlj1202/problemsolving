#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> digits;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    char c;
    int digitsum = 0;
    bool zero = false;
    while (cin >> c) {
        int digit = c - '0';
        if (digit == 0) zero = true;
        digits.push_back(digit);
        digitsum += digit;
    }

    if (digitsum % 3 == 0 && zero) {
        sort(digits.begin(), digits.end(), greater<int>());
        for (auto i : digits) cout << i;
        cout << '\n';
    } else {
        cout << -1 << '\n';
    }

    return 0;
}
