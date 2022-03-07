#include <cstdio>

using namespace std;

int primes[2003];
int plen;

int dp[2003][20][402];
bool visited[2003][20][402];

int calc(int n, int k, int pi) {
    if (n < 1) return 0;

    if (!visited[n][k][pi] && k >= 2) {
        for (int i = pi - 1; i >= 0; i--) {
            dp[n][k][pi] += calc(n - primes[pi], k - 1, i);
        }
    }

    visited[n][k][pi] = true;

    return dp[n][k][pi];
}

int main() {
    primes[plen++] = 2;
    for (int i = 3; i < 2003; i += 2) {
        int pi;
        for (pi = 0; pi < plen; pi++) {
            if (i % primes[pi] == 0) break;
        }

        if (pi == plen) primes[plen++] = i;
    }

    for (int i = 0; i < plen; i++) {
        dp[primes[i]][1][i] = 1;
        visited[primes[i]][1][i] = true;
    }

    int T;
    scanf("%d", &T);

    while (T--) {
        int N, K;
        scanf("%d %d", &N, &K);

        int result = 0;

        for (int i = 0; i < plen; i++) {
            result += calc(N, K, i);
        }

        printf("%d\n", result);
    }

    return 0;
}
