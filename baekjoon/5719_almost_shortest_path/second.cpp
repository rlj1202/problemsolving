#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int INF = 0x3f3f3f3f;

struct edge {
    int node;
    int len;

    bool operator< (const edge &o) const {
        return len < o.len;
    }
    bool operator> (const edge &o) const {
        return len > o.len;
    }
};

int min_dist[502];
priority_queue<edge, vector<edge>, greater<edge>> pq;

queue<int> q;

void dijkstra(int start, vector<edge> *adj, vector<int> *previous) {
    memset(min_dist, INF, sizeof(min_dist));

    min_dist[start] = 0;
    pq.push({start, 0});

    while (!pq.empty()) {
        edge cur = pq.top();
        pq.pop();
        if (min_dist[cur.node] < cur.len) continue;

        for (edge e : adj[cur.node]) {
            if (e.node == -1) continue;

            int new_dist = min_dist[cur.node] + e.len;

            if (min_dist[e.node] > new_dist) {
                previous[e.node].clear();
                previous[e.node].push_back(cur.node);
                min_dist[e.node] = new_dist;
                pq.push({e.node, new_dist});
            } else if (min_dist[e.node] == new_dist) {
                previous[e.node].push_back(cur.node);
            }
        }
    }
}

int main() {
    while (true) {
        vector<edge> adj[502];
        vector<int> previous[502];

        // 500, 10000
        int N, M;
        scanf("%d %d", &N, &M);
        if (N == 0 && M == 0) break;

        int S, D;
        scanf("%d %d", &S, &D);

        for (int m = 0; m < M; m++) {
            // N, N, 1000
            int u, v, p;
            scanf("%d %d %d", &u, &v, &p);

            adj[u].push_back({v, p});
        }

        dijkstra(S, adj, previous);

        q.push(D);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (int next : previous[cur]) {
                for (edge &e : adj[next]) {
                    if (e.node == cur) {
                        e.node = -1;
                        q.push(next);
                    }
                }
            }
        }
        previous[D].clear();
        
        dijkstra(S, adj, previous);

        printf("%d\n", previous[D].empty() ? - 1 : min_dist[D]);
    }

    return 0;
}