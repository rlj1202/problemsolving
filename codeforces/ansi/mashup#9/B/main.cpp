#include <cstdio>
#include <algorithm>

using namespace std;

long long fac[21];
long long fac_sum[1 << 21];
int fac_cnt[1 << 21];

int main() {
    fac[0] = 1;
    for (int i = 1; i < 21; i++) {
        fac[i] = fac[i - 1] * i;
    }

    for (int i = 0; i < (1 << 21); i++) {
        for (int j = 0; j < 21; j++) {
            if (i & (1 << j)) {
                fac_sum[i] += fac[j];
                fac_cnt[i]++;
            }
        }
    }

    int T;
    scanf("%d", &T);

    while (T--) {
        long long N;
        scanf("%lld", &N);

        int result = 0x3f3f3f3f;

        for (int i = 0; i < (1 << 21); i++) {
            long long cur = N - fac_sum[i];

            if (cur < 0) continue;

            int powerful = fac_cnt[i];

            while (cur) {
                powerful += cur % 2;
                cur /= 2;
            }

            result = min(result, powerful);
        }

        printf("%d\n", result);
    }

    return 0;
}
