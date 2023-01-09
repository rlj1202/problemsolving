#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

int A[3];
int B[3];

int flow[12][12];
int cap[12][12];
bool adj[12][12];

bool visited[12];
int parent[12];
queue<int> q;

int bfs() {
    memset(visited, 0, sizeof(visited));
    memset(parent, -1, sizeof(parent));

    visited[0] = true;
    q.push(0);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next = 0; next <= 7; next++) {
            if (!adj[cur][next]) continue;
            if (cap[cur][next] - flow[cur][next] <= 0) continue;
            if (visited[next]) continue;

            visited[next] = true;
            parent[next] = cur;
            q.push(next);
        }
    }

    if (visited[7]) {
        int minPath = 0x3f3f3f3f;

        for (int cur = 7; cur != 0; cur = parent[cur]) {
            int next = parent[cur];
            minPath = min(minPath, cap[next][cur] - flow[next][cur]);
        }

        for (int cur = 7; cur != 0; cur = parent[cur]) {
            int next = parent[cur];
            flow[next][cur] += minPath;
            flow[cur][next] -= minPath;
        }

        return minPath;
    } else {
        return 0;
    }
}

int main() {
    int N; // 1e9
    scanf("%d", &N);
    for (int i = 0; i < 3; i++) scanf("%d", A + i);
    for (int i = 0; i < 3; i++) scanf("%d", B + i);

    // maximum rounds Alice can win
    for (int i = 0; i < 3; i++)
        adj[i + 1][(i + 1) % 3 + 4] = true;
    for (int i = 0; i < 3; i++) adj[0][i + 1] = true;
    for (int i = 0; i < 3; i++) adj[i + 4][7] = true;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 2; j++)
            cap[i + 1][(i + j) % 3 + 4] = N;
    for (int i = 0; i < 3; i++) cap[0][i + 1] = A[i];
    for (int i = 0; i < 3; i++) cap[i + 4][7] = B[i];

    for (int i = 0; i <= 7; i++)
        for (int j = 0; j <= 7; j++)
            if (adj[i][j]) adj[j][i] = true;

    int maxRounds = 0;

    while (true) {
        int minPath = bfs();
        if (minPath == 0) break;

        maxRounds += minPath;
    }

    // minimum rounds Alice can win
    memset(flow, 0, sizeof(flow));

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 2; j++)
            adj[i + 1][(i + j) % 3 + 4] = true;

    for (int i = 0; i < 3; i++) cap[0][i + 1] = B[i];
    for (int i = 0; i < 3; i++) cap[i + 4][7] = A[i];

    for (int i = 0; i <= 7; i++)
        for (int j = 0; j <= 7; j++)
            if (adj[i][j]) adj[j][i] = true;

    int minRounds = 0;

    while (true) {
        int minPath = bfs();
        if (minPath == 0) break;

        minRounds += minPath;
    }

    printf("%d %d\n", N - minRounds, maxRounds);

    return 0;
}
