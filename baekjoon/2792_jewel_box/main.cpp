#include <cstdio>

using namespace std;

int amounts[300005];

int main() {
    int N, M;
    long long totalAmounts = 0;
    scanf("%d %d", &N, &M);
    for (int m = 0; m < M; m++) {
        scanf("%d", amounts + m);
        totalAmounts += amounts[m];
    }

    long long l = 0;
    long long r = totalAmounts;
    long long mid = (l + r) / 2;

    while (l < r) {
        long long students = N;
        for (int m = 0; m < M; m++) {
            long long amount = amounts[m];

            students -= amount / mid + ((amount % mid) > 0);
        }

        if (students < 0) {
            l = mid + 1;
        } else {
            r = mid;
        }

        mid = (l + r) / 2;
    }

    printf("%lld\n", mid);

    return 0;
}