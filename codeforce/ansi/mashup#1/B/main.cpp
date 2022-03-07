#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        long long A, B, N, M; // 1e18
        scanf("%lld %lld %lld %lld", &A, &B, &N, &M);

        bool result = (M <= min(A, B)) && (N + M <= A + B);
        printf("%s\n", result ? "Yes" : "No");
    }

    return 0;
}
