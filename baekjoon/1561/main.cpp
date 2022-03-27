#include <cstdio>

using namespace std;

int arr[10004];

int main() {
    long long N, M; // 2e9, 1e4
    scanf("%lld %lld", &N, &M);
    for (int m = 0; m < M; m++) {
        scanf("%d", arr + m);
    }

    long long l = 0;
    long long r = 1e12;
    long long mid = (l + r) / 2;

    while (l < r) {
        long long minutes = mid;

        long long maxChildren = 0;
        for (int m = 0; m < M; m++) {
            maxChildren += (minutes + arr[m] - 1) / arr[m];
        }

        if (maxChildren >= N) {
            r = mid - 1;
        } else {
            l = mid;
        }

        mid = (l + r + 1) / 2;
    }

    long long cur = 0;
    for (int m = 0; m < M; m++) {
        cur += (mid + arr[m] - 1) / arr[m];
    }

    long long answer;

    for (int m = 0; m < M; m++) {
        if (mid % arr[m] == 0) {
            cur++;
        }

        if (cur == N) {
            answer = m + 1;
            break;
        }
    }

    printf("%lld\n", answer);

    return 0;
}
