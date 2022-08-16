#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    string S;
    cin >> S;

    int a = 0;
    int b = 0;
    for (int i = 1; S[i]; i++) {
        if (S[i - 1] != S[i]) {
            if (S[i - 1] == '0') {
                a++;
            } else {
                b++;
            }
        }
    }
    if (S.back() == '0') {
        a++;
    } else {
        b++;
    }

    cout << min(a, b) << '\n';

    return 0;
}
