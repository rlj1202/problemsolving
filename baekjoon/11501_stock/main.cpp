#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        // 1e6
        int N;
        scanf("%d", &N);
        int stock_prices[1000006];

        for (int n = 0; n < N; n++) {
            // 1e4
            scanf("%d", stock_prices + n);
        }
        stock_prices[N] = 0;

        int future_max[1000006];
        future_max[N] = 0;
        for (int n = N - 1; n >= 0; n--) {
            future_max[n] = max(future_max[n + 1], stock_prices[n]);
        }

        long long result = 0;
        long long cur_stock = 0;

        for (int n = 0; n < N; n++) {
            if (stock_prices[n] > future_max[n + 1]) {
                result += cur_stock * stock_prices[n];
                cur_stock = 0;
            } else {
                result -= stock_prices[n];
                cur_stock++;
            }
        }

        printf("%lld\n", result);
    }

    return 0;
}