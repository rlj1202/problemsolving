#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;

    int cur = 1;
    int delta = 6;
    int cnt = 1;
    while (cur < N) {
        cur += delta;
        delta += 6;
        cnt++;
    }

    cout << cnt << '\n';

    return 0;
}
