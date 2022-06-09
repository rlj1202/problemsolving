#include <cstdio>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);

        int i = 0;
        int cur = N;
        long long power = 1;

        long long A = 0;
        long long B = 0;

        while (cur) {
            if (i % 2 == 0) {
                A += (cur % 10) * power;
            } else {
                B += (cur % 10) * power;

                power *= 10;
            }

            cur /= 10;
            i++;
        }

        printf("%lld\n", (A + 1) * (B + 1) - 2LL);
    }

    return 0;
}
