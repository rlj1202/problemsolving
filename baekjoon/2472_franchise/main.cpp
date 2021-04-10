#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const char answers[2][4] = {"NO", "YES"};

struct edge {
    int node;
    int cost;

    bool operator >(const edge &o) const {
        return cost < o.cost;
    }
};

int apartments[3];

vector<edge> adj[100005];

priority_queue<edge, vector<edge>, greater<edge>> q;
int mindists[3][100005];

int nodes[3][100005];

void dijkstra(int start, int *mindist, size_t smindist) {
    memset(mindist, 0x3f, smindist);

    mindist[start] = 0;
    q.push({start, 0});

    while (!q.empty()) {
        edge cur = q.top();
        q.pop();

        if (mindist[cur.node] < cur.cost) continue;

        for (edge next : adj[cur.node]) {
            int newdist = cur.cost + next.cost;
            if (mindist[next.node] > newdist) {
                mindist[next.node] = newdist;
                q.push({next.node, newdist});
            }
        }
    }
}

int main() {
    // 1e5
    int N;
    scanf("%d", &N);
    for (int i = 0; i < 3; i++) {
        scanf("%d", apartments + i);
    }
    // number of edges, max degree of vertex is 5.
    int M;
    scanf("%d", &M);
    for (int m = 0; m < M; m++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);

        adj[x].push_back({y, z});
        adj[y].push_back({x, z});
    }

    // O(3 * N log M)
    // = O(N log M)
    for (int i = 0; i < 3; i++) {
        dijkstra(apartments[i], mindists[i], sizeof(mindists[i]));
    }

    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int n = 1; n <= N; n++) printf("%2d ", mindists[i][n]);
        printf("\n");
    }

    for (int i = 0; i < 3; i++) {
        for (int n = 1; n <= N; n++) {
            nodes[i][n] = n;
        }
        sort(nodes[i] + 1, nodes[i] + 1 + N, [&i](int a, int b) -> bool {
            return mindists[i][a] < mindists[i][b];
        });
    }

    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int n = 1; n <= N; n++) printf("%2d ", nodes[i][n]);
        printf("\n");
    }

    // 1e4
    int T;
    scanf("%d", &T);

    // O(T * log N)
    while (T--) {
        int q;
        scanf("%d", &q);

        bool result = false;

        printf("%s\n", answers[result]);
    }

    return 0;
}