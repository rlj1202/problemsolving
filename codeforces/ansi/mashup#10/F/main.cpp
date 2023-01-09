#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int B[1003];
int C[1003];

int min_k[1003];

long long buffer[2][1000006];

int main() {
    memset(min_k, 0x3f, sizeof(min_k));

    min_k[1] = 0;
    min_k[2] = 1;
    for (int n = 2; n < 1003; n++) {
        for (int m = 1; m <= n; m++) {
            min_k[n + n/m] = min(min_k[n + n/m], min_k[n] + 1);
        }
    }

    int T;
    scanf("%d", &T);

    while (T--) {
        memset(buffer, 0, sizeof(buffer));

        int N, K;
        scanf("%d %d", &N, &K);
        for (int n = 1; n <= N; n++) {
            scanf("%d", B + n);
        }
        for (int n = 1; n <= N; n++) {
            scanf("%d", C + n);
        }

        long long *prev = buffer[0];
        long long *next = buffer[1];

        K = min(K, 1003 * 20);

        for (int n = 1; n <= N; n++) {
            for (int k = 0; k <= K; k++) {
                next[k] = prev[k];

                if (k - min_k[B[n]] >= 0)
                    next[k] = max(next[k], prev[k - min_k[B[n]]] + (long long) C[n]);
            }

            long long *tmp = prev;
            prev = next;
            next = tmp;
        }

        printf("%lld\n", prev[K]);
    }

    return 0;
}
