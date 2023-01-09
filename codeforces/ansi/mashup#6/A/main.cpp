#include <cstdio>
#include <algorithm>

using namespace std;

const long long MOD = 1e9 + 7;

int arr[1003];
long long comb[1003][1003];

int main() {
    int T;
    scanf("%d", &T);

    comb[0][0] = 1;
    for (int r = 1; r < 1003; r++) {
        comb[r][0] = 1;

        for (int c = 0; c < 1003; c++) {
            comb[r][c] = comb[r - 1][c - 1] + comb[r - 1][c];
            comb[r][c] %= MOD;
        }
    }

    while (T--) {
        int N, K;
        scanf("%d %d", &N, &K);
        for (int n = 0; n < N; n++) {
            scanf("%d", arr + n);
        }
        sort(arr, arr + N);

        int a = upper_bound(arr + N - K, arr + N, arr[N - K]) - (arr + N - K);
        int b = (arr + N - K) - lower_bound(arr, arr + N - K, arr[N - K]);

        printf("%lld\n", comb[a + b][a]);
    }

    return 0;
}
