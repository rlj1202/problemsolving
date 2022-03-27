#include <cstdio>
#include <algorithm>

using namespace std;

struct point { int x, y; };

bool operator< (const point& a, const point& b) {
    return a.x < b.x;
}

point points[10004];

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, K;
        scanf("%d %d", &N, &K);
        for (int n = 0; n < N; n++) {
            int x, y;
            scanf("%d %d", &x, &y);

            points[n] = { x, y };
        }

        sort(points, points + N);

        double l = 0;
        double r = 1e9;

        while ((r - l) > 0.01) {
            double mid = (l + r) / 2.0;

            int turnnels = 1;

            int minHeight = points[0].y;
            int maxHeight = points[0].y;
            for (int n = 0; n < N; n++) {
                minHeight = min(minHeight, points[n].y);
                maxHeight = max(maxHeight, points[n].y);

                if ((maxHeight - minHeight) / 2.0 > mid) {
                    turnnels++;

                    minHeight = points[n].y;
                    maxHeight = points[n].y;
                }
            }

            if (turnnels <= K) {
                r = mid;
            } else {
                l = mid;
            }
        }

        printf("%.1lf\n", l);
    }

    return 0;
}
