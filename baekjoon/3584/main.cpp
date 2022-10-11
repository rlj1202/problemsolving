#include <bits/stdc++.h>

using namespace std;

const int MAX_LEVEL = 20;

vector<int> adj[10004];
bool has_parent[10004];

int depth[10004];
int lca[10004][MAX_LEVEL + 1];

void dfs(int cur, int prev) {
    depth[cur] = depth[prev] + 1;

    lca[cur][0] = prev;

    for (int level = 1; level <= MAX_LEVEL; level++) {
        lca[cur][level] = lca[lca[cur][level - 1]][level - 1];
    }

    for (int next : adj[cur]) {
        if (next == prev) continue;

        dfs(next, cur);
    }
}

int query(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);

    // Make both level to equal
    for (int level = MAX_LEVEL; level >= 0; level--) {
        if (depth[lca[a][level]] >= depth[b]) {
            a = lca[a][level];
        }
    }

    if (a != b) {
        for (int level = MAX_LEVEL; level >= 0; level--) {
            if (lca[a][level] != lca[b][level]) {
                a = lca[a][level];
                b = lca[b][level];
            }
        }

        a = lca[a][0];
    }

    return a;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;

        memset(has_parent, 0, sizeof(has_parent));
        memset(lca, 0, sizeof(lca));
        memset(depth, 0, sizeof(depth));
        for (int n = 1; n <= N; n++) {
            adj[n].clear();
        }

        for (int n = 0; n < N - 1; n++) {
            int a, b; // parent, child
            cin >> a >> b;

            has_parent[b] = true;

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        int root = -1;
        for (int n = 1; n <= N; n++) {
            if (!has_parent[n]) {
                root = n;
                break;
            }
        }

        dfs(root, 0);

        int A, B;
        cin >> A >> B;

        int answer = query(A, B);
        cout << answer << '\n';
    }

    return 0;
}
