#include <cstdio>

using namespace std;

long long arr[100005];

int main() {
    long long N;
    scanf("%lld", &N);
    for (int n = 1; n <= N; n++) {
        scanf("%lld", arr + n);
    }

    if (N == 1) {
        printf("1 1\n");
        printf("0\n");
        printf("1 1\n");
        printf("0\n");
        printf("1 1\n");
        printf("%d\n", -arr[1]);
        return 0;
    }

    printf("%d %d\n", 1, N - 1);
    printf("%lld ", arr[1] * (N - 1));
    for (int n = 2; n <= N - 1; n++) {
        printf("%d ", 0);
    }
    printf("\n");

    printf("%d %d\n", 2, N);
    for (int n = 2; n <= N; n++) {
        printf("%lld ", arr[n] * (N - 1));
    }
    printf("\n");

    printf("%d %d\n", 1, N);
    for (int n = 1; n <= N; n++) {
        printf("%lld ", -arr[n] * N);
    }
    printf("\n");

    return 0;
}
