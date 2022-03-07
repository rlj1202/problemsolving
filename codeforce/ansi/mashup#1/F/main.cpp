#include <cstdio>

using namespace std;

int arr[200005];
int bags[200005];

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, K; // 2e5, N
        scanf("%d %d", &N, &K);

        for (int n = 0; n < N; n++) {
            scanf("%d", arr + n); // -1e9 ~ 1e9
        }
        for (int k = 0; k < K; k++) {
            scanf("%d", bags + k);
        }

        printf("%d\n", 0);
    }

    return 0;
}
