#include <algorithm>
#include <cstdio>

using namespace std;

int arr[1003];

int dp[1003];

int main() {
    int N;
    scanf("%d", &N);

    for (int n = 0; n < N; n++) {
        scanf("%d", arr + n);
    }

    int answer = 0;

    for (int n = 0; n < N; n++) {
        dp[n] = 1;

        for (int m = 0; m < n; m++) {
            if (arr[m] > arr[n]) {
                dp[n] = max(dp[n], dp[m] + 1);
            }
        }

        answer = max(answer, dp[n]);
    }

    printf("%d\n", answer);

    return 0;
}