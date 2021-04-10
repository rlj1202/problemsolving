#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int INF = 0x3f3f3f3f;

const int dr[] = {1, 0, -1, 0};
const int dc[] = {0, 1, 0, -1};

struct edge {
    int cap;
    int flow;
    int node;
    int inv;
};

int N, M;

char grid[102][102];

vector<edge> adj[20004];

queue<int> q;
bool visited[20004];
edge *previous[20004];

inline int index(int r, int c, int l) {
    return c + (r - 1) * M + l * N*M;
}

void make_edge(int a, int b, int cap) {
    adj[a].push_back({cap, 0, b, (int) adj[b].size()});
    adj[b].push_back({0, 0, a, (int) adj[a].size() - 1});
}

int main() {
    scanf("%d %d", &N, &M);

    for (int n = 1; n <= N; n++) {
        scanf("%s", grid[n] + 1);
    }

    int start;
    int end;

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= M; c++) {
            if (grid[r][c] == '#') continue;

            if (grid[r][c] == 'K') {
                start = index(r, c, 1);

                for (int i = 0; i < 4; i++) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if (nr < 1 || nr > N) continue;
                    if (nc < 1 || nc > M) continue;

                    if (grid[nr][nc] == 'H') {
                        printf("-1\n");
                        return 0;
                    }
                }
            } else if (grid[r][c] == 'H') {
                end = index(r, c, 0);
            }

            make_edge(index(r, c, 0), index(r, c, 1), 1);

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr < 1 || nr > N) continue;
                if (nc < 1 || nc > M) continue;
                if (grid[nr][nc] == '#') continue;

                make_edge(index(r, c, 1), index(nr, nc, 0), INF);
            }
        }
    }

    int result = 0;

    while (true) {
        memset(visited, 0, sizeof(visited));
        memset(previous, 0, sizeof(previous));

        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (edge &e : adj[cur]) {
                if (visited[e.node]) continue;
                if (e.cap - e.flow <= 0) continue;

                previous[e.node] = &adj[e.node][e.inv];

                visited[e.node] = true;
                q.push(e.node);
            }
        }

        if (previous[end] == 0) break;

        int min_flow = INF;
        for (edge *cur = previous[end]; cur; cur = previous[cur->node]) {
            edge &inv = adj[cur->node][cur->inv];
            min_flow = min(min_flow, inv.cap - inv.flow);
        }

        for (edge *cur = previous[end]; cur; cur = previous[cur->node]) {
            cur->flow -= min_flow;
            adj[cur->node][cur->inv].flow += min_flow;
        }

        result += min_flow;
    }

    printf("%d\n", result);

    return 0;
}