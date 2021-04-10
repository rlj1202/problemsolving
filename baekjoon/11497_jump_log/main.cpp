#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        // 1e4
        int N;
        scanf("%d", &N);
        int heights[10004];
        for (int n = 0; n < N; n++) {
            // 1e5
            scanf("%d", heights + n);
        }

        sort(heights, heights + N);

        int result = 0;

        for (int i = 0; i < N - 1; i++) {
            int delta = heights[min(i + 2, N - 1)] - heights[i];

            result = max(result, delta);
        }

        printf("%d\n", result);
    }

    return 0;
}