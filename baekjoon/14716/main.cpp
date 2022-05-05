#include <cstdio>
#include <queue>

using namespace std;

const int dr[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
const int dc[] = { 1, 1, 0, -1, -1, -1, 0, 1 };

struct point {
    int r, c;
};

int grid[302][302];
bool visited[302][302];

queue<point> q;

int main() {
    int M, N;
    scanf("%d %d", &M, &N);

    for (int m = 1; m <= M; m++) {
        for (int n = 1; n <= N; n++) {
            scanf("%d", &grid[m][n]);
        }
    }

    int answer = 0;

    for (int m = 1; m <= M; m++) {
        for (int n = 1; n <= N; n++) {
            if (grid[m][n] == 0) continue;
            if (visited[m][n]) continue;

            answer++;

            visited[m][n] = true;
            q.push({ m, n });

            while (!q.empty()) {
                point cur = q.front();
                q.pop();

                for (int i = 0; i < 8; i++) {
                    point next = { cur.r + dr[i], cur.c + dc[i] };

                    if (grid[next.r][next.c] == 0) continue;
                    if (visited[next.r][next.c]) continue;

                    visited[next.r][next.c] = true;
                    q.push(next);
                }
            }
        }
    }

    printf("%d\n", answer);

    return 0;
}
