#include <cstdio>

using namespace std;

int main() {
    int K, N;
    scanf("%d %d", &K, &N);

    for (int k = 0; k < K; k++) {
        for (int n = 0; n < N; n++) {
            printf("%d ", 0);
        }
        printf("\n");
    }

    return 0;
}
