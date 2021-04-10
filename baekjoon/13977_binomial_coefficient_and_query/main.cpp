#include <cstdio>

using namespace std;

const int MOD = 1e9 + 7;

long long factorial[4000006];

int main() {
    factorial[0] = 1;
    for (long long i = 1; i <= 4000000; i++) {
        factorial[i] = i * factorial[i - 1];
        factorial[i] %= MOD;
    }

    // 1e5
    int M;
    scanf("%d", &M);
    for (int m = 0; m < M; m++) {
        // 4e6, N
        int n, k;
        scanf("%d %d", &n, &k);

        long long result = factorial[n];

        long long cur = factorial[n - k] * factorial[k];
        cur %= MOD;

        for (int p = MOD - 2; p; p >>= 1) {
            if (p % 2 == 1) {
                result = result * cur;
                result %= MOD;
            }

            cur = cur * cur;
            cur %= MOD;
        }

        printf("%lld\n", result);
    }

    return 0;
}