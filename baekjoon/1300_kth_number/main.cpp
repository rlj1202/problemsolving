#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    long long N, K;
    scanf("%lld %lld", &N, &K);

    long long l = 0;
    long long r = N*N; // K를 넣어도 맞다. 그 이유는 B[K]는 항상 K보다 작거나
                       // 같기 때문이다. (B[k] <= k)
    long long mid = (l + r) / 2;

    while (l < r) {
        long long count = 0;
        for (int i = 1; i <= min(N, mid); i++) {
            count += min(mid / i, N);
        }

        if (count < K) {
            l = mid + 1;
        } else {
            r = mid;
        }

        mid = (l + r) / 2;
    }

    printf("%lld\n", mid);

    return 0;
}