#include <cstdio>
#include <algorithm>

using namespace std;

int arr[100005];
int maxlen[100005];

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);
        for (int n = 1; n <= N; n++) {
            scanf("%d", arr + n);
        }

        int result = 0;

        for (int n = N; n >= 1; n--) {
            maxlen[n] = 1;

            for (int m = 2; n*m <= N; m++) {
                if (arr[n] >= arr[n*m]) continue;

                maxlen[n] = max(maxlen[n], maxlen[n*m] + 1);
            }

            result = max(result, maxlen[n]);
        }

        printf("%d\n", result);
    }

    return 0;
}
