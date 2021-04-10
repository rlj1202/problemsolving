#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

const int INF = 0x3f3f3f3f;

const int MAX_N = 50;
const int MAX_V = MAX_N * MAX_N + 2;

const int SOURCE = 0;
const int SINK = MAX_V - 1;

const int prices[5][5] = {
    { 10,  8,  7,  5,  1 },
    {  8,  6,  4,  3,  1 },
    {  7,  4,  3,  2,  1 },
    {  5,  3,  2,  2,  1 },
    {  1,  1,  1,  1,  0 },
};

const int dr[] = {1, 0, -1, 0};
const int dc[] = {0, 1, 0, -1};

struct point {
    int r, c;

    int get_index() {
        return c + (r - 1) * MAX_N;
    }
};

char grid[MAX_N + 2][MAX_N + 2];

vector<int> adj[MAX_V];

int cap[MAX_V][MAX_V];
int flow[MAX_V][MAX_V];
int cost[MAX_V][MAX_V];

queue<int> q;
bool check[MAX_V];

int min_cost[MAX_V];
int previous[MAX_V];

inline int get_price(point a, point b) {
    char m = grid[a.r][a.c];
    char n = grid[b.r][b.c];
    if (m == 'F') m = 'E';
    if (n == 'F') n = 'E';
    return prices[m - 'A'][n - 'A'];
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    for (int n = 1; n <= N; n++) {
        for (int m = 1; m <= M; m++) {
            scanf(" %c", &grid[n][m]);
        }
    }

    for (int n = 1; n <= N; n++) {
        for (int m = 1; m <= M; m++) {
            point cur = {n, m};

            if ((n + m) % 2 == 0) {
                adj[SOURCE].push_back(cur.get_index());
                adj[cur.get_index()].push_back(SINK);

                cap[SOURCE][cur.get_index()] = 1;
                cap[cur.get_index()][SINK] = 1;

                for (int i = 0; i < 4; i++) {
                    point next = {n + dr[i], m + dc[i]};
                    if (next.r < 1 || N < next.r) continue;
                    if (next.c < 1 || M < next.c) continue;

                    adj[cur.get_index()].push_back(next.get_index());
                    adj[next.get_index()].push_back(cur.get_index());

                    cost[cur.get_index()][next.get_index()]
                        = -get_price(cur, next);
                    cost[next.get_index()][cur.get_index()]
                        = get_price(cur, next);
                    cap[cur.get_index()][next.get_index()]
                        = 1;
                }
            } else {
                adj[cur.get_index()].push_back(SINK);

                cap[cur.get_index()][SINK] = 1;
            }
        }
    }

    int result = 0;

    // O(N*M/2 * N*M)
    while (true) {
        memset(min_cost, INF, sizeof(min_cost));
        memset(previous, -1, sizeof(previous));

        min_cost[SOURCE] = 0;
        q.push(SOURCE);

        int test = 0;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            check[cur] = false;

            for (int next : adj[cur]) {
                if (cap[cur][next] - flow[cur][next] <= 0) continue;

                int new_cost = min_cost[cur] + cost[cur][next];
                if (min_cost[next] > new_cost) {
                    min_cost[next] = new_cost;
                    previous[next] = cur;

                    if (!check[next]) {
                        check[next] = true;
                        q.push(next);
                    }
                }
            }
        }

        if (previous[SINK] == -1) break;

        int min_flow = INF;
        for (int cur = SINK; cur != SOURCE; cur = previous[cur]) {
            min_flow = min(min_flow, cap[previous[cur]][cur] - flow[previous[cur]][cur]);
        }

        for (int cur = SINK; cur != SOURCE; cur = previous[cur]) {
            result += min_flow * cost[previous[cur]][cur];
            flow[previous[cur]][cur] += min_flow;
            flow[cur][previous[cur]] -= min_flow;
        }
    }

    printf("%d\n", -result);

    // for (int n = 1; n <= N; n++) {
    //     for (int m = 1; m <= M; m++) {
    //         for (int i = 1; i <= N; i++) {
    //             for (int j = 1; j <= M; j++) {
    //                 point a = point{n, m};
    //                 point b = point{i, j};
    //                 int f = flow[a.get_index()][b.get_index()];
    //                 if (f > 0) {
    //                     printf("(%d %d) -> (%d %d) : %d, %d\n", n, m, i, j, f, get_price(a, b));
    //                 }
    //             }
    //         }
    //     }
    // }

    return 0;
}