#include <cstdio>
#include <algorithm>

using namespace std;

int arr[1000006];

int A[1000006];

int main() {
    int N;
    scanf("%d", &N);
    for (int n = 0; n < N; n++) {
        scanf("%d", arr + n);
    }

    int r = 0, p = 0;
    for (int i = 0; i < N; i++) {
        if (i <= r) {
            A[i] = min(A[2*p - i], r - i);
        } else {
            A[i] = 0;
        }

        while (i - A[i] - 1 && i + A[i] + 1 < N &&
               arr[i - A[i] - 1] == arr[i + A[i] + 1])
            A[i]++;

        if (r < i + A[i]) {
            r = i + A[i];
            p = i;
        }
    }

    printf("\t");
    for (int i = 0; i < N; i++) printf("%d ", A[i]);
    printf("\n");

    int M;
    scanf("%d", &M);

    while (M--) {
        int s, e;
        scanf("%d %d", &s, &e);
        s--;

        int len = e - s;
        int mid = (s + e) / 2;

        if (len % 2 == 0) {
            printf("test\n");
        } else {
            printf("%d\n", A[mid] > 0 || len == 1);
        }
    }

    return 0;
}