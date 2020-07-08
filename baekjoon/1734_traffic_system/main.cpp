#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct edge {
    int dest;
    bool cut_edge;

    int inv;

    bool operator< (const edge &o) const {
        return dest < o.dest;
    }
};

const char ANSWERS[2][4] = {"no", "yes"};

vector<edge> adj[100005];

int visited[100005];
int lowers[100005];
int poped[100005];
int size[100005];
int cur_visited;
int cur_poped;

bool cut_vertex[100005];

int dfs(int parent, int node) {
    visited[node] = ++cur_visited;
    lowers[node] = visited[node];

    for (edge &e : adj[node]) {
        if (!visited[e.dest]) {
            int lower_child = dfs(node, e.dest);
            size[node] += size[e.dest];
            lowers[node] = min(lowers[node], lower_child);

            // cut-vertex condition
            // cur-edge condition
            if (visited[node] < lower_child) {
                if (parent) {
                    cut_vertex[node] = true;
                }

                e.cut_edge = true;
                adj[e.dest][e.inv].cut_edge = true;
            }
        } else if (e.dest != parent) {
            lowers[node] = min(lowers[node], visited[e.dest]);
        }
    }

    // cut-vertex condition
    if (!parent && adj[node].size() >= 2) {
        cut_vertex[node] = true;
    }

    poped[node] = ++cur_poped;
    size[node]++;

    return lowers[node];
}

bool is_in_tree(int root, int node) {
    return poped[root] - size[root] < poped[node] &&
           poped[node] <= poped[root];
}

bool in_same_group(int a, int b, int g1, int g2) {
    int g = poped[g1] < poped[g2] ? g1 : g2;
    return is_in_tree(g, a) == is_in_tree(g, b);
}

bool in_same_group(int a, int b, int c) {
    // TODO

    return false;
}

int main() {
    int N, E;
    scanf("%d %d", &N, &E);
    for (int e = 0; e < E; e++) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back({b, false, (int) adj[b].size()});
        adj[b].push_back({a, false, (int) adj[a].size() - 1});
    }
    for (int n = 1; n <= N; n++) {
        sort(adj[n].begin(), adj[n].end());
    }

    for (int n = 1; n <= N; n++) {
        if (!visited[n]) dfs(0, n);
    }

    int Q;
    scanf("%d", &Q);
    while (Q--) {
        int type;
        scanf("%d", &type);

        if (type == 1) {
            int a, b, g1, g2;
            scanf("%d %d %d %d", &a, &b, &g1, &g2);

            edge &e = *lower_bound(adj[g1].begin(), adj[g1].end(), edge{g2});
            if (e.cut_edge) {
                printf("%s\n", ANSWERS[in_same_group(a, b, g1, g2)]);
            } else {
                printf("%s\n", ANSWERS[true]);
            }
        } else if (type == 2) {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);

            if (cut_vertex[c]) {
                printf("%s\n", ANSWERS[in_same_group(a, b, c)]);
            } else {
                printf("%s\n", ANSWERS[true]);
            }
        }
    }

    return 0;
}