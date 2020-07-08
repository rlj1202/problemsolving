#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

struct edge {
    int next;
    int limit;
};

vector<edge> adj[10004];
int queue[10004];
bool visited[10004];

bool bfs(int p, int q, int limit) {
    int l = 0;
    int r = 0;
    queue[r++] = p;
    visited[p] = true;

    while (l < r) {
        int cur = queue[l++];

        for (edge e : adj[cur]) {
            if (visited[e.next]) continue;
            if (e.limit < limit) continue;

            queue[r++] = e.next;
            visited[e.next] = true;
        }
    }

    return visited[q];
}

int max_weight(int p, int q) {
    int l = 0;
    int r = 1e9;
    int mid = (l + r) / 2;

    while (l < r) {
        memset(visited, 0, sizeof(visited));
        if (bfs(p, q, mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }

        mid = (l + r + 1) / 2;
    }

    return mid;
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
    int P, Q;
    scanf("%d %d", &P, &Q);

    int result = max_weight(P, Q);
    printf("%d\n", result);

    return 0;
}