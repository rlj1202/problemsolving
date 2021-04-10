#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int dr[] = {1, 0, -1, 0};
const int dc[] = {0, 1, 0, -1};

int map[102][102];

struct state {
    int r, c;
    int cost;

    bool operator <(const state &o) const {
        return cost < o.cost;
    }
    bool operator >(const state &o) const {
        return cost > o.cost;
    }
};

priority_queue<state, vector<state>, greater<state>> q;
int mindistance[102][102];

int main() {
    int M, N;
    scanf("%d %d", &M, &N);
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= M; c++) {
            scanf(" %c", &map[r][c]);
            map[r][c] -= '0';
        }
    }

    memset(mindistance, 0x3f, sizeof(mindistance));

    mindistance[1][1] = 0;
    q.push({ 1, 1, 0 });

    while (!q.empty()) {
        state cur = q.top();
        q.pop();

        for (int i = 0; i < 4; i++) {
            state next = { cur.r + dr[i], cur.c + dc[i] };
            if (next.r < 1 || next.r > N) continue;
            if (next.c < 1 || next.c > M) continue;
            // if (mindistance[next.r][next.c] != -1) continue;

            next.cost = cur.cost + map[next.r][next.c];

            if (mindistance[next.r][next.c] > next.cost) {
                mindistance[next.r][next.c] = next.cost;
                q.push(next);
            }
        }
    }

    printf("%d\n", mindistance[N][M]);

    return 0;
}