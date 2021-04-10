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

int N;
int cost[502][502];

vector<edge> adj[502 + 2];

queue<int> q;
int level[502 + 2];
int work[502 + 2];
bool visited[502 + 2];

void make_edge(int a, int b, int capA, int capB = 0) {
    adj[a].push_back({capA, 0, b, (int) adj[b].size()});
    adj[b].push_back({capB, 0, a, (int) adj[a].size() - 1});
}

bool bfs() {
    memset(level, 0, sizeof(level));

    level[0] = 1;
    q.push(0);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (edge e : adj[cur]) {
            if (level[e.node]) continue;
            if (e.cap - e.flow <= 0) continue;

            level[e.node] = level[cur] + 1;
            q.push(e.node);
        }
    }

    return level[N + 1];
}

int dfs(int cur, int flow) {
    if (cur == N + 1) return flow;

    for (int &i = work[cur]; i < adj[cur].size(); i++) {
        edge &e = adj[cur][i];

        if (level[cur] + 1 != level[e.node]) continue;
        if (e.cap - e.flow <= 0) continue;

        int min_flow = dfs(e.node, min(flow, e.cap - e.flow));
        if (min_flow) {
            e.flow += min_flow;
            adj[e.node][e.inv].flow -= min_flow;

            return min_flow;
        }
    }

    return 0;
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        int team;
        scanf("%d\n", &team);

        if (team == 1) {
            make_edge(0, i, INF);
        } else if (team == 2) {
            make_edge(i, N + 1, INF);
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

    while (bfs()) {
        memset(work, 0, sizeof(work));

        while (true) {
            int min_flow = dfs(0, INF);
            if (!min_flow) break;
            result += min_flow;
        }
    }

    visited[0] = true;
    q.push(0);

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

    printf("%d\n", result);

    for (int i = 1; i <= N; i++) {
        if (visited[i]) printf("%d ", i);
    }
    printf("\n");
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) printf("%d ", i);
    }
    printf("\n");

    return 0;
}