#include <cstdio>
#include <algorithm>

using namespace std;

int primes[100005];
int plen;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    primes[plen++] = 2;
    for (int i = 3; i * i <= 1e9; i += 2) {
        int pi = 0;
        while (pi < plen && i % primes[pi] != 0) pi++;
        if (pi == plen) primes[plen++] = i;
    }

    int T;
    scanf("%d", &T);

    while (T--) {
        int A, B, K;
        scanf("%d %d %d", &A, &B, &K);

        int C = gcd(A, B);

        int a = A;
        int b = B;
        int c = C;

        int a_primes = 0;
        int b_primes = 0;
        int c_primes = 0;

        for (int i = 0; i < plen; i++) {
            while (a % primes[i] == 0) {
                a /= primes[i];
                a_primes++;
            }
        }
        if (a > 1) a_primes++;

        for (int i = 0; i < plen; i++) {
            while (b % primes[i] == 0) {
                b /= primes[i];
                b_primes++;
            }
        }
        if (b > 1) b_primes++;

        for (int i = 0; i < plen; i++) {
            while (c % primes[i] == 0) {
                c /= primes[i];
                c_primes++;
            }
        }
        if (c > 1) c_primes++;

        bool result = false;

        for (int i = 0; i <= c_primes; i++) {
            int a_delta = a_primes - i;
            int b_delta = b_primes - i;

            int min_k = (a_delta > 0) + (b_delta > 0);
            int max_k = a_delta + b_delta;

            if (min_k <= K && K <= max_k) {
                result = true;
                break;
            }
        }

        printf("%s\n", result ? "YES" : "NO");
    }

    return 0;
}
