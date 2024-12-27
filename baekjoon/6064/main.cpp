#include <algorithm>
#include <cstdio>

using namespace std;

// x - 1 = (year - 1) % M
// y - 1 = (year - 1) % N

// year - 1 = (x - 1) + M * ?
// year - 1 = (y - 1) + N * ?

// year - 1 = (x - 1) + (y - 1) + M * ? + N * ?

// year == x (mod M)
// year == y (mod N)

// year - x == 0 (mod M)
// year - y == 0 (mod N)

// year = x + M * ?
// year = y + N * ?
// x + M*? = y + N*?
// x - y = N*? - M*?

// LCM?

// year == x (mod MN)
// year == y (mod MN)
// year = x + MN*?
// year = y + MN*?
// 0 = x - y + MN * ?
// x - y = MN * ?

typedef long long ll;

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        ll M, N, x, y;
        scanf("%lld %lld %lld %lld", &M, &N, &x, &y);

        ll limit = lcm(M, N);

        ll year = x;

        while ((year - 1) % N != y - 1) {
            year += M;

            if (year > limit) {
                year = -1;
                break;
            }
        }

        printf("%lld\n", year);
    }

    return 0;
}