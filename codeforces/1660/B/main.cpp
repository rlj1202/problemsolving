#include <cstdio>
#include <algorithm>

using namespace std;

int arr[200005];

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);
        for (int n = 0; n < N; n++) {
            scanf("%d", arr + n); // 1e9
        }
        sort(arr, arr + N);

        bool result = true;

        if (N == 1) {
            if (arr[0] > 1) {
                result = false;
            }
        } else {
            if (arr[N - 1] - arr[N - 2] >= 2) {
                result = false;
            }
        }

        printf("%s\n", result ? "YES" : "NO");
    }

    return 0;
}
