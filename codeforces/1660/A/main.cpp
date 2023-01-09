#include <cstdio>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        long long A, B; // 1e8
        scanf("%lld %lld", &A, &B);

        if (A == 0) {
            printf("1\n");
        } else {
            printf("%lld\n", B*2 + A + 1);
        }
    }

    return 0;
}
