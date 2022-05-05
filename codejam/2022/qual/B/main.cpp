#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        int minC = 0x3f3f3f3f;
        int minM = 0x3f3f3f3f;
        int minY = 0x3f3f3f3f;
        int minK = 0x3f3f3f3f;

        for (int i = 0; i < 3; i++) {
            int c, m, y, k;
            scanf("%d %d %d %d", &c, &m, &y, &k);

            minC = min(minC, c);
            minM = min(minM, m);
            minY = min(minY, y);
            minK = min(minK, k);
        }

        printf("Case #%d: ", t);

        if (minC + minM + minY + minK >= 1e6) {
            int cur = 1e6;

            int c = min(cur, minC); cur -= c;
            int m = min(cur, minM); cur -= m;
            int y = min(cur, minY); cur -= y;
            int k = cur;
            printf("%d %d %d %d\n", c, m, y, k);
        } else {
            printf("IMPOSSIBLE\n");
        }
    }

    return 0;
}
