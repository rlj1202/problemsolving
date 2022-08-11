#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

char grid[2003][2003];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        for (int r = 0; r < N; r++) {
            cin >> grid[r];
        }

        ll answer = 0;

        cout << "Case #" << t << '\n';
        cout << answer << '\n';
    }

    cout << '\n';

    return 0;
}
