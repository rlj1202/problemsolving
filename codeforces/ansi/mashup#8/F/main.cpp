#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int arr[300005];

bool is_pointy(int a, int b, int c) {
    return (a < b && b > c) || (a > b && b < c);
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);
        for (int n = 1; n <= N; n++) {
            scanf("%d", arr + n);
        }
        arr[0] = arr[1];
        arr[N + 1] = arr[N];

        int pointies = 0;

        for (int n = 1; n <= N; n++) {
            pointies += is_pointy(arr[n - 1], arr[n], arr[n + 1]);
        }

        int result = pointies;

        for (int n = 2; n <= N - 1; n++) {
            if (is_pointy(arr[n - 1], arr[n], arr[n + 1])) {
                int a = arr[n - 2];
                int b = arr[n - 1];
                int c = arr[n];
                int d = arr[n + 1];
                int e = arr[n + 2];

                int cur = 1;
                cur += is_pointy(arr[n - 2], arr[n - 1], arr[n]);
                cur += is_pointy(arr[n], arr[n + 1], arr[n + 2]);

                int next = min(
                    is_pointy(a, b, b) + is_pointy(b, d, e),
                    is_pointy(a, b, d) + is_pointy(d, d, e)
                );

                result = min(result, pointies - cur + next);
            }
        }

        printf("%d\n", result);
    }

    return 0;
}
