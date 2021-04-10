#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

const int INF = 0x3f3f3f3f;

struct edge {
    long long cap;
    long long flow;
    int node;
    int inv;
};

vector<edge> adj[402];

queue<int> q;
bool visited[402];
edge *previous[402];

void make_edge(int a, int b, int c) {
    adj[a].push_back({c, 0, b, (int) adj[b].size()});
    adj[b].push_back({0, 0, a, (int) adj[a].size() - 1});
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    int S, D;
    scanf("%d %d", &S, &D);
    for (int n = 1; n <= N; n++) {
        // 1e7
        int cost;
        scanf("%d", &cost);

        make_edge(n, n + N, cost);
    }
    for (int m = 0; m < M; m++) {
        int a, b;
        scanf("%d %d", &a, &b);

        make_edge(a + N, b, INF);
        make_edge(b + N, a, INF);
    }

    while (true) {
        memset(visited, 0, sizeof(visited));
        memset(previous, 0, sizeof(previous));

        visited[S] = true;
        q.push(S);

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (edge e : adj[cur]) {
                if (visited[e.node]) continue;
                if (e.cap - e.flow <= 0) continue;

                visited[e.node] = true;
                q.push(e.node);

                previous[e.node] = &adj[e.node][e.inv];
            }
        }

        if (previous[D + N] == 0) break;

        long long min_flow = INF;
        for (edge *cur = previous[D + N]; cur; cur = previous[cur->node]) {
            edge inv = adj[cur->node][cur->inv];
            min_flow = min(min_flow, inv.cap - inv.flow);
        }

        for (edge *cur = previous[D + N]; cur; cur = previous[cur->node]) {
            cur->flow -= min_flow;
            adj[cur->node][cur->inv].flow += min_flow;
        }
    }

    memset(visited, 0, sizeof(visited));

    visited[S] = true;
    q.push(S);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (edge e : adj[cur]) {
            if (visited[e.node]) continue;
            if (e.cap - e.flow <= 0) continue;

            visited[e.node] = true;
            q.push(e.node);
        }
    }

    for (int i = 1; i <= N; i++) {
        if (visited[i] && !visited[i + N]) printf("%d ", i);
    }
    printf("\n");

    return 0;
}