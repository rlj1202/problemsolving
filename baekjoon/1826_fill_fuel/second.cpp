#include <bits/stdc++.h>

using namespace std;

struct station {
    int pos, fule;

    bool operator<(const station &o) const {
        return pos < o.pos;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;

    vector<station> stations(N);

    for (auto &[pos, fule] : stations) {
        cin >> pos >> fule;
    }

    int L, P;
    cin >> L >> P;

    int cur = P;

    int cnt = 0;

    priority_queue<int> pq;

    for (auto [pos, fule] : stations) {
    }

    cout << cnt << '\n';

    return 0;
}
