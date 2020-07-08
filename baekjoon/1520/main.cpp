#include <cstdio>
#include <queue>

using namespace std;

const int dr[] = {0, 1, 0, -1};
const int dc[] = {1, 0, -1, 0};

struct pos {
    int r, c;
};

int grid[502][502];
int indegrees[502][502];

queue<pos> q;
int count[502][502];

bool in_range(pos &p, int height, int width) {
    return 1 <= p.r && p.r <= height && 1 <= p.c && p.c <= width;
}

int main() {
    int M, N;
    scanf("%d %d", &M, &N);
    for (int r = 1; r <= M; r++)
        for (int c = 1; c <= N; c++)
            scanf("%d", &grid[r][c]);

    for (int r = 1; r <= M; r++) {
        for (int c = 1; c <= N; c++) {
            for (int i = 0; i < 4; i++) {
                pos next = {r + dr[i], c + dc[i]};
                if (!in_range(next, M, N))
                    continue;

                indegrees[r][c] += grid[r][c] < grid[next.r][next.c];
            }
        }
    }

    for (int r = 1; r <= M; r++) {
        for (int c = 1; c <= N; c++) {
            if (indegrees[r][c] == 0) {
                q.push({r, c});
            }
        }
    }

    count[1][1] = 1;

    while (!q.empty()) {
        pos cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            pos next = {cur.r + dr[i], cur.c + dc[i]};
            if (!in_range(next, M, N))
                continue;
            if (grid[cur.r][cur.c] <= grid[next.r][next.c])
                continue;

            count[next.r][next.c] += count[cur.r][cur.c];
            if (--indegrees[next.r][next.c] == 0) {
                q.push(next);
            }
        }
    }

    printf("%d\n", count[M][N]);

    return 0;
}