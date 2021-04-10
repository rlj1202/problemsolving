#include <cstdio>
#include <vector>
#include <stack>
#include <cstring>
#include <algorithm>

using namespace std;

int visited[2003];
int visited_cur;
int group[2003];
int group_cur;
stack<int> s;

int dfs(int n, vector<int> *adj, int node) {
    visited[node] = ++visited_cur;
    int lower = visited[node];

    s.push(node);

    for (int next : adj[node]) {
        if (!visited[next]) {
            lower = min(lower, dfs(n, adj, next));
        } else if (!group[next]) {
            lower = min(lower, visited[next]);
        }
    }

    if (lower == visited[node]) {
        group_cur++;

        while (!s.empty()) {
            int poped = s.top();
            s.pop();

            group[poped] = group_cur;

            if (poped == node) break;
        }
    }

    return lower;
}

void scc(int n, vector<int> *adj) {
    memset(visited, 0, sizeof(visited));
    memset(group, 0, sizeof(group));
    visited_cur = 0;
    group_cur = 0;

    for (int i = 1; i <= 2*n; i++) {
        if (visited[i]) continue;

        dfs(n, adj, i);
    }
}

int main() {
    int N, M;
    while (scanf("%d %d", &N, &M) != -1) {
        vector<int> adj[2003];

        for (int m = 0; m < M; m++) {
            int a, b;
            scanf("%d %d", &a, &b);

            if (a < 0) a = -a + N;
            if (b < 0) b = -b + N;

            int na = ((a - 1 + N) % (2*N)) + 1;
            int nb = ((b - 1 + N) % (2*N)) + 1;

            adj[na].push_back(b);
            adj[nb].push_back(a);
        }
        adj[1 + N].push_back(1);

        scc(N, adj);

        bool result = true;

        for (int n = 1; n <= N; n++) {
            if (group[n] == group[n + N]) {
                result = false;
                break;
            }
        }

        printf("%s\n", result ? "yes" : "no");
    }

    return 0;
}