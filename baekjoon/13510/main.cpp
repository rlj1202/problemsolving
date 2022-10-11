#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int MAX_LEVEL = 20;
const int INF = 0x3f3f3f3f;

struct seg {
    int tree[100005 * 4];
    int limit;

    void init(int n) {
        for (limit = 1; limit <= n; limit <<= 1);
        memset(tree, 0, sizeof(tree));
    }

    void update(int i, int v) {
        i += limit - 1;
        tree[i] = v;

        while (i > 1) {
            i >>= 1;
            tree[i] = max(tree[2*i], tree[2*i + 1]);
        }
    }

    int query(int i, int j) {
        i += limit - 1;
        j += limit - 1;

        int result = -INF;
        while (i < j) {
            if (i % 2 == 1) result = max(result, tree[i++]);
            if (j % 2 == 0) result = max(result, tree[j--]);

            i >>= 1;
            j >>= 1;
        }
        if (i == j) result = max(result, tree[i]);

        return result;
    }
} seg;

pii edges[100005];
int depth[100005];
int cost[100005];

int volume[100005];

int lca[100005][MAX_LEVEL + 1];

int order[100005];
int order_cur;

int head[100005];
int comp[100005];
int comp_cur;

vector<pii> adj[100005];

void dfs(int cur, int prev) {
    depth[cur] = depth[prev] + 1;
    lca[cur][0] = prev;
    volume[cur] = 1;

    for (int level = 1; level <= MAX_LEVEL; level++) {
        lca[cur][level] = lca[lca[cur][level - 1]][level - 1];
    }

    for (auto [next, weight] : adj[cur]) {
        if (next == prev) continue;

        dfs(next, cur);

        volume[cur] += volume[next];
        cost[next] = weight;
    }
}

void hld(int cur, int prev) {
    order[cur] = ++order_cur;

    sort(adj[cur].begin(), adj[cur].end(), [](const pii &a, const pii &b) {
        return volume[a.first] > volume[b.first];
    });

    int heavy = -1;

    // Heavy edge
    for (auto [next, weight] : adj[cur]) {
        if (next == prev) continue;

        heavy = next;

        comp[next] = comp[cur];

        hld(next, cur);

        break;
    }
    
    // Light edge
    for (auto [next, weight] : adj[cur]) {
        if (next == prev) continue;
        if (next == heavy) continue;

        comp[next] = ++comp_cur;
        head[comp_cur] = next;

        hld(next, cur);
    }
}

int get_lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    // depth[u] > depth[v]

    for (int level = MAX_LEVEL; level >= 0; level--) {
        if (depth[lca[u][level]] >= depth[v]) {
            u = lca[u][level];
        }
    }

    if (u != v) {
        for (int level = MAX_LEVEL; level >= 0; level--) {
            if (lca[u][level] != lca[v][level]) {
                u = lca[u][level];
                v = lca[v][level];
            }
        }

        u = lca[u][0];
    }

    return u;
}

void update(int idx, int val) {
    if (depth[edges[idx].first] > depth[edges[idx].second]) {
        swap(edges[idx].first, edges[idx].second);
    }

    seg.update(order[edges[idx].second], val);
}

int sub_query(int u, int v) {
    int result = 0;

    while (comp[u] != comp[v]) {
        int u_head = head[comp[u]];
        int v_head = head[comp[v]];

        if (depth[u_head] > depth[v_head]) {
            result = max(result, seg.query(order[u_head], order[u]));
            u = lca[u_head][0];
        } else {
            result = max(result, seg.query(order[v_head], order[v]));
            v = lca[v_head][0];
        }
    }

    if (depth[v] > depth[u]) swap(u, v);
    // depth[v] < depth[u];

    result = max(result, seg.query(order[v] + 1, order[u]));

    return result;
}

int query(int u, int v) {
    int t = get_lca(u, v);
    return max(sub_query(u, t), sub_query(v, t));
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;

    seg.init(N);

    for (int n = 1; n <= N - 1; n++) {
        int u, v, w;
        cin >> u >> v >> w;

        edges[n] = { u, v };

        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w });
    }

    dfs(1, 0);
    hld(1, 0);

    for (int n = 2; n <= N; n++) {
        seg.update(order[n], cost[n]);
    }

    int M;
    cin >> M;

    for (int m = 0; m < M; m++) {
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            int i, c;
            cin >> i >> c;

            update(i, c);
        } else if (cmd == 2) {
            int u, v;
            cin >> u >> v;

            cout << query(u, v) << '\n';
        }
    }

    return 0;
}
