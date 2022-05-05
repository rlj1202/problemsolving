#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;

struct edge {
    int from, to;
    int weight;

    bool operator<(const edge& o) const {
        return weight > o.weight;
    }
};

int taxes[30004];

vector<edge> adj[1003];

priority_queue<edge> pq;
queue<int> q;
int mindist[1003][30004];
bool closed[1003];

int main() {
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    int S, D;
    scanf("%d %d", &S, &D);

    for (int m = 0; m < M; m++) {
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);

        adj[a].push_back({a, b, w});
        adj[b].push_back({b, a, w});
    }

    for (int k = 1; k <= K; k++) {
        scanf("%d", taxes + k);

        taxes[k] += taxes[k - 1];
    }

    // dijkstra
    memset(mindist, INF, sizeof(mindist));

    mindist[S][0] = 0;
    for (int k = 1; k <= K; k++) mindist[S][k] = 0;
    pq.push({ 0, S, 0 });

    while (!pq.empty()) {
        edge cur = pq.top();
        pq.pop();

        if (closed[cur.to]) continue;

        closed[cur.to] = true;
        for (int k = 0; k <= K; k++) {
            mindist[cur.to][k] = min(mindist[cur.to][k],
                mindist[cur.from][k] + 0);
        }

        for (edge& e : adj[cur.to]) {
            if (closed[e.to]) continue;

            int newdist = cur.weight + e.weight;
            if (mindist[e.to][0] > newdist) {
                mindist[e.to][0] = newdist;
                pq.push({ e.from, e.to, newdist });
            }
        }
    }

    // answer
    for (int k = 0; k <= K; k++) {
        printf("%d\n", mindist[D][k]);
    }

    return 0;
}
