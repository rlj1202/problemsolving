#include <bits/stdc++.h>

using namespace std;

int deltas[200005];
int accumMax[200005];
long long accumHeight[200005];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N, Q;
        cin >> N >> Q;

        for (int n = 1; n <= N; n++) {
            cin >> deltas[n];
        }

        memset(accumMax, 0, sizeof(accumMax));
        memset(accumHeight, 0, sizeof(accumHeight));
        for (int n = 1; n <= N; n++) {
            accumMax[n] = max(accumMax[n - 1], deltas[n]);
            accumHeight[n] = accumHeight[n - 1] + deltas[n];
        }

        while (Q--) {
            int K;
            cin >> K;

            int index = upper_bound(accumMax + 1, accumMax + N + 1, K) - accumMax;

            cout << accumHeight[index - 1] << ' ';
        }

        cout << '\n';
    }

    return 0;
}
