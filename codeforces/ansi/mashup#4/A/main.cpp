#include <cstdio>
#include <algorithm>

using namespace std;

long long arr[100005];
long long sum[100005];

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, S;
        scanf("%d %d", &N, &S);
        for (int n = 1; n <= N; n++) {
            scanf("%lld", arr + n);
            sum[n] = sum[n - 1] + arr[n];
        }

        int result = 0;
        int maxgifts = 0;

        for (int n = 1; n <= N; n++) {
            int index = upper_bound(sum + 1, sum + N + 1, S + arr[n]) - sum;
            if (index <= n) continue;

            int gifts = index - 2;

            if (maxgifts < gifts) {
                // printf("\t[%d] %d, gifts = %d, index = %d\n", n, arr[n], gifts, index);
                maxgifts = gifts;
                result = n;
            }
        }

        if (sum[N] <= S) {
            result = 0;
        }

        printf("%d\n", result);
    }

    return 0;
}
