#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;

struct edge {
    int node;
    int len;

    bool operator> (const edge &o) const {
        return len > o.len;
    }
};

vector<edge> adj[202];

priority_queue<edge, vector<edge>, greater<edge>> pq;
int min_dist[202];

void dijkstra(vector<edge> *adj, int start) {
    memset(min_dist, INF, sizeof(min_dist));

    min_dist[start] = 0;
    pq.push({start, 0});

    while (!pq.empty()) {
        edge cur = pq.top();
        pq.pop();

        if (min_dist[cur.node] < cur.len) continue;

        for (edge e : adj[cur.node]) {
            int new_dist = e.len + min_dist[cur.node];
            if (min_dist[e.node] > new_dist) {
                min_dist[e.node] = new_dist;
                pq.push({e.node, new_dist});
            }
        }
    }
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    for (int m = 0; m < M; m++) {
        int s, e, l;
        scanf("%d %d %d", &s, &e, &l);

        adj[s].push_back({e, l});
        adj[e].push_back({s, l});
    }

    double result = 1e9;

    for (int n = 1; n <= N; n++) {
        dijkstra(adj, n);

        double max_time = 0;
        for (int m = 1; m <= N; m++) {
            for (edge e : adj[m]) {
                if (min_dist[m] > min_dist[e.node]) continue;

                double extra = (e.len - min_dist[e.node] + min_dist[m]) / 2.0;
                max_time = max(max_time, min_dist[e.node] + extra);
            }
        }

        result = min(result, max_time);
    }

    printf("%.1f\n", result);

    return 0;
}