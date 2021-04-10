#include <cstdio>
#include <algorithm>

using namespace std;

struct point { int x, y; };

int hunters[100005];
point animals[100005];

int main() {
    // 1e5, 1e5, 1e9
    int M, N, L;
    scanf("%d %d %d", &M, &N, &L);
    for (int m = 0; m < M; m++) {
        // 1e9
        scanf("%d", hunters + m);
    }
    for (int n = 0; n < N; n++) {
        // 1e9, 1e9
        int x, y;
        scanf("%d %d", &x, &y);
        animals[n] = {x, y};
    }

    sort(hunters, hunters + M);

    int result = 0;

    for (int n = 0; n < N; n++) {
        if (animals[n].y > L) continue;

        int leftmost = animals[n].x - (L - animals[n].y);
        int rightmost = animals[n].x + (L - animals[n].y);

        int *begin = lower_bound(hunters, hunters + M, leftmost);
        int *end = upper_bound(hunters, hunters + M, rightmost);

        if ((end - begin) > 0) {
            result++;
        }
    }

    printf("%d\n", result);

    return 0;
}