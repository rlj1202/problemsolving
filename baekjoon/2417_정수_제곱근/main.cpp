#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    unsigned long long N;
    scanf("%llu", &N);

    unsigned long long l = 0;
    unsigned long long r = N;
    unsigned long long mid = N / 2;

    while (l < r) {
        if (mid < sqrt(N)) {
            l = mid + 1;
        } else {
            r = mid;
        }

        mid = (l + r) / 2;
    }

    printf("%llu\n", mid);

    return 0;
}
