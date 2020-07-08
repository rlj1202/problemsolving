#include <cstdio>

using namespace std;

int lessons[100005];

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    for (int n = 0; n < N; n++) {
        scanf("%d", lessons + n);
    }

    long long l = 0;
    long long r = 1e9;
    long long mid = (l + r) / 2;

    while (l < r) {
        int i = 0;
        int m = 0;
        for (; m < M; m++) {
            long long size = 0;
            while (size + lessons[i] <= mid && i < N) {
                size += lessons[i++];
            }
            if (size == 0) break;
        }

        if (m == M && i == N) {
            r = mid;
        } else {
            if (m < M && i == N) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        mid = (l + r) / 2;
    }

    printf("%lld\n", mid);

    return 0;
}