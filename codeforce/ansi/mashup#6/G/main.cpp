#include <cstdio>
#include <algorithm>

using namespace std;

int arr[100005];

void solve(int n, int k) {
    if (n % 2 == 0) {
        if (k % 2 == 0) {
            arr[0] = arr[1] = (n - (k - 2)) / 2;
            for (int i = 2; i < k; i++) {
                arr[i] = 1;
            }
        } else {
            if (k*2 >= n) {
                for (int i = 0; i < k; i++) {
                    arr[i] = 1;
                }
                for (int i = 0; i < n - k; i++) {
                    arr[i] = 2;
                }
            } else {
                solve(n / 2, k);
                for (int i = 0; i < k; i++) {
                    arr[i] *= 2;
                }
            }
        }
    } else {
        if (k % 2 == 0) {
            arr[k - 1] = 1;
            solve(n - 1, k - 1);
        } else {
            arr[0] = arr[1] = (n - (k - 2)) / 2;
            for (int i = 2; i < k; i++) {
                arr[i] = 1;
            }
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, K;
        scanf("%d %d", &N, &K);

        solve(N, K);

        for (int k = 0; k < K; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }

    return 0;
}
