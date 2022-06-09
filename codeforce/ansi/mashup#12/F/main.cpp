#include <cstdio>
#include <set>

using namespace std;

int arr[200005];
long long sum[200005];

set<long long> s;

int main() {
    int N;
    scanf("%d", &N);
    for (int n = 1; n <= N; n++) {
        scanf("%d", arr + n);
    }

    for (int n = 1; n <= N; n++) {
        sum[n] = sum[n - 1] + (long long) arr[n];
    }

    int right = 1;

    long long result = 0;

    s.insert(0);

    for (int n = 1; n <= N; n++) {
        while (right <= N && s.count(sum[right]) == 0) {
            s.insert(sum[right++]);
        }

        result += (long long) (right - n);
        s.erase(sum[n - 1]);
    }

    printf("%lld\n", result);

    return 0;
}
