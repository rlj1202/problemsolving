#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int dr[] = { 1, 0, -1, 0 }; // down, right, up, left
const int dc[] = { 0, 1, 0, -1 };

int N;

ll grid[10][22][22];

void shift(int dir, ll (*grid)[22]) {
    for (int r = dr[dir] > 0 ? 1 : N; 1 <= r && r <= N; r += dr[dir] > 0 ? 1 : -1) {
        for (int c = dc[dir] > 0 ? 1 : N; 1 <= c && c <= N; c += dc[dir] > 0 ? 1 : -1) {
            if (grid[r][c] == 0) continue;

            int t_r = r;
            int t_c = c;

            while (true) {
                t_r += dr[dir];
                t_c += dc[dir];

                if (t_r < 1 || N < t_r) break;
                if (t_c < 1 || N < t_c) break;
                if (grid[t_r][t_c] != 0) break;
            }

            if (t_r < 1 || N < t_r) continue;
            if (t_c < 1 || N < t_c) continue;
            if (grid[t_r][t_c] != grid[r][c]) continue;

            grid[r][c] *= 2;
            grid[t_r][t_c] = 0;
        }
    }

    for (int r = dr[dir] > 0 ? 1 : N; 1 <= r && r <= N; r += dr[dir] > 0 ? 1 : -1) {
        for (int c = dc[dir] > 0 ? 1 : N; 1 <= c && c <= N; c += dc[dir] > 0 ? 1 : -1) {
            if (grid[r][c] != 0) continue;

            int t_r = r;
            int t_c = c;

            while (true) {
                t_r += dr[dir];
                t_c += dc[dir];

                if (t_r < 1 || N < t_r) break;
                if (t_c < 1 || N < t_c) break;
                if (grid[t_r][t_c] != 0) break;
            }

            if (t_r < 1 || N < t_r) continue;
            if (t_c < 1 || N < t_c) continue;
            if (grid[t_r][t_c] == 0) continue;

            grid[r][c] = grid[t_r][t_c];
            grid[t_r][t_c] = 0;
        }
    }
}

ll dfs(int depth) {
    if (depth == 5) {
        ll largest = 0;

        for (int r = 1; r <= N; r++) {
            for (int c = 1; c <= N; c++) {
                largest = max(largest, grid[depth][r][c]);
            }
        }

        return largest;
    }

    ll answer = 0;

    for (int i = 0; i < 4; i++) {
        // Copy the state
        for (int r = 1; r <= N; r++) {
            for (int c = 1; c <= N; c++) {
                grid[depth + 1][r][c] = grid[depth][r][c];
            }
        }

        shift(i, grid[depth + 1]);

        answer = max(answer, dfs(depth + 1));
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            cin >> grid[0][r][c];
        }
    }

    cout << dfs(0) << '\n';

    return 0;
}
