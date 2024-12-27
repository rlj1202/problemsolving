#include <algorithm>
#include <cstdio>

using namespace std;

const int dr[] = {0, -1, 0, 1};
const int dc[] = {-1, 0, 1, 0};

char grid[55][55];
int visited[55][55];

bool dfs(int r, int c) {
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr < 0 || nc < 0 || !grid[nr][nc])
            continue;
        if (grid[nr][nc] != grid[r][c])
            continue;
        if (visited[nr][nc]) {
            if (visited[nr][nc] < visited[r][c])
                continue;

            return true;
        }

        visited[nr][nc] = visited[r][c] + 1;
        if (dfs(nr, nc)) {
            return true;
        }
    }

    return false;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    for (int n = 0; n < N; n++) {
        scanf("%s", grid[n]);
    }

    bool answer = false;

    for (int n = 0; n < N; n++) {
        for (int m = 0; m < M; m++) {
            if (visited[n][m])
                continue;

            visited[n][m] = 1;
            if (dfs(n, m)) {
                answer = true;
                break;
            }
        }
    }

    printf("%s\n", answer ? "Yes" : "No");

    return 0;
}