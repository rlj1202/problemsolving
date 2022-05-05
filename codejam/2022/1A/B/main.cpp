#include <cstdio>
#include <algorithm>

using namespace std;

long long arr[102];

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        int N;
        scanf("%d", &N);
        if (N == -1) break;

        long long sum = 0;

        // Output
        int mid = min(N, 60);
        for (int n = 0; n < mid; n++) {
            long long value = 1 << n;
            printf("%lld ", value);

            sum += value;
        }
        for (int n = mid; n < N; n++) {
            long long value = (n - mid) * 2 + 1;
            printf("%lld ", value);

            sum += value;
        }
        printf("\n");

        // Input
        for (int n = 0; n < N; n++) {
            scanf("%lld", arr + n);

            sum += arr[n];
        }

        // Answer
        long long cur = 1;
        sum /= 2;
        while (sum) {
            if (sum % 2 == 1) {
                printf("%lld ", cur);
            }

            sum /= 2;
            cur <<= 1;
        }

        printf("\n");
    }

    return 0;
}
