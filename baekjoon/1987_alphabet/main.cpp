#include <cstdio>
#include <algorithm>

using namespace std;

const int dr[] = {1, 0, -1, 0};
const int dc[] = {0, 1, 0, -1};

int R, C;

char map[22][22];
bool visited[26];

int dfs(int r, int c, int dist) {
    int result = dist;

    char cur = map[r][c];
    visited[cur - 'A'] = true;

    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr < 0 || nr >= R) continue;
        if (nc < 0 || nc >= C) continue;
        if (visited[map[nr][nc] - 'A']) continue;

        result = max(result, dfs(nr, nc, dist + 1));
    }

    visited[cur - 'A'] = false;

    return result;
}

int main() {
    scanf("%d %d", &R, &C);
    for (int r = 0; r < R; r++) {
        scanf("%s", map[r]);
    }

    printf("%d\n", dfs(0, 0, 1));

    return 0;
}
