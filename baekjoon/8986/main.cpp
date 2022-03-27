#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int arr[100005];

long long func(long long dist) {
    long long sum = 0;

    for (int n = 0; n < N; n++) {
        sum += abs(dist*n - (long long) arr[n]);
    }

    return sum;
}

int main() {
    scanf("%d", &N);
    for (int n = 0; n < N; n++) {
        scanf("%d", arr + n);
    }

    long long l = 0;
    long long r = 1e9;

    while (r - l) {
        long long mid1 = (l*2 + r) / 3;
        long long mid2 = (l + r*2 + 2) / 3;

        long long v1 = func(mid1);
        long long v2 = func(mid2);

        if (v1 < v2) {
            r = mid2 - 1;
        } else if (v1 > v2) {
            l = mid1 + 1;
        } else {
            l = mid1 + 1;
        }
    }

    printf("%lld\n", func(l));

    return 0;
}
