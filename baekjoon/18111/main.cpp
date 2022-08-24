#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int grid[502][502];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, M, B;
    cin >> N >> M >> B;

    for (int n = 0; n < N; n++) {
        for (int m = 0; m < M; m++) {
            cin >> grid[n][m];
        }
    }

    int min_time = 0x7f7f7f7f;
    int height = 0;

    for (int h = 0; h <= 256; h++) {
        int positives = 0;
        int negatives = 0;

        for (int n = 0; n < N; n++) {
            for (int m = 0; m < M; m++) {
                int delta = h - grid[n][m];

                if (delta > 0) {
                    positives += delta;
                } else if (delta < 0) {
                    negatives += -delta;
                }
            }
        }

        int remains = -positives + negatives + B;

        if (remains >= 0) {
            int time = positives + negatives * 2;

            if (min_time >= time) {
                min_time = time;
                height = h;
            }
        }
    }

    cout << min_time << ' ' << height << '\n';

    return 0;
}
