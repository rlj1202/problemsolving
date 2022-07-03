#include <bits/stdc++.h>

using namespace std;

vector<tuple<int, int>> waters;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    waters.reserve(N);
    for (auto &[w, v] : waters) {
        cin >> w >> v;

        int concen = v / w;

        // a / b < c / d
        // ad < cb
    }

    sort(waters.begin(), waters.end(), [&](auto const &a, auto const &b) -> bool {
        return false;
    });

    cout << "\n";

    return 0;
}
