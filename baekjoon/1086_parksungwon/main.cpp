#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

int pw[52];

char arr[16][52];
int remains[16];
int lens[16];

long long dp[1 << 15][102];

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// 15! = 1.3e12
int main() {
    // 15
    int N;
    scanf("%d", &N);
    for (int n = 0; n < N; n++) {
        // 10^50
        scanf("%s", arr[n]);
    }
    // 100
    int K;
    scanf("%d", &K);

    pw[0] = 1;
    for (int i = 1; i <= 50; i++) {
        pw[i] = pw[i - 1] * 10;
        pw[i] %= K;
    }

    for (int n = 0; n < N; n++) {
        for (int i = 0; arr[n][i]; i++) {
            remains[n] *= 10;
            remains[n] %= K;
            remains[n] += arr[n][i] - '0';
            remains[n] %= K;
            lens[n]++;
        }

        dp[1 << n][remains[n]] = 1;
    }

    for (int mask = 0; mask < (1 << N); mask++) {
        for (int remain = 0; remain < K; remain++) {
            for (int select = 0; select < N; select++) {
                if (mask & (1 << select)) continue;

                int next = remain * pw[lens[select]];
                next %= K;
                next += remains[select];
                next %= K;

                dp[mask | (1 << select)][next] += dp[mask][remain];
            }
        }
    }

    long long a = dp[(1 << N) - 1][0];
    long long b = 1;

    for (long long i = 1; i <= N; i++) b *= i;

    long long comm = gcd(a, b);
    a /= comm;
    b /= comm;
    printf("%lld/%lld\n", a, b);

    return 0;
}