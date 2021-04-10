#include <cstdio>

using namespace std;

int sums[1003][1003];

int main() {
    // 1e3
    int N;
    scanf("%d", &N);

    for (int n = 0; n < N; n++) {
        for (int m = 0; m < N; m++) {
            // 1e5
            scanf("%d", &sums[n][m]);
        }
    }

    if (N == 2) {
        printf("%d %d\n", 1, 1);
        return 0;
    }

    for (int n = 0; n < N; n++) {
        int a = (n + 1) % N;
        int b = (n + 2) % N;

        int result = (sums[n][a] + sums[n][b] - sums[a][b]) / 2;
        printf("%d ", result);
    }
    printf("\n");

    return 0;
}