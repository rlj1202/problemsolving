#include <bits/stdc++.h>

using namespace std;

int delta[1003];
int accum[1003];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int N, T;
    cin >> N >> T;

    for (int n = 0; n < N; n++) {
        int K;
        cin >> K;

        for (int k = 0; k < K; k++) {
            int s, e;
            cin >> s >> e;

            delta[s]++;
            delta[e]--;
        }
    }

    int cur = 0;
    for (int i = 0; i < 1003; i++) {
        if (i) accum[i] = accum[i - 1] + cur;
        cur += delta[i];
    }

    int left = 0;
    int t_max = 0;

    for (int i = T; i < 1003; i++) {
        int cur = accum[i] - accum[i - T];
        if (t_max < cur) {
            t_max = cur;
            left = i - T;
        }
    }

    cout << left << ' ' << left + T << '\n';

    return 0;
}
