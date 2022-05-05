#include <cstdio>

using namespace std;

const long long MOD = 998244353;

long long factorial[502];

int main() {
    int T;
    scanf("%d", &T);

    factorial[0] = 1;
    for (int i = 1; i <= 500; i++) {
        factorial[i] = i * factorial[i - 1];
        factorial[i] %= MOD;
    }

    while (T--) {
        int N; // 1000
        scanf("%d", &N);

        if (N % 2 == 1) {
            printf("0\n");
        } else {
            long long answer = factorial[N / 2] * factorial[N / 2];
            answer %= MOD;
            printf("%lld\n", answer); // the number of beautiful permutations
        }
    }

    return 0;
}
