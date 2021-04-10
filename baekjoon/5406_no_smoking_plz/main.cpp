#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int INF = 0x3f3f3f3f;

struct edge {
    int cap;
    int flow;
    int node;
    int inv;
};

vector<edge> adj[1000006];

queue<int> q;
bool visited[1000006];
edge *previous[1000006];

int index(int r, int c, int width) {
    return c + (r - 1) * width;
}

void make_edge(vector<edge> *adj, int a, int b, int cap, int cap2 = 0) {
    adj[a].push_back({cap, 0, b, (int) adj[b].size()});
    adj[b].push_back({cap2, 0, a, (int) adj[a].size() - 1});
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int R, C;
        scanf("%d %d", &R, &C);
        int er, ec;
        scanf("%d %d", &er, &ec);
        int kr, kc;
        scanf("%d %d", &kr, &kc);
        er++; ec++;
        kr++; kc++;

        int src = index(er, ec, C);
        int sink = index(kr, kc, C);

        for (int r = 1; r <= R; r++) {
            for (int c = 1; c <= C; c++) {
                adj[index(r, c, C)].clear();
            }
        }
        for (int r = 1; r <= R; r++) {
            for (int c = 1; c <= C - 1; c++) {
                int area;
                scanf("%d", &area);

                if (area == 0) continue;

                int cost = area + 1;
                make_edge(adj, index(r, c, C), index(r, c + 1, C), cost, cost);
            }
        }
        for (int r = 1; r <= R - 1; r++) {
            for (int c = 1; c <= C; c++) {
                int area;
                scanf("%d", &area);

                if (area == 0) continue;

                int cost = area + 1;
                make_edge(adj, index(r, c, C), index(r + 1, c, C), cost, cost);
            }
        }

        int result = 0;

        while (true) {
            memset(visited, 0, sizeof(visited));    
            memset(previous, 0, sizeof(previous));

            visited[src] = true;
            q.push(src);

            while (!q.empty()) {
                int cur = q.front();
                q.pop();

                for (edge e : adj[cur]) {
                    if (e.cap - e.flow <= 0) continue;
                    if (visited[e.node]) continue;

                    visited[e.node] = true;
                    previous[e.node] = &adj[e.node][e.inv];
                    q.push(e.node);
                }
            }

            if (previous[sink] == 0) break;

            int min_flow = INF;
            for (edge *cur = previous[sink]; cur; cur = previous[cur->node]) {
                edge *inv = &adj[cur->node][cur->inv];
                min_flow = min(min_flow, inv->cap - inv->flow);
            }

            for (edge *cur = previous[sink]; cur; cur = previous[cur->node]) {
                edge *inv = &adj[cur->node][cur->inv];

                inv->flow += min_flow;
                cur->flow -= min_flow;
            }

            result += min_flow;
        }

        printf("%d\n", result * 1000);
    }

    return 0;
}