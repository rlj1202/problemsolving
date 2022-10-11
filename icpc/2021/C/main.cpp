#include <bits/stdc++.h>

using namespace std;

map<int, int> jump;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;

    for (int n = 0; n < N; n++) {
        int i, k;
        char j;
        cin >> i >> j >> k;

        int next;

        if (j == 'L') {
            next = i - k;
        } else if (j == 'R') {
            next = i + k;
        }

        jump.insert({ i, next });
    }

    int cur;
    cin >> cur;

    while (jump.count(cur)) {
        cur = jump[cur];
    }

    cout << cur << '\n';

    return 0;
}
