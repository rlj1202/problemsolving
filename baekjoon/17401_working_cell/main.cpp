#include <cstdio>
#include <cstring>

using namespace std;

const int MOD = 1e9 + 7;

const int MAX_N = 22;

long long adj[102][MAX_N][MAX_N];
long long sum[102][MAX_N][MAX_N];

long long temp[MAX_N][MAX_N];

void mul(int n, long long (*dest)[MAX_N], long long (*a)[MAX_N], long long (*b)[MAX_N]) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            temp[i][j] = 0;

            for (int k = 1; k <= n; k++) {
                temp[i][j] += a[i][k] * b[k][j];
                temp[i][j] %= MOD;
            }
        }
    }

    memcpy(dest, temp, sizeof(temp));
}

int main() {
    // 100, 20, 1e9
    int T, N, D;
    scanf("%d %d %d", &T, &N, &D);

    for (int t = 0; t < T; t++) {
        int M;
        scanf("%d", &M);
        for (int m = 0; m < M; m++) {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);

            adj[t][a][b] = c;
        }
    }

    memcpy(sum[0], adj[0], sizeof(adj[0]));
    for (int t = 1; t < T; t++) {
        mul(N, sum[t], sum[t - 1], adj[t]);
    }

    long long result[MAX_N][MAX_N];
    memset(result, 0, sizeof(result));
    for (int i = 1; i <= N; i++) {
        result[i][i] = 1;
    }

    int q = D / T;
    int r = D % T;

    long long pw[MAX_N][MAX_N];
    memcpy(pw, sum[T - 1], sizeof(sum[T - 1]));
    while (q) {
        if (q % 2 == 1) {
            mul(N, result, result, pw);
        }

        q >>= 1;
        mul(N, pw, pw, pw);
    }

    if (r) mul(N, result, result, sum[r - 1]);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) printf("%d ", result[i][j]);
        printf("\n");
    }

    return 0;
}