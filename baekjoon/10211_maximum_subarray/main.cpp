#include <cstdio>
#include <algorithm>

using namespace std;

int arr[1003];

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);
        for (int n = 0; n < N; n++) {
            scanf("%d", arr + n);
        }

        int result = arr[0];

        int curSumMin = 0;
        int curSum = 0;
        for (int n = 0; n < N; n++) {
            curSum += arr[n];

            result = max(result, curSum - curSumMin);
            curSumMin = min(curSumMin, curSum);
        }

        printf("%d\n", result);
    }

    return 0;
}