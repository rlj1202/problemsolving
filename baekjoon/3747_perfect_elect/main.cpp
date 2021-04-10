#include <cstdio>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

int visited[2003];
int visited_cur;
int group[2003];
int group_cur;

stack<int> s;

int dfs(vector<int> *adj, int node) {
    visited[node] = ++visited_cur;
    int lower = visited[node];

    s.push(node);

    for (int next : adj[node]) {
        if (!visited[next]) {
            lower = min(lower, dfs(adj, next));
        } else if (!group[next]) {
            lower = min(lower, visited[next]);
        }
    }

    if (lower == visited[node]) {
        group_cur++;

        while (!s.empty()) {
            int popped = s.top();
            s.pop();

            group[popped] = group_cur;

            if (popped == node) break;
        }
    }

    return lower;
}

int main() {
    int N, M;
    while (scanf("%d %d", &N, &M) != -1) {
        vector<int> adj[2003];

        for (int m = 0; m < M; m++) {
            int i, j;
            scanf("%d %d", &i, &j);

            if (i < 0) i = -i + N;
            if (j < 0) j = -j + N;

            int ni = (i - 1 + N) % (N*2) + 1;
            int nj = (j - 1 + N) % (N*2) + 1;

            adj[ni].push_back(j);
            adj[nj].push_back(i);
        }

        memset(visited, 0, sizeof(visited));
        memset(group, 0, sizeof(group));
        visited_cur = group_cur = 0;

        for (int n = 1; n <= N*2; n++) {
            if (!visited[n]) dfs(adj, n);
        }

        bool result = true;

        for (int n = 1; n <= N; n++) {
            if (group[n] == group[n + N]) {
                result = false;
                break;
            }
        }

        printf("%d\n", result);
    }

    return 0;
}