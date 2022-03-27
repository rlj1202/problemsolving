#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    unsigned long long N;
    scanf("%llu", &N);

    unsigned long long l = 0ULL;
    unsigned long long r = N;
    unsigned long long mid = N >> 1ULL;

    while (l < r) {
        if (mid >= N / mid + (N % mid > 0ULL)) {
            r = mid;
        } else {
            l = mid + 1ULL;
        }

        mid = (l >> 1ULL) + (r >> 1ULL) + (((l % 2ULL) + (r % 2ULL)) >> 1ULL);
    }

    printf("%llu\n", mid);

    return 0;
}
