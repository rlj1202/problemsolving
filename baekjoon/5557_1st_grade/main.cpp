#include <cstdio>

using namespace std;

int arr[102];

long long count[102][21];

int main() {
    int N;
    scanf("%d", &N);
    for (int n = 0; n < N; n++) {
        scanf("%d", arr + n);
    }

    count[0][arr[0]] = 1;

    for (int n = 1; n < N - 1; n++) {
        for (int i = 0; i <= 20; i++) {
            if ((0 <= i - arr[n]) && (i - arr[n] <= 20))
                count[n][i] += count[n - 1][i - arr[n]];

            if ((0 <= i + arr[n]) && (i + arr[n] <= 20))
                count[n][i] += count[n - 1][i + arr[n]];
        }
    }

    printf("%lld\n", count[N - 2][arr[N - 1]]);

    return 0;
}