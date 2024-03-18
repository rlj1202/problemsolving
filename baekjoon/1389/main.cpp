#include <bits/stdc++.h>

using namespace std;

int dist[102][102];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    memset(dist, 0x3f, sizeof(dist));

    for (int m = 0; m < M; m++) {
        int a, b;
        cin >> a >> b;

        dist[a][b] = 1;
        dist[b][a] = 1;
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int min_sum = 0x3f3f3f3f;
    int answer = 0;

    for (int n = 1; n <= N; n++) {
        int sum = 0;

        for (int m = 1; m <= N; m++) {
            if (n == m) continue;
            sum += dist[n][m];
        }

        if (min_sum > sum) {
            min_sum = sum;
            answer = n;
        }
    }

    cout << answer << '\n';

    return 0;
}
