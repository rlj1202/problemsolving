#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> adj[1000006];

int label[1000006];

int visited[1000006];
int visited_flag;
int match[1000006];

void labeling(int parent, int node, bool flag) {
    label[node] = flag;

    for (int next : adj[node]) {
        if (parent == next) continue;

        labeling(node, next, !flag);
    }
}

bool dfs(int node) {
    if (visited[node] == visited_flag) return false;
    visited[node] = visited_flag;

    for (int next : adj[node]) {
        if (!match[next] || dfs(match[next])) {
            match[next] = node;
            return true;
        }
    }

    return false;
}

int main() {
    int N;
    scanf("%d", &N);
    for (int n = 0; n < N - 1; n++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    labeling(-1, 1, true);

    int result = 0;

    for (int n = 1; n <= N; n++) {
        if (label[n]) continue;
        visited_flag++;
        result += dfs(n);
    }

    printf("%d\n", result);

    return 0;
}