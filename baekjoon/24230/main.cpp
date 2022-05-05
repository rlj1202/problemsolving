#include <cstdio>
#include <vector>

using namespace std;

int color[200005];

vector<int> adj[200005];

int dfs(int parent, int node) {
    int result = 0;

    if (color[node] && color[parent] != color[node]) result++;

    for (int next : adj[node]) {
        if (next == parent) continue;

        result += dfs(node, next);
    }

    return result;
}

int main() {
    int N;
    scanf("%d", &N);
    for (int n = 1; n <= N; n++) {
        scanf("%d", color + n);
    }
    for (int n = 0; n < N - 1; n++) {
        int a, b;
        scanf("%d %d", &a, &b);
        
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    printf("%d\n", dfs(0, 1));

    return 0;
}
