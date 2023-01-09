#include <cstdio>
#include <algorithm>

using namespace std;

long long arr[100005];

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N; // 1e5
        scanf("%d", &N);

        for (int n = 0; n < N; n++) {
            scanf("%lld", arr + n); // +-1e9
            if (n) arr[n] += arr[n - 1];
        }

        long long minsum = 0;
        int index = -1;
        long long maxsum = 0;
        for (int n = 0; n < N; n++) {
            if (maxsum < arr[n] - minsum && !(n == N - 1 && index == -1)) {
                maxsum = arr[n] - minsum;
            }

            if (minsum >= arr[n]) {
                minsum = arr[n];
                index = n;
            }
        }
        for (int n = 0; n < N; n++) {
            maxsum = max(maxsum, arr[N - 1] - arr[n]);
        }

        printf("%s\n", maxsum < arr[N - 1] ? "YES" : "NO");
    }

    return 0;
}
