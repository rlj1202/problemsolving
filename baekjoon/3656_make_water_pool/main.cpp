#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const long long INF = 0x7f7f7f7f7f7f7f7f;

const int dr[] = {1, 0, -1, 0};
const int dc[] = {0, 1, 0, -1};

struct edge {
    long long cap;
    long long flow;
    int node;
    int inv;
};

int W, H, D, F, B;

char grid[52][52];

queue<int> q;
bool visited[5003];
edge *previous[5003];

inline int index(int r, int c) {
    return c + (r - 1) * W;
}

void make_edge(vector<edge> *adj, int a, int b, long long cap, long long cap2 = 0) {
    adj[a].push_back({cap, 0, b, (int) adj[b].size()});
    adj[b].push_back({cap2, 0, a, (int) adj[a].size() - 1});
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        vector<edge> adj[5003];

        scanf("%d %d %d %d %d", &W, &H, &D, &F, &B);
        for (int r = 1; r <= H; r++) {
            scanf("%s", grid[r] + 1);
        }

        long long result = 0;

        for (int r = 1; r <= H; r++) {
            for (int c = 1; c <= W; c++) {
                if (r == 1 || r == H || c == 1 || c == W) {
                    if (grid[r][c] == '.') {
                        grid[r][c] = '#';
                        result += F;
                    }
                }
            }
        }

        int src = 0;
        int sink = index(H, W) + 1;

        for (int r = 1; r <= H; r++) {
            for (int c = 1; c <= W; c++) {
                char type = grid[r][c];

                if (type == '#') {
                    make_edge(adj, src, index(r, c), 
                        r == 1 || r == H || c == 1 || c == W
                            ? INF : D
                    );
                } else if (type == '.') {
                    make_edge(adj, index(r, c), sink, F);
                }

                if (r + 1 <= H) {
                    make_edge(adj, index(r, c), index(r + 1, c), B, B);
                }
                if (c + 1 <= W) {
                    make_edge(adj, index(r, c), index(r, c + 1), B, B);
                }
            }
        }

        while (true) {
            memset(visited, 0, sizeof(visited));
            memset(previous, 0, sizeof(previous));

            visited[src] = true;
            q.push(src);

            while (!q.empty()) {
                int cur = q.front();
                q.pop();

                for (edge e : adj[cur]) {
                    if (e.cap - e.flow <= 0) continue;
                    if (visited[e.node]) continue;

                    visited[e.node] = true;
                    previous[e.node] = &adj[e.node][e.inv];
                    q.push(e.node);
                }
            }

            if (previous[sink] == 0) break;

            long long min_flow = INF;
            for (edge *cur = previous[sink]; cur; cur = previous[cur->node]) {
                edge *inv = &adj[cur->node][cur->inv];
                min_flow = min(min_flow, inv->cap - inv->flow);
            }

            for (edge *cur = previous[sink]; cur; cur = previous[cur->node]) {
                edge *inv = &adj[cur->node][cur->inv];

                inv->flow += min_flow;
                cur->flow -= min_flow;
            }

            result += min_flow;
        }

        printf("%lld\n", result);
    }

    return 0;
}