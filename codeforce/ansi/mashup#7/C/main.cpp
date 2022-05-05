#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int arr[10004];
int uq[10004];

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, K;
        scanf("%d %d", &N, &K);
        for (int n = 0; n < N; n++) {
            scanf("%d", arr + n);
        }

        memcpy(uq, arr, sizeof(arr));
        sort(uq, uq + N);
        int uniques = unique(uq, uq + N) - uq;

        if (uniques > K) {
            printf("-1\n");
        } else {
            printf("%d\n", N * K);
            for (int n = 0; n < N; n++) {
                for (int i = 0; i < uniques; i++) {
                    printf("%d ", uq[i]);
                }
                for (int i = uniques; i < K; i++) {
                    printf("%d ", uq[uniques - 1]);
                }
            }
            printf("\n");
        }
    }

    return 0;
}
