#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int dr[] = { 1, 0, -1, 0 };
const int dc[] = { 0, 1, 0, -1 };

struct point { int r, c; };

char map[1503][1503];
int visited[1503][1503];

int parent[1503 * 1503];

queue<point> waterQueue;
queue<point> iceQueue;

int index(int r, int c) {
    return c + r * 1500;
}

int find(int a) {
    if (parent[a] == -1) return a;
    return parent[a] = find(parent[a]);
}

void merge(int a, int b) {
    int A = find(a);
    int B = find(b);

    if (A == B) return;

    parent[A] = B;
}

int main() {
    int R, C;
    scanf("%d %d", &R, &C);

    point L1 = {-1, -1};
    point L2 = {-1, -1};

    for (int r = 0; r < R; r++) {
        scanf("%s", map[r]);

        for (int c = 0; c < C; c++) {
            if (map[r][c] == 'L') {
                if (L1.r == -1) {
                    L1 = {r, c};
                } else {
                    L2 = {r, c};
                }
            }
        }
    }

    memset(parent, -1, sizeof(parent));

    int visitedGroup = 0;

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (map[r][c] == 'X') continue;
            if (visited[r][c]) continue;

            visitedGroup++;

            waterQueue.push({r, c});
            visited[r][c] = visitedGroup;

            while (!waterQueue.empty()) {
                point cur = waterQueue.front();
                waterQueue.pop();

                for (int i = 0; i < 4; i++) {
                    point next = { cur.r + dr[i], cur.c + dc[i] };
                    if (next.r < 0 || next.r >= R) continue;
                    if (next.c < 0 || next.c >= C) continue;

                    if (visited[next.r][next.c]) continue;

                    if (map[next.r][next.c] != 'X') {
                        waterQueue.push(next);
                        visited[next.r][next.c] = visitedGroup;
                    } else {
                        iceQueue.push(next);
                        visited[next.r][next.c] = visitedGroup;
                    }
                }
            }
        }
    }

    int count = 0;
    bool meet = false;

    while (!meet) {
        if (find(visited[L1.r][L1.c]) == find(visited[L2.r][L2.c])) {
            meet = true;
            break;
        }

        while (!iceQueue.empty()) {
            point cur = iceQueue.front();
            iceQueue.pop();

            for (int i = 0; i < 4; i++) {
                point next = { cur.r + dr[i], cur.c + dc[i] };
                if (next.r < 0 || next.r >= R) continue;
                if (next.c < 0 || next.c >= C) continue;

                if (!visited[next.r][next.c]) continue;

                merge(visited[cur.r][cur.c], visited[next.r][next.c]);
            }

            map[cur.r][cur.c] = '.';

            waterQueue.push(cur);
        }

        while (!waterQueue.empty()) {
            point cur = waterQueue.front();
            waterQueue.pop();

            for (int i = 0; i < 4; i++) {
                point next = { cur.r + dr[i], cur.c + dc[i] };
                if (next.r < 0 || next.r >= R) continue;
                if (next.c < 0 || next.c >= C) continue;

                if (map[next.r][next.c] == 'X') {
                    if (visited[next.r][next.c]) continue;

                    iceQueue.push(next);
                    visited[next.r][next.c] = visited[cur.r][cur.c];
                }
            }
        }

        count++;
    }

    printf("%d\n", count);

    return 0;
}
