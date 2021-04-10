#include <cstdio>

using namespace std;

// 200, 40000
int N, M;

int visited[202];
int visited_flag;

bool adj[202][202];
int arr[202];

bool dfs(int node) {
    if (visited[node] == visited_flag) return false;
    visited[node] = visited_flag;

    for (int next = 1; next <= N; next++) {
        if (!adj[node][next]) continue;

        if (!arr[next]) {
            arr[next] = node;
            return true;
        } else {
            if (dfs(arr[next])) {
                arr[next] = node;
                return true;
            }
        }
    }

    return false;
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            adj[i][j] = true;
        }
    }
    // O(M * N^2)
    for (int m = 0; m < M; m++) {
        int cmd, x, y, v;
        scanf("%d %d %d %d", &cmd, &x, &y, &v);

        if (cmd == 1) { // max(arr[x:y]) == v
            for (int i = x; i <= y; i++) {
                for (int j = v + 1; j <= N; j++) {
                    adj[i][j] = false;
                }
            }
        } else if (cmd == 2) { // min(arr[x:y]) == v
            for (int i = x; i <= y; i++) {
                for (int j = 1; j < v; j++) {
                    adj[i][j] = false;
                }
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        visited_flag++;
        if (!dfs(i)) {
            printf("-1\n");
            return 0;
        }
    }

    for (int n = 1; n <= N; n++) {
        printf("%d ", arr[n]);
    }
    printf("\n");

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}