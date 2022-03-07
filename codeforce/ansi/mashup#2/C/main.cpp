#include <cstdio>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    printf("%d\n", 4 + N*3);
    printf("0 0\n");
    printf("0 1\n");
    printf("1 0\n");
    printf("1 1\n");
    for (int n = 0; n < N; n++) {
        printf("%d %d\n", 1 + n, 2 + n);
        printf("%d %d\n", 2 + n, 2 + n);
        printf("%d %d\n", 2 + n, 1 + n);
    }

    return 0;
}
