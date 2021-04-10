#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int INF = 0x3f3f3f3f;

struct edge {
    int cap;
    int flow;
    int cost;
    int node;
    int inv;
};

queue<int> q;
bool check[2003];
int min_dist[2003];
edge *previous[2003];

void make_edge(vector<edge> *adj, int a, int b, int cost, int cap) {
    adj[a].push_back({cap, 0, cost, b, (int) adj[b].size()});
    adj[b].push_back({0, 0, -cost, a, (int) adj[a].size() - 1});
}

int main() {
    int V, E;
    while (scanf("%d %d", &V, &E) != -1) {
        vector<edge> adj[2003];

        for (int v = 2; v <= V - 1; v++) {
            make_edge(adj, v, v + V, 0, 1);
        }
        make_edge(adj, 1, 1 + V, 0, 2);
        make_edge(adj, V, V + V, 0, 2);
        for (int e = 0; e < E; e++) {
            int a, b, cost;
            scanf("%d %d %d", &a, &b, &cost);

            make_edge(adj, a + V, b, cost, 1);
        }

        int result = 0;

        while (true) {
            // SPFA
            memset(check, 0, sizeof(check));
            memset(min_dist, INF, sizeof(min_dist));
            memset(previous, 0, sizeof(previous));

            min_dist[1] = 0;
            q.push(1);

            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                check[cur] = false;

                for (edge e : adj[cur]) {
                    if (e.cap - e.flow <= 0) continue;

                    int new_dist = min_dist[cur] + e.cost;
                    if (min_dist[e.node] > new_dist) {
                        min_dist[e.node] = new_dist;
                        previous[e.node] = &adj[e.node][e.inv];

                        if (!check[e.node]) {
                            check[e.node] = true;
                            q.push(e.node);
                        }
                    }
                }
            }

            if (previous[V + V] == 0) break;

            int min_flow = INF;
            for (edge *cur = previous[V + V]; cur; cur = previous[cur->node]) {
                edge inv = adj[cur->node][cur->inv];
                min_flow = min(min_flow, inv.cap - inv.flow);
            }

            for (edge *cur = previous[V + V]; cur; cur = previous[cur->node]) {
                edge &inv = adj[cur->node][cur->inv];

                result += min_flow * inv.cost;

                inv.flow += min_flow;
                cur->flow -= min_flow;
            }
        }

        printf("%d\n", result);
    }

    return 0;
}