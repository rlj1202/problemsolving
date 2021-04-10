#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int INF = 0x3f3f3f3f;

const int MAX_N = 500;
const int MAX_V = MAX_N * 2 + 2;

int vertex_color[502];
int coin_color[502];

queue<int> q;
int min_dist[502][502];

int cap[MAX_V][MAX_V];
int flow[MAX_V][MAX_V];
int cost[MAX_V][MAX_V];

bool check[MAX_V];
int previous[MAX_V];
int min_cost[MAX_V];

void bfs(vector<int> *adj, int start, int *visited) {
    visited[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : adj[cur]) {
            if (visited[next] != -1) continue;

            visited[next] = visited[cur] + 1;
            q.push(next);
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, M;
        scanf("%d %d", &N, &M);

        vector<int> adj[502];
        for (int m = 0; m < M; m++) {
            int x, y;
            scanf("%d %d", &x, &y);
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        for (int n = 1; n <= N; n++) { // color of vertices
            scanf("%d", vertex_color + n);
        }
        for (int n = 1; n <= N; n++) { // color of coins
            scanf("%d", coin_color + n);
        }

        // find shortest path
        memset(min_dist, -1, sizeof(min_dist));
        for (int n = 1; n <= N; n++) {
            if (!(coin_color[n] == 1 && vertex_color[n] == 0)) continue;
            bfs(adj, n, min_dist[n]);
        }

        // MCMF
        memset(cap, 0, sizeof(cap));
        memset(flow, 0, sizeof(flow));
        memset(cost, 0, sizeof(cost));

        int source = 0;
        int sink = 2 * N + 1;
        vector<int> graph[MAX_V];

        for (int n = 1; n <= N; n++) {
            if (!(coin_color[n] == 1 && vertex_color[n] == 0)) continue;

            graph[source].push_back(n);

            cap[source][n] = 1;

            for (int m = 1; m <= N; m++) {
                if (!(coin_color[m] == 0 && vertex_color[m] == 1)) continue;

                graph[n].push_back(m + N);
                graph[m + N].push_back(n);

                cap[n][m + N] = INF;

                cost[n][m + N] = min_dist[n][m];
                cost[m + N][n] = - cost[n][m + N];
            }
        }
        for (int m = 1; m <= N; m++) {
            graph[m + N].push_back(sink);

            cap[m + N][sink] = 1;
        }

        int result = 0;

        while (true) {
            memset(min_cost, INF, sizeof(min_cost));
            memset(previous, -1, sizeof(previous));

            min_cost[source] = 0;
            q.push(source);

            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                check[cur] = false;

                for (int next : graph[cur]) {
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

            if (previous[sink] == -1) break;

            int min_flow = INF;
            for (int cur = sink; cur != source; cur = previous[cur]) {
                min_flow = min(min_flow, cap[previous[cur]][cur] - flow[previous[cur]][cur]);
            }

            for (int cur = sink; cur != source; cur = previous[cur]) {
                result += min_flow * cost[previous[cur]][cur];
                flow[previous[cur]][cur] += min_flow;
                flow[cur][previous[cur]] -= min_flow;
            }
        }

        // print result
        printf("%d\n", result);
    }
    
    return 0;
}