#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int index_of[1000006];
int arr[3003];

long long dp[3003][3003];

int main() {
    int N;
    scanf("%d", &N);
    for (int n = 1; n <= N; n++) {
        scanf("%d", arr + n);
        index_of[arr[n]] = n;
    }

    memset(dp, -1, sizeof(dp));

    long long result = 0;

    for (int i = N - 1; i >= 1; i--) {
        for (int j = i + 1; j <= N; j++) {
            dp[i][j] = (long long) arr[i] + (long long) arr[j];

            long long delta = arr[j] - arr[i];

            if (arr[j] + delta >= 1000006) continue;

            long long next = dp[j][index_of[arr[j] + delta]];
            if (next != -1) {
                dp[i][j] += next - arr[j];

                result = max(result, dp[i][j]);
            }
        }
    }

    // for (int i = 1; i <= N; i++) {
    //     for (int j = 1; j <= N; j++) {
    //         printf("%2d ", dp[i][j]);
    //     }
    //     printf("\n");
    // }

    printf("%lld\n", result);

    return 0;
}
