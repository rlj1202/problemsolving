#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int arr[100005];

int main() {
    int N;
    scanf("%d", &N);
    for (int n = 0; n < N; n++) {
        scanf("%d", arr + n);
    }

    sort(arr, arr + N);

    long long l = 1;
    long long r = 1;
    while (true) {
        bool valid = true;
        long long cur = 1;
        for (int n = 0; n < N; n++) {
            long long next = cur * (r + 1);
            if (cur > next) {
                valid = false;
                break;
            }
            cur = next;
        }
        if (valid) {
            r++;
        } else {
            break;
        }
    }

    while (r - l) {
        long long mid1 = (l*2 + r) / 3;
        long long mid2 = (l + r*2 + 2) / 3;

        long long cost1 = 0;
        long long cur1 = 1;
        for (int n = 0; n < N; n++) {
            cost1 += abs(cur1 - arr[n]);
            cur1 *= mid1;
        }

        long long cost2 = 0;
        long long cur2 = 1;
        for (int n = 0; n < N; n++) {
            cost2 += abs(cur2 - arr[n]);
            cur2 *= mid2;
        }

        if (cost1 < cost2) {
            r = mid2 - 1;
        } else if (cost1 > cost2) {
            l = mid1 + 1;
        } else {
            l = mid1;
        }
    }

    long long cost = 0;
    long long cur = 1;
    for (int n = 0; n < N; n++) {
        cost += abs(cur - arr[n]);
        cur *= l;
    }

    printf("%lld\n", cost);

    return 0;
}
