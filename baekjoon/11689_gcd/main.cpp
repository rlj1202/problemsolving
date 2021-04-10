#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    long long N; // 1e12
    scanf("%lld", &N);

    long long result = 1;

    long long cur = N;
    for (long long i = 2; i <= ceil(sqrt(N)); i++) {
        long long pow = 1;
        while (cur && cur % i == 0) {
            cur /= i;
            pow *= i;
        }

        result *= pow - pow / i;
    }
    if (cur != 1) {
        result *= cur - 1;
    }

    printf("%lld\n", result);

    return 0;
}