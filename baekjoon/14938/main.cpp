#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int items[102];

int adj[102][102];

int main() {
    int N, M, R;
    scanf("%d %d %d", &N, &M, &R);

    for (int n = 1; n <= N; n++) {
        scanf("%d", items + n);
    }

    memset(adj, 0x3f, sizeof(adj));

    for (int r = 0; r < R; r++) {
        int a, b, l;
        scanf("%d %d %d", &a, &b, &l);

        adj[a][b] = l;
        adj[b][a] = l;
    }
    for (int n = 1; n <= N; n++) {
        adj[n][n] = 0;
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }

    int answer = 0;

    for (int n = 1; n <= N; n++) {
        int score = 0;
        for (int m = 1; m <= N; m++) {
            if (adj[n][m] <= M) {
                score += items[m];
            }
        }
        answer = max(answer, score);
    }

    printf("%d\n", answer);

    return 0;
}
