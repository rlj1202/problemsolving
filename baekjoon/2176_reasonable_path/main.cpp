#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int INF = 0x3f3f3f3f;

const int V_START = 1;
const int V_TERMINAL = 2;

struct edge {
    int vertex;
    int len;

    bool operator >(const edge &o) const {
        return len > o.len;
    }
};

vector<edge> adj[1003];

priority_queue<edge, vector<edge>, greater<edge>> q;
int min_dist[1003];

int count[1003];

void dijkstra(int start) {
    memset(min_dist, INF, sizeof(min_dist));

    min_dist[start] = 0;
    q.push({start, 0});

    while (!q.empty()) {
        edge cur = q.top();
        q.pop();

        if (min_dist[cur.vertex] < cur.len) continue;

        for (edge e : adj[cur.vertex]) {
            int new_dist = min_dist[cur.vertex] + e.len;
            if (min_dist[e.vertex] > new_dist) {
                min_dist[e.vertex] = new_dist;
                q.push({e.vertex, new_dist});
            }
        }
    }
}

int get_count(int vertex) {
    if (count[vertex] != -1) return count[vertex];

    count[vertex] = 0;

    for (edge e : adj[vertex]) {
        if (min_dist[vertex] >= min_dist[e.vertex]) continue;

        count[vertex] += get_count(e.vertex);
    }

    return count[vertex];
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    for (int m = 0; m < M; m++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    dijkstra(V_TERMINAL);

    memset(count, -1, sizeof(count));
    count[V_START] = 1;

    printf("%d\n", get_count(V_TERMINAL));

    return 0;
}