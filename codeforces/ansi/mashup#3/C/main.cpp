#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int arr[200005];

int deltas[200005 * 2];

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, K; // 2e5, 2e5
        scanf("%d %d", &N, &K);
        for (int n = 0; n < N; n++) {
            scanf("%d", arr + n);
        }

        memset(deltas, 0, sizeof(deltas));

        for (int n = 0; n < N / 2; n++) {
            int a = arr[n];
            int b = arr[N - n - 1];

            int minVal = min(a, b);
            int maxVal = max(a, b);

            int sum = a + b;
            int lower = minVal + 1;
            int upper = maxVal + K;

            // [2, lower) : 2
            // [lower, sum) : 1
            // [sum, sum] : 0
            // (sum, upper] : 1
            // (upper, K] : 2

            deltas[2] += 2;
            deltas[lower] += -2;

            deltas[lower] += 1;
            deltas[sum] += -1;

            deltas[sum] += 0;
            deltas[sum + 1] += 0;

            deltas[sum + 1] += 1;
            deltas[upper + 1] += -1;

            deltas[upper + 1] += 2;
        }

        int result = 0x3f3f3f3f;

        int sum = 0;
        for (int k = 2; k <= K * 2; k++) {
            sum += deltas[k];
            result = min(result, sum);
        }

        printf("%d\n", result);
    }

    return 0;
}
