#include <bits/stdc++.h>

using namespace std;

int grid[302][302];
int sum[302][302];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int M, N;
    cin >> M >> N;

    for (int r = 1; r <= M; r++) {
        for (int c = 1; c <= N; c++) {
            cin >> grid[r][c];
        }
    }

    for (int r = 1; r <= M; r++) {
        for (int c = 1; c <= N; c++) {
            sum[r][c] = grid[r][c] + sum[r - 1][c] + sum[r][c - 1] - sum[r - 1][c - 1];
        }
    }

    int answer = 0;

    for (int r = 1; r <= M; r++) {
        for (int c = 1; c <= N; c++) {
            for (int h = 1; h <= r; h++) {
                for (int w = 1; w <= c; w++) {
                    int cur = sum[r][c] - sum[r - h][c] - sum[r][c - w] + sum[r - h][c - w];

                    if (cur > 10) break;
                    if (cur == 10) answer++;
                }
            }
        }
    }

    cout << answer << '\n';

    return 0;
}
