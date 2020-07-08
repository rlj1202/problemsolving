#include <cstdio>
#include <queue>

using namespace std;

struct cell {
    int r, c;
    int height;

    bool operator>(const cell &o) const { return height > o.height; }
};

const int dr[] = {0, 1, 0, -1};
const int dc[] = {1, 0, -1, 0};

priority_queue<cell, vector<cell>, greater<cell>> pq;

int heights[302][302];
bool checked[302][302];

int main() {
    int N, M;
    scanf("%d %d", &M, &N);
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            int height;
            scanf("%d", &height);
            heights[r][c] = height;

            if (r == 0 || c == 0 || r == N - 1 || c == M - 1) {
                pq.push({r, c, height});
                checked[r][c] = true;
            }
        }
    }

    int result = 0;

    while (!pq.empty()) {
        cell cur = pq.top();
        pq.pop();

        for (int i = 0; i < 4; i++) {
            cell next = {cur.r + dr[i], cur.c + dc[i]};
            if (next.r < 0 || next.c < 0 || next.r >= N || next.c >= M)
                continue;
            if (checked[next.r][next.c])
                continue;

            next.height = heights[next.r][next.c];
            if (next.height >= cur.height) {
                pq.push(next);
                checked[next.r][next.c] = true;
            } else {
                result += cur.height - next.height;
                pq.push({next.r, next.c, cur.height});
                checked[next.r][next.c] = true;
            }
        }
    }

    printf("%d\n", result);

    return 0;
}