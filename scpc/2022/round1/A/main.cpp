#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int pos[300005];
pii ants[300005];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        for (int n = 0; n < N; n++) {
            cin >> ants[n].second;
            pos[n] = ants[n].second;
        }
        for (int n = 0; n < N; n++) {
            cin >> ants[n].first;
        }

        sort(ants, ants + N);

        ll answer = 0;
        for (int n = 0; n < N; n++) {
            answer += abs(ants[n].second - pos[n]);
        }

        cout << "Case #" << t << '\n';
        cout << answer << '\n';
    }

    return 0;
}
