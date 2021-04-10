#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int INF = 0x3f3f3f;

const int MAX_N = 400;
const int MAX_V = MAX_N * 2 + 2;
const int SOURCE = 0;
const int SINK = MAX_V - 1;

int flow[MAX_V][MAX_V];
int cap[MAX_V][MAX_V];
int adj[MAX_V][MAX_V];

queue<int> q;
bool check[MAX_V];

int min_dist[MAX_V];
int previous[MAX_V];

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    for (int n = 1; n <= N; n++) {
        cap[SOURCE][n] = 1;
    }
    for (int m = 1; m <= M; m++) {
        cap[m + MAX_N][SINK] = 1;
    }
    for (int n = 1; n <= N; n++) {
        int W;
        scanf("%d", &W);

        for (int w = 0; w < W; w++) {
            int work, cost;
            scanf("%d %d", &work, &cost);

            adj[n][work + MAX_N] = cost;
            adj[work + MAX_N][n] = -cost;
            cap[n][work + MAX_N] = INF;
        }
    }

    int result = 0;

    while (true) {
        memset(min_dist, INF, sizeof(min_dist));
        memset(previous, -1, sizeof(previous));

        min_dist[SOURCE] = 0;
        q.push(SOURCE);

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            check[cur] = false;

            for (int next = 0; next < MAX_V; next++) {
                if (cap[cur][next] - flow[cur][next] <= 0) continue;

                int new_dist = min_dist[cur] + adj[cur][next];
                if (min_dist[next] > new_dist) {
                    min_dist[next] = new_dist;
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
            result += min_flow * adj[previous[cur]][cur];
            flow[previous[cur]][cur] += min_flow;
            flow[cur][previous[cur]] -= min_flow;
        }
    }

    int works = 0;
    for (int n = 1; n <= N; n++) {
        works += flow[SOURCE][n];
    }

    printf("%d\n", works); // number of works
    printf("%d\n", result); // min cost

    return 0;
}