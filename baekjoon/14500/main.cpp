#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int dr[] = {0, 1, 0, -1};
const int dc[] = {1, 0, -1, 0};

int N, M;

int grid[502][502];
int visited[502][502];

int dfs(int r, int c, int len) {
    if (len == 1) {
        return grid[r][c];
    }

    visited[r][c] = true;

    int max_val = 0;

    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr < 0 || nr >= N || nc < 0 || nc >= M) {
            continue;
        }
        if (visited[nr][nc]) {
            continue;
        }

        int result = dfs(nr, nc, len - 1);
        max_val = max(max_val, result);
    }

    visited[r][c] = false;

    if (!max_val) {
        return 0;
    }

    return grid[r][c] + max_val;
}

int main() {
    scanf("%d %d", &N, &M);

    for (int n = 0; n < N; n++) {
        for (int m = 0; m < M; m++) {
            scanf("%d", &grid[n][m]);
        }
    }

    int answer = 0;

    for (int n = 0; n < N; n++) {
        for (int m = 0; m < M; m++) {
            int result = dfs(n, m, 4);

            answer = max(answer, result);
        }
    }

    // up
    for (int n = 1; n < N; n++) {
        for (int m = 1; m < M - 1; m++) {
            answer = max(answer,
                grid[n - 1][m] + grid[n][m - 1] + grid[n][m] + grid[n][m + 1]);
        }
    }

    // down
    for (int n = 0; n < N - 1; n++) {
        for (int m = 1; m < M - 1; m++) {
            answer = max(answer,
                grid[n + 1][m] + grid[n][m - 1] + grid[n][m] + grid[n][m + 1]);
        }
    }

    // left
    for (int n = 1; n < N - 1; n++) {
        for (int m = 1; m < M; m++) {
            answer = max(answer,
                grid[n][m - 1] + grid[n][m] + grid[n - 1][m] + grid[n + 1][m]);
        }
    }

    // right
    for (int n = 1; n < N - 1; n++) {
        for (int m = 0; m < M - 1; m++) {
            answer = max(answer,
                grid[n][m + 1] + grid[n][m] + grid[n - 1][m] + grid[n + 1][m]);
        }
    }

    printf("%d\n", answer);

    return 0;
}