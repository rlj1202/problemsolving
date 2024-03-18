#include <bits/stdc++.h>

using namespace std;

int cnt;

bool recur(int num) {
    if (num < 10) {
        return num % 3 == 0;
    }

    int sum = 0;

    while (num) {
        sum += num % 10;
        num /= 10;
    }
    cnt++;

    return recur(sum);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    string X;
    cin >> X;

    int sum = 0;

    if (X.length() > 1) {
        cnt++;
        for (char c : X) {
            sum += c - '0';
        }
    } else {
        sum = X[0] - '0';
    }

    bool result = recur(sum);

    cout << cnt << '\n';
    cout << (result ? "YES" : "NO") << '\n';

    return 0;
}
