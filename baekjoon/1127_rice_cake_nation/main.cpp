#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int INF = 0x3f3f3f3f;

struct edge {
    int cap;
    int flow;
    int node;
    int inv;
};

int grid[52][52];

bool com[52][52];
bool sec[52][52];

queue<int> q;
bool visited[104];
edge *previous[104];

void make_edge(vector<edge> *adj, int a, int b, int cap) {
    adj[a].push_back({cap, 0, b, (int) adj[b].size()});
    adj[b].push_back({0, 0, a, (int) adj[a].size() - 1});
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            char c;
            scanf(" %c", &c);
            grid[i][j] = c - '0';
        }
    }
    int K;
    scanf("%d", &K);
    for (int n = 1; n <= N; n++) {
        int c;
        scanf("%d", &c);
        for (int i = 0; i < c; i++) {
            int secid;
            scanf("%d", &secid);
            sec[n][secid] = true;
        }
    }
    for (int n = 1; n <= N; n++) {
        int c;
        scanf("%d", &c);
        for (int i = 0; i < c; i++) {
            int secid;
            scanf("%d", &secid);
            com[n][secid] = true;
        }
    }

    int result = 0;

    for (int secid = 0; secid < K; secid++) {
        vector<edge> adj[102];
        
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (grid[i][j]) {
                    make_edge(adj, i + N, j, 1);
                    make_edge(adj, i, j + N, 1);
                }
            }

            make_edge(adj, i, i + N, INF);

            if (sec[i][secid]) {
                make_edge(adj, 0, i, INF);
            }
            if (!com[i][secid]) {
                make_edge(adj, i + N, N * 2 + 1, INF);
            }
        }

        int min_cut = 0;

        while (true) {
            memset(visited, 0, sizeof(visited));
            memset(previous, 0, sizeof(previous));

            visited[0] = true;
            q.push(0);

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

            if (previous[N * 2 + 1] == 0) break;

            int min_flow = INF;
            for (edge *cur = previous[N * 2 + 1]; cur; cur = previous[cur->node]) {
                edge *inv = &adj[cur->node][cur->inv];
                min_flow = min(min_flow, inv->cap - inv->flow);
            }

            for (edge *cur = previous[N * 2 + 1]; cur; cur = previous[cur->node]) {
                edge *inv = &adj[cur->node][cur->inv];

                inv->flow += min_flow;
                cur->flow -= min_flow;
            }

            min_cut += min_flow;
        }

        result += min_cut / 2;
    }

    printf("%d\n", result);

    return 0;
}