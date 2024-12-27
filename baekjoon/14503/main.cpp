#include <algorithm>
#include <cstdio>

const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};

int grid[55][55];

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int r, c, d;
    scanf("%d %d %d", &r, &c, &d);

    for (int n = 0; n < N; n++) {
        for (int m = 0; m < M; m++) {
            scanf("%d", &grid[n][m]);
        }
    }

    int answer = 0;

    while (true) {
        if (grid[r][c] == 0) {
            answer++;
            grid[r][c] = -1;
        }

        bool clean = true;
        for (int i = 0; i < 4; i++) {
            if (grid[r + dr[i]][c + dc[i]] == 0) {
                clean = false;
                break;
            }
        }

        if (clean) {
            int nr = r - dr[d];
            int nc = c - dc[d];

            if (nr < 0 || nr >= N || nc < 0 || nc >= M) {
                break;
            }
            if (grid[nr][nc] == 1) {
                break;
            }

            r = nr;
            c = nc;

            continue;
        }

        d = (d - 1 + 4) % 4;

        int fr = r + dr[d];
        int fc = c + dc[d];

        if (fr < 0 || fr >= N || fc < 0 || fc >= M) {
            continue;
        }

        if (grid[fr][fc] == 0) {
            r = fr;
            c = fc;
        }
    }

    printf("%d\n", answer);

    return 0;
}