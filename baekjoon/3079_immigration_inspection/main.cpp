#include <cstdio>
#include <algorithm>

using namespace std;

int time[100005];

int main() {
    long long N, M;
    scanf("%lld %lld", &N, &M);
    for (int n = 0; n < N; n++) {
        scanf("%d", time + n);
    }

    long long l = 0;
    long long r = 1e18;
    long long mid = (l + r) / 2;

    while (l < r) {
        long long count = 0;
        for (int n = 0; n < N; n++) {
            count += mid / time[n];
            count = min(count, M);
        }

        if (count >= M) {
            r = mid;
        } else {
            l = mid + 1;
        }

        mid = (l + r) / 2;
    }

    printf("%lld\n", mid);

    return 0;
}