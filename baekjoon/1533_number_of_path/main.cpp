#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

const int MOD = 1e6 + 3;
const int MAT = 55;

long long adj[MAT][MAT];
long long temp[MAT][MAT];

void mul(int size, long long (*dest)[MAT], long long (*a)[MAT], long long (*b)[MAT]) {
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            temp[i][j] = 0;
            for (int k = 1; k <= size; k++) {
                temp[i][j] += a[i][k] * b[k][j];
            }
            temp[i][j] %= MOD;
        }
    }

    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            dest[i][j] = temp[i][j];
        }
    }
}

int main() {
    int N, S, E, T;
    scanf("%d %d %d %d", &N, &S, &E, &T); // T <= 1e9

    int vertices = N*5;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            char c;
            scanf(" %c", &c);
            int len = c - '0';
            if (!len) continue;

            adj[i][N*(len - 1) + j] = 1;
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int l = 2; l <= 5; l++) {
            adj[N*(l - 1) + i][N*(l - 2) + i] = 1;
        }
    }

    long long result[MAT][MAT];
    memset(result, 0, sizeof(result));
    for (int i = 1; i <= vertices; i++) {
        result[i][i] = 1;
    }

    long long pow[MAT][MAT];
    memcpy(pow, adj, sizeof(adj));

    while (T) {
        if ((T % 2) == 1) {
            mul(vertices, result, result, pow);
        }

        T >>= 1;
        mul(vertices, pow, pow, pow);
    }

    printf("%lld\n", result[S][E]);

    return 0;
}