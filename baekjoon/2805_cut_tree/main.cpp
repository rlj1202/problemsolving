#include <cstdio>
#include <algorithm>

using namespace std;

long long heights[1000006];

int main() {
    int N, M;
    long long maxHeight = 0;
    scanf("%d %d", &N, &M);
    for (int n = 0; n < N; n++) {
        scanf("%lld", heights + n);
        maxHeight = max(maxHeight, heights[n]);
    }

    long long l = 0;
    long long r = maxHeight;
    long long mid = (l + r) / 2;

    while (l < r) {
        long long length = 0;
        for (int n = 0; n < N; n++) {
            length += max(0LL, heights[n] - mid);
        }

        if (length >= M) {
            l = mid;
        } else {
            r = mid - 1;
        }

        mid = (l + r + 1) / 2;
    }

    printf("%lld\n", mid);

    return 0;
}