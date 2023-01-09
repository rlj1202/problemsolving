#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, G, B;
        scanf("%d %d %d", &N, &G, &B);

        long long result = 0;

        long long minHQ = ceil(N / 2.0);
        long long maxLQ = N - minHQ;

        if (minHQ % G == 0) {
            long long HQ = G * (minHQ / G - 1);
            long long LQ = B * (minHQ / G - 1);

            long long remains = max(minHQ - HQ, 0LL) + max(maxLQ - LQ, 0LL);

            result = HQ + LQ + remains;
        } else {
            long long HQ = G * (minHQ / G);
            long long LQ = B * (minHQ / G);

            long long remains = max(minHQ - HQ, 0LL) + max(maxLQ - LQ, 0LL);

            result = HQ + LQ + remains;
        }

        printf("%lld\n", result);
    }

    return 0;
}
