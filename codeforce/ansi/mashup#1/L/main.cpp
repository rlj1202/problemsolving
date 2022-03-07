#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    
    while (T--) {
        long long A, K; // 1e18, 1e16
        scanf("%lld %lld", &A, &K);

        long long result = A;
        for (int k = 2; k <= K; k++) {
            int m = 9999;
            int M = 0;

            long long cur = result;
            while (cur) {
                int digit = cur % 10;
                m = min(m, digit);
                M = max(M, digit);

                cur /= 10;
            }

            if (m == 0) break;

            result += m * M;
        }

        printf("%lld\n", result);
    }

    return 0;
}
