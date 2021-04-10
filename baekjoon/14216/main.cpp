#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

const int INF = 0x3f3f3f3f;

struct edge {
    int cap;
    int flow;
    int cost;
    int node;
    int inv;
};

int N;

vector<edge> adj[1003];

queue<int> q;
bool check[1003];
int min_dist[1003];
edge *previous[1003];

void make_edge(int a, int b, int cap, int cost) {
    adj[a].push_back({cap, 0, cost, b, (int) adj[b].size()});
    adj[b].push_back({0, 0, -cost, a, (int) adj[a].size() - 1});
}


int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        make_edge(0, i, 1, 0);
        make_edge(i + N, N * 2 + 1, 1, 0);

        for (int j = 1; j <= N; j++) {
            int cost; // 1e4
            scanf("%d", &cost);

            make_edge(i, j + N, 1, cost);
        }
    }

    int result = 0;

    while (true) {
        memset(min_dist, INF, sizeof(min_dist));
        memset(previous, 0, sizeof(previous));

        min_dist[0] = 0;
        q.push(0);

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

        if (previous[N * 2 + 1] == 0) break;

        int min_flow = INF;
        for (edge *cur = previous[N * 2 + 1]; cur; cur = previous[cur->node]) {
            edge *inv = &adj[cur->node][cur->inv];
            min_flow = min(min_flow, inv->cap - inv->flow);
        }

        for (edge *cur = previous[N * 2 + 1]; cur; cur = previous[cur->node]) {
            edge *inv = &adj[cur->node][cur->inv];

            result += inv->cost * min_flow;

            inv->flow += min_flow;
            cur->flow -= min_flow;
        }
    }

    printf("%d\n", result);

    return 0;
}