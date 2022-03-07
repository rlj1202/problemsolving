#include <cstdio>

using namespace std;

int main() {
    long long K;
    scanf("%lld", &K);

    long long cur = 1;
    int cnt[11];
    int i = 0;
    for (int j = 0; j < 10; j++) cnt[j] = 1;
    while (cur < K) {
        cur += cur / cnt[i];

        cnt[i]++;
        i = (i + 1) % 10;
    }

    for (int j = 0; j < 10; j++) {
        for (int k = 0; k < cnt[10 - j - 1]; k++) {
            printf("%c", "codeforces"[j]);
        }
    }
    printf("\n");

    return 0;
}
