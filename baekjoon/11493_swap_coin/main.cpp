#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int vertex_colors[502];
int coin_colors[502];

queue<int> q;

void bfs(int N, vector<int> *adj, int *visited, int start) {
    visited[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : adj[cur]) {
            if (visited[next] != -1) continue;

            visited[next] = visited[cur] + 1;
            q.push(next);
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        // 500, N(N - 1) / 2
        int N, M; // number of vertices, number of edges
        scanf("%d %d", &N, &M);
        
        vector<int> adj[502];
        int visited[502][502];

        memset(visited, -1, sizeof(visited));

        for (int m = 0; m < M; m++) { // edges
            int x, y;
            scanf("%d %d", &x, &y);
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        for (int n = 1; n <= N; n++) { // color of vertices
            scanf("%d", vertex_colors + n);
        }
        for (int n = 1; n <= N; n++) { // color of coins
            scanf("%d", coin_colors + n);
        }

        // O(N^2)
        for (int n = 1; n <= N; n++) {
            if (coin_colors[n] == 1 && vertex_colors[n] == 0) {
                bfs(N, adj, visited[n], n);
            }
        }

        printf("\n");
        for (int n = 1; n <= N; n++) {
            printf("\t%d: ", n);
            for (int i = 1; i <= N; i++) printf("%2d ", visited[n][i]);
            printf("\n");
        }

        // O(N^N)...?

        printf("%d\n", 0);
    }

    return 0;
}