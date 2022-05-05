#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int INF = 0x3f3f3f3f;

struct edge {
    int from, to;
    int weight;
    int inv;

    bool operator<(const edge& o) const {
        return weight > o.weight;
    }
};

vector<edge> adj[1003];

priority_queue<edge> pq;
int mindist[1003];
bool closed[1003];

void dijkstra(int start) {
    memset(mindist, INF, sizeof(mindist));
    memset(closed, 0, sizeof(closed));

    mindist[start] = 0;
    pq.push({ 0, start, 0 });

    while (!pq.empty()) {
        edge cur = pq.top();
        pq.pop();

        if (closed[cur.to] = true);
        closed[cur.to] = true;

        for (edge& e : adj[cur.to]) {
            int newdist = mindist[cur.to] + e.weight;
            if (mindist[e.to] > newdist) {
                mindist[e.to] = newdist;
                pq.push({ e.from, e.to, newdist });
            }
        }
    }
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M); // 1000, 5000
    for (int m = 0; m < M; m++) {
        int a, b, t;
        scanf("%d %d %d", &a, &b, &t);

        adj[a].push_back({ a, b, t, (int) adj[b].size() });
        adj[b].push_back({ b, a, t, (int) adj[a].size() - 1 });
    }

    dijkstra(1);

    int minResult = mindist[N];
    int maxResult = mindist[N];

    vector<edge*> edges;
    queue<int> q;

    q.push(N);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        int cnt = 0;
        edge* next_edge;

        for (edge& e : adj[cur]) {
            if (mindist[cur] - e.weight == mindist[e.to]) {
                cnt++;
                next_edge = &e;

                q.push(e.to);
            }
        }

        if (cnt == 1) {
            edges.push_back(next_edge);
        }
    }

    for (edge* e : edges) {
        edge& cur = *e;
        edge& inv = adj[cur.to][cur.inv];

        int backup = cur.weight;
        cur.weight = INF;
        inv.weight = INF;

        dijkstra(1);

        minResult = min(minResult, mindist[N]);
        maxResult = max(maxResult, mindist[N]);

        cur.weight = backup;
        inv.weight = backup;
    }

    if (maxResult == INF) {
        printf("-1\n");
    } else {
        printf("%d\n", maxResult - minResult);
    }

    return 0;
}
