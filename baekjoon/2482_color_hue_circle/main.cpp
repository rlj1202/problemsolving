#include <cstdio>

const long long MOD = 1e9 + 3;

long long count[1003][1003];

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    count[0][0] = 1;
    count[1][0] = 1;
    count[1][1] = 1;

    for (int n = 2; n <= N; n++) {
        for (int k = 0; k <= K; k++) {
            count[n][k] = count[n - 1][k]; // not choose

            if (k) { // choose
                count[n][k] += count[n - 2][k - 1];
                count[n][k] %= MOD;
            }
        }
    }

    printf("%lld\n", (count[N - 1][K] + count[N - 3][K - 1]) % MOD);

    return 0;
}