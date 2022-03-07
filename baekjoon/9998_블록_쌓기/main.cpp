#include <cstdio>
#include <cmath>

using namespace std;

long long N;

long long Y[300005];
long long D[300005];

long long graph(long long i) {
    return abs(i - N / 2);
}

long long calc(long long offset) {
    long long result = 0;

    for (int i = 0; i < N; i++) {
        result += abs(Y[i] - (offset + graph(i)));
        result += abs(D[i] - (offset + graph(i)));
    }

    return result;
}

int main() {
    scanf("%lld", &N);
    for (int i = 0; i < N; i++) scanf("%lld", Y + i);
    for (int i = 0; i < N; i++) scanf("%lld", D + i);

    long long l = 0;
    long long r = 2 * powl(10, 12);
    long long midl = l + (r - l) / 3;
    long long midr = r - (r - l) / 3;

    while (l < r) {
        long long suml = calc(midl);
        long long sumr = calc(midr);

        if (suml < sumr) {
            r = midr - 1;
        } else if (suml >= sumr) {
            l = midl + 1;
        }

        midl = l + (r - l) / 3;
        midr = r - (r - l) / 3;
    }

    printf("%lld\n", calc(l));

    return 0;
}
