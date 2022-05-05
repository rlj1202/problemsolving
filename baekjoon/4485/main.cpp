#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int dr[] = { 1, 0, -1, 0 };
const int dc[] = { 0, 1, 0, -1 };

struct state {
    int r, c;
    int dist;

    bool operator<(const state& o) const {
        return dist > o.dist;
    }
};

int map[202][202];
int mindist[202][202];
bool closed[202][202];

priority_queue<state> pq;

int main() {
    int t = 0;

    while (true) {
        t++;

        int N;
        scanf("%d", &N);
        if (N == 0) break;

        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                scanf("%d", &map[r][c]);
            }
        }

        memset(mindist, 0x3f, sizeof(mindist));
        memset(closed, 0, sizeof(closed));

        mindist[0][0] = map[0][0];
        pq.push({ 0, 0, mindist[0][0] });

        while (!pq.empty()) {
            state cur = pq.top();
            pq.pop();

            if (closed[cur.r][cur.c]) continue;
            closed[cur.r][cur.c] = true;

            for (int i = 0; i < 4; i++) {
                int nr = cur.r + dr[i];
                int nc = cur.c + dc[i];
                if (nr < 0 || nr >= N) continue;
                if (nc < 0 || nc >= N) continue;

                if (closed[nr][nc]) continue;

                int newdist = cur.dist + map[nr][nc];

                if (mindist[nr][nc] > newdist) {
                    mindist[nr][nc] = newdist;
                    pq.push({ nr, nc, newdist });
                }
            }
        }

        printf("Problem %d: %d\n", t, mindist[N - 1][N - 1]);
    }

    return 0;
}
