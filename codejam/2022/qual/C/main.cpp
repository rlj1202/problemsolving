#include <cstdio>
#include <algorithm>

using namespace std;

int arr[100005];

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        int N;
        scanf("%d", &N);
        for (int n = 0; n < N; n++) {
            scanf("%d", arr + n);
        }
        sort(arr, arr + N);

        int cur = 0;

        for (int i = 0; i < N; i++) {
            if (cur < arr[i]) {
                cur++;
            }
        }

        printf("Case #%d: %d\n", t, cur);
    }

    return 0;
}
