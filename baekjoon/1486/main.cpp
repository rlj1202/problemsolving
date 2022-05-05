#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

const int dr[] = { 1, 0, -1, 0 };
const int dc[] = { 0, 1, 0, -1 };

const int INF = 0x3f3f3f3f;

char map[32][32];

struct state {
    int r, c;
    int dist;

    bool operator<(const state& o) const {
        return dist > o.dist;
    }
};

priority_queue<state> pq;
int mindistClimb[32][32];
int mindistDescend[32][32];
bool closed[32][32];

int main() {
    int N, M, T, D;
    scanf("%d %d %d %d", &N, &M, &T, &D);
    for (int n = 0; n < N; n++) {
        scanf("%s", map[n]);

        for (int m = 0; m < M; m++) {
            if ('A' <= map[n][m] && map[n][m] <= 'Z') {
                map[n][m] = map[n][m] - 'A';
            } else {
                map[n][m] = map[n][m] - 'a' + 26;
            }
        }
    }

    memset(mindistClimb, INF, sizeof(mindistClimb));
    memset(mindistDescend, INF, sizeof(mindistDescend));

    mindistClimb[0][0] = 0;
    pq.push({ 0, 0, 0 });
    
    while (!pq.empty()) {
        state cur = pq.top();
        pq.pop();

        if (closed[cur.r][cur.c]) continue;
        closed[cur.r][cur.c] = true;

        for (int i = 0; i < 4; i++) {
            int nr = cur.r + dr[i];
            int nc = cur.c + dc[i];
            if (nr < 0 || nr >= N) continue;
            if (nc < 0 || nc >= M) continue;

            if (closed[nr][nc]) continue;

            int delta = abs(map[cur.r][cur.c] - map[nr][nc]);
            if (delta > T) continue;

            int newdist = mindistClimb[cur.r][cur.c] + (map[cur.r][cur.c] < map[nr][nc] ? delta*delta : 1);
            if (mindistClimb[nr][nc] > newdist) {
                mindistClimb[nr][nc] = newdist;
                pq.push({ nr, nc, newdist });
            }
        }
    }

    memset(closed, 0, sizeof(closed));

    mindistDescend[0][0] = 0;
    pq.push({ 0, 0, 0 });

    while (!pq.empty()) {
        state cur = pq.top();
        pq.pop();

        if (closed[cur.r][cur.c]) continue;
        closed[cur.r][cur.c] = true;

        for (int i = 0; i < 4; i++) {
            int nr = cur.r + dr[i];
            int nc = cur.c + dc[i];
            if (nr < 0 || nr >= N) continue;
            if (nc < 0 || nc >= M) continue;

            if (closed[nr][nc]) continue;

            int delta = abs(map[cur.r][cur.c] - map[nr][nc]);
            if (delta > T) continue;

            int newdist = mindistDescend[cur.r][cur.c] + (map[cur.r][cur.c] <= map[nr][nc] ? 1 : delta*delta);
            if (mindistDescend[nr][nc] > newdist) {
                mindistDescend[nr][nc] = newdist;
                pq.push({ nr, nc, newdist });
            }
        }
    }

    int result = 0;

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            int sum = INF;

            if (mindistClimb[r][c] != INF && mindistDescend[r][c] != INF)
                sum = mindistClimb[r][c] + mindistDescend[r][c];
            
            if (sum > D) continue;
            
            result = max(result, (int) map[r][c]);
        }
    }

    printf("%d\n", result);

    return 0;
}
