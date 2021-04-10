#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int INF = 0x3f3f3f3f;

const int MAX_N = 100;
const int MAX_V = MAX_N * 2 + 2;

const int SOURCE = 0;
const int SINK = MAX_V - 1;

int cost[MAX_V][MAX_V];
int cap[MAX_V][MAX_V];
int flow[MAX_V][MAX_V];

queue<int> q;
bool check[MAX_V];

int min_cost[MAX_V];
int previous[MAX_V];

int main() {
    // 100, 100
    int N, M;
    scanf("%d %d", &N, &M);
    for (int n = 1; n <= N; n++) {
        // number of books which a person is willing to buy
        int c;
        scanf("%d", &c);
        cap[n][SINK] = c;
    }
    for (int m = 1; m <= M; m++) {
        // number of books which a bookstore has
        int c;
        scanf("%d", &c);
        cap[SOURCE][m + MAX_N] = c;
    }
    for (int m = 1; m <= M; m++) {
        for (int n = 1; n <= N; n++) {
            // cost when a bookstore deliver a book to a person
            scanf("%d", &cost[m + MAX_N][n]);
            cost[n][m + MAX_N] = -cost[m + MAX_N][n];
            cap[m + MAX_N][n] = INF;
        }
    }

    int result = 0;

    while (true) {
        // find shortest path
        memset(min_cost, INF, sizeof(min_cost));
        memset(previous, -1, sizeof(previous));

        min_cost[SOURCE] = 0;
        q.push(SOURCE);

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            check[cur] = false;

            for (int next = 0; next < MAX_V; next++) {
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
            min_flow = min(
                min_flow,
                cap[previous[cur]][cur] - flow[previous[cur]][cur]
            );
        }

        for (int cur = SINK; cur != SOURCE; cur = previous[cur]) {
            result += min_flow * cost[previous[cur]][cur];

            flow[previous[cur]][cur] += min_flow;
            flow[cur][previous[cur]] -= min_flow;
        }
    }

    printf("%d\n", result);

    return 0;
}