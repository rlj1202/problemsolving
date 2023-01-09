#include <cstdio>
#include <algorithm>

using namespace std;

int arr[200005];
long long sum[600005];

int main() {
    int N; // 2e5
    scanf("%d", &N);
    for (int n = 0; n < N; n++) {
        scanf("%d", arr + n); // 4e5
    }

    for (int n = 0; n < N; n++) {
        sum[arr[n] - n + N] += (long long) arr[n];
    }

    long long result = 0;
    for (int n = 0; n < 600005; n++) {
        result = max(result, sum[n]);
    }

    printf("%lld\n", result);

    return 0;
}
