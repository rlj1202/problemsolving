#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int INF = 0x3f3f3f3f;

const int dr[] = { 1, 0, -1, 0 };
const int dc[] = { 0, 1, 0, -1 };

struct state {
    int r, c;
    int dist;

    bool operator<(const state& o) const {
        return dist > o.dist;
    }
};

char map[102][102];

priority_queue<state> pq;
bool closed[102][102];

int mindistA[102][102];
int mindistB[102][102];
int mindistC[102][102];

int dijkstra(int h, int w, int (*mindist)[102], pair<int, int> start) {
    memset(closed, 0, sizeof(closed));

    mindist[start.first][start.second] = map[start.first][start.second] == '#';
    pq.push({ start.first, start.second, mindist[start.first][start.second] });

    while (!pq.empty()) {
        state cur = pq.top();
        pq.pop();

        if (closed[cur.r][cur.c]) continue;
        closed[cur.r][cur.c] = true;

        for (int i = 0; i < 4; i++) {
            int nr = cur.r + dr[i];
            int nc = cur.c + dc[i];
            if (nr < 0 || nr >= h) continue;
            if (nc < 0 || nc >= w) continue;

            if (closed[nr][nc]) continue;

            if (map[nr][nc] == '*') continue;

            int newdist = cur.dist;
            if (map[nr][nc] == '#') newdist++;

            if (mindist[nr][nc] > newdist) {
                mindist[nr][nc] = newdist;
                pq.push({ nr, nc, newdist });
            }
        }
    }

    int result = INF;

    for (int r = 0; r < h; r++) {
        for (int c = 0; c < w; c++) {
            if (r != 0 && r != h - 1 && c != 0 && c != w - 1) continue;

            result = min(result, mindist[r][c]);
        }
    }

    return result;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int H, W;
        scanf("%d %d", &H, &W);

        pair<int, int> prisonerA;
        pair<int, int> prisonerB;
        int prisonerCnt = 0;

        for (int h = 0; h < H; h++) {
            scanf("%s", map[h]);

            for (int w = 0; w < W; w++) {
                if (map[h][w] == '$') {
                    if (prisonerCnt == 0) prisonerA = {h, w};
                    if (prisonerCnt == 1) prisonerB = {h, w};
                    prisonerCnt++;
                }
            }
        }

        long long result = INF;

        memset(mindistA, INF, sizeof(mindistA));
        memset(mindistB, INF, sizeof(mindistB));

        int minA = dijkstra(H, W, mindistA, prisonerA);
        int minB = dijkstra(H, W, mindistB, prisonerB);

        result = min(result, (long long) minA + minB);

        for (int h = 0; h < H; h++) {
            for (int w = 0; w < W; w++) {
                if (h != 0 && h != H - 1 && w != 0 && w != W - 1) continue;
                if (map[h][w] == '*') continue;

                memset(mindistC, INF, sizeof(mindistC));

                dijkstra(H, W, mindistC, { h, w });

                for (int r = 0; r < H; r++) {
                    for (int c = 0; c < W; c++) {
                        if (mindistA[r][c] == INF) continue;
                        if (mindistB[r][c] == INF) continue;
                        if (mindistC[r][c] == INF) continue;
                        if (map[r][c] == '*') continue;

                        long long sum = mindistA[r][c] + mindistB[r][c] + mindistC[r][c];
                        if (map[r][c] == '#') sum -= 2;
                        
                        result = min(result, sum);
                    }
                }
            }
        }

        printf("%lld\n", result);
    }

    return 0;
}
