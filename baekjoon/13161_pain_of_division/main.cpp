#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int INF = 0x3f3f3f3f;

struct edge {
    int cap;
    int flow;
    int node;
    int inv;
};

int team[502];
int cost[502][502];

vector<edge> adj[502 + 2];

queue<int> q;
bool visited[502 + 2];
edge *previous[502 + 2];

void make_edge(int a, int b, int capA, int capB = 0) {
    adj[a].push_back({capA, 0, b, (int) adj[b].size()});
    adj[b].push_back({capB, 0, a, (int) adj[a].size() - 1});
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d\n", team + i);

        if (team[i]) {
            if (team[i] == 1) {
                make_edge(0, i, INF);
            } else if (team[i] == 2) {
                make_edge(i, N + 1, INF);
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < i; j++) {
            make_edge(i, j, cost[i][j], cost[i][j]);
        }
    }

    int result = 0;

    while (true) {
        memset(visited, 0, sizeof(visited));
        memset(previous, 0, sizeof(previous));

        visited[0] = true;
        q.push(0);

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (edge e : adj[cur]) {
                if (visited[e.node]) continue;
                if (e.cap - e.flow <= 0) continue;

                previous[e.node] = &adj[e.node][e.inv];

                visited[e.node] = true;
                q.push(e.node);
            }
        }

        if (previous[N + 1] == 0) break;

        int min_flow = INF;
        for (edge *cur = previous[N + 1]; cur; cur = previous[cur->node]) {
            edge &inv = adj[cur->node][cur->inv];
            min_flow = min(min_flow, inv.cap - inv.flow);
        }

        for (edge *cur = previous[N + 1]; cur; cur = previous[cur->node]) {
            cur->flow -= min_flow;
            adj[cur->node][cur->inv].flow += min_flow;
        }

        result += min_flow;
    }

    memset(visited, 0, sizeof(visited));

    visited[0] = true;
    q.push(0);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (edge e : adj[cur]) {
            if (e.cap - e.flow <= 0) continue;
            if (visited[e.node]) continue;

            visited[e.node] = true;
            q.push(e.node);

            team[e.node] = 1;
        }
    }

    printf("%d\n", result);

    for (int i = 1; i <= N; i++) {
        if (team[i] == 1) printf("%d ", i);
    }
    printf("\n");
    for (int i = 1; i <= N; i++) {
        if (team[i] != 1) printf("%d ", i);
    }
    printf("\n");

    return 0;
}