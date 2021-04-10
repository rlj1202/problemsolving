#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int INF = 0x3f3f3f3f;

struct edge {
    int cap;
    int flow;
    int cost;
    int node;
    int inv;
};

int A[52][52]; // number of people
int B[52][52]; // cost

vector<edge> adj[102];

queue<int> q;
int min_dist[102];
bool check[102];
edge *previous[102];

void make_edge(int a, int b, int cap, int cost) {
    adj[a].push_back({cap, 0, cost, b, (int) adj[b].size()});
    adj[b].push_back({0, 0, -cost, a, (int) adj[a].size() - 1});
}

int main() {
    int N, P;
    scanf("%d %d", &N, &P);
    for (int i = 1; i <= N - 1; i++) {
        for (int j = i + 1; j <= N; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    for (int i = 1; i <= N - 1; i++) {
        for (int j = i + 1; j <= N; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    for (int i = 1; i <= N - 1; i++) {
        make_edge(i + N, i + 1 + N, INF, 0);
        make_edge(i    , i + 1 + N, INF, 0);

        for (int j = i + 1; j <= N; j++) {
            make_edge(i, j, A[i][j], -B[i][j]);
        }
    }
    for (int i = 1; i <= N; i++) {
        make_edge(i + N, i, INF, 0);
    }
    make_edge(0, 1 + N, P, 0);

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

        if (previous[N] == 0) break;

        int min_flow = INF;
        for (edge *cur = previous[N]; cur; cur = previous[cur->node]) {
            edge inv = adj[cur->node][cur->inv];
            min_flow = min(min_flow, inv.cap - inv.flow);
        }

        for (edge *cur = previous[N]; cur; cur = previous[cur->node]) {
            edge *inv = &adj[cur->node][cur->inv];

            inv->flow += min_flow;
            cur->flow -= min_flow;

            result += min_flow * inv->cost;
        }
    }

    printf("%d\n", -result);

    return 0;
}