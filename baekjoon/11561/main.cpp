#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        long long N;
        scanf("%lld", &N);

        long long l = 0;
        long long r = sqrt(1e17);

        while (r - l) {
            long long mid = (l + r + 1) / 2;

            long long dist = mid * (mid + 1) / 2;

            if (dist <= N) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }

        printf("%lld\n", l);
    }

    return 0;
}
