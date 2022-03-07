#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    long long X; // 1e12
    scanf("%lld", &X);

    long long minVal = X;
    long long a = 1;
    long long b = X;

    for (long long i = 1; i <= (long long) sqrt(X); i++) {
        if (X % i != 0LL) continue;
        if (gcd(i, X / i) != 1) continue;

        if (minVal > max(i, X / i)) {
            minVal = max(i, X / i);
            a = i;
            b = X / i;
        }
    }

    printf("%lld %lld\n", a, b);

    return 0;
}
