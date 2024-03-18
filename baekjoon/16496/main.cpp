#include <bits/stdc++.h>

using namespace std;

string strs[1003];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;

    for (int n = 0; n < N; n++) {
        cin >> strs[n];
    }

    bool allZeros = true;
    for (int n = 0; n < N; n++) {
        if (strs[n] != "0") {
            allZeros = false;
            break;
        }
    }

    if (allZeros) {
        cout << "0\n";
        return 0;
    }

    sort(strs, strs + N, [](string &a, string &b) -> bool {
        return (a + b) < (b + a);
    });

    for (int n = 0; n < N; n++) {
        cout << strs[N - n - 1];
    }

    cout << '\n';

    return 0;
}
