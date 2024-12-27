#include <bits/stdc++.h>

using namespace std;

const int dr[] = {0, 0, 0, -1, 1};
const int dc[] = {0, 1, -1, 0, 0};

int grid[22][22];
int dice[4][4];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    int x, y;
    int K;
    cin >> N >> M;
    cin >> x >> y;
    cin >> K;

    for (int n = 0; n < N; n++) {
        for (int m = 0; m < M; m++) {
            cin >> grid[n][m];
        }
    }

    for (int k = 0; k < K; k++) {
        int cmd;
        cin >> cmd;

        int nx = x + dr[cmd];
        int ny = y + dc[cmd];

        if (nx < 0 || nx >= N) {
            continue;
        }
        if (ny < 0 || ny >= M) {
            continue;
        }

        x = nx;
        y = ny;

        int new_dice[4][4];
        memcpy(new_dice, dice, sizeof(dice));

        if (dr[cmd]) {
            for (int i = 0; i < 4; i++) {
                new_dice[i][0] = dice[(i - dr[cmd] + 4) % 4][0];
            }
            new_dice[0][2] = new_dice[2][0];
        } else if (dc[cmd]) {
            for (int j = 0; j < 4; j++) {
                new_dice[0][j] = dice[0][(j - dc[cmd] + 4) % 4];
            }
            new_dice[2][0] = new_dice[0][2];
        }

        memcpy(dice, new_dice, sizeof(new_dice));

        if (!grid[x][y]) {
            grid[x][y] = dice[2][0];
        } else {
            dice[2][0] = grid[x][y];
            dice[0][2] = grid[x][y];
            grid[x][y] = 0;
        }

        cout << dice[0][0] << '\n';
    }

    return 0;
}
