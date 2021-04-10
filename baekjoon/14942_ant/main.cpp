#include <cstdio>
#include <vector>

using namespace std;

struct edge {
    int node;
    int len;
};

int energies[100005];

vector<edge> adj[100005];
int sum[100005];
int parents[100005][20];

void construct(int parent, int node) {
    for (edge e : adj[node]) {
        if (e.node == parent) continue;

        parents[e.node][0] = node;
        for (int i = 1; i < 20; i++) {
            parents[e.node][i] = parents[parents[e.node][i - 1]][i - 1];
        }

        sum[e.node] = e.len + sum[node];
        construct(node, e.node);
    }
}

int main() {
    // 1e5
    int N;
    scanf("%d", &N);
    for (int n = 1; n <= N; n++) {
        // 1e5
        scanf("%d", energies + n);
    }
    for (int n = 1; n <= N - 1; n++) {
        // N, N, 1e4
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    construct(0, 1);

    for (int n = 1; n <= N; n++) {
        int cur = n;

        while (true) {
            int pw = 19;
            while (pw && ((sum[n] - sum[parents[cur][pw]]) >= energies[n] || parents[cur][pw] == 0)) {
                pw--;
            }

            if (parents[cur][pw] == 0) break;
            if ((sum[n] - sum[parents[cur][pw]]) > energies[n]) break;

            cur = parents[cur][pw];
        }

        printf("%d\n", cur);
    }

    return 0;
}