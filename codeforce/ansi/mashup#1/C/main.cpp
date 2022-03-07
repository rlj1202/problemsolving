#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, R; // 1e9
        scanf("%d %d", &N, &R);

        long long result = 0;

        int maxWidth = min(N, R);
        result = (long long) maxWidth * (maxWidth + 1) / 2;

        if (N <= R) {
            result += 1 - N;
        }

        printf("%lld\n", result);
    }

    return 0;
}
