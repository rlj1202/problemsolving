#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

struct pos {
    int r, c;
};

const int dr[] = {0, 1, 0, -1};
const int dc[] = {1, 0, -1, 0};

int N;
int map[102][102];

queue<pos> q;
bool visited[102][102];

bool bfs(int lower, int upper) {
    if (map[1][1] < lower || upper < map[1][1]) {
        return false;
    }

    memset(visited, 0, sizeof(visited));

    q.push({1, 1});
    visited[1][1] = true;

    while (!q.empty()) {
        pos cur = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            pos next = {cur.r + dr[i], cur.c + dc[i]};
            if (next.r < 1 || N < next.r) continue;
            if (next.c < 1 || N < next.c) continue;
            if (visited[next.r][next.c]) continue;
            if (map[next.r][next.c] < lower || upper < map[next.r][next.c]) continue;

            q.push(next);
            visited[next.r][next.c] = true;
        }
    }

    return visited[N][N];
}

int main() {
    scanf("%d", &N);
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            scanf("%d", &map[r][c]);
        }
    }

    int result = 0x3f3f3f3f;

    for (int lower = 0; lower <= 200; lower++) {
        int l = lower;
        int r = 200;
        int mid = (l + r) / 2;

        while (l < r) {
            if (bfs(lower, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }

            mid = (l + r) / 2;
        }

        if (bfs(lower, mid)) result = min(result, mid - lower);
    }

    printf("%d\n", result);

    return 0;
}