#include <cstdio>
#include <cmath>

using namespace std;

const int INF = 0x7fffffff;

struct point {
    int x, y;

    int dist_2(const point &o) const {
        int dx = x - o.x;
        int dy = y - o.y;
        return dx*dx + dy*dy;
    }
};

point points[1003];

int main() {
    // 1e3
    int N;
    scanf("%d", &N);
    for (int n = 0; n < N; n++) {
        int x, y;
        scanf("%d %d", &x, &y);
        points[n] = { x, y };
    }

    int min_dist = INF;
    int closest = 0;
    int farthest = 0;

    for (int n = 0; n < N; n++) {
        int max_dist = 0;
        int max_point = n;

        for (int m = 0; m < N; m++) {
            int dist = points[n].dist_2(points[m]);
            if (max_dist < dist) {
                max_dist = dist;
                max_point = m;
            }
        }

        if (min_dist >= max_dist) {
            min_dist = max_dist;
            closest = n;
            farthest = max_point;
        }
    }

    printf("%.12lf %.12lf\n", (double) points[closest].x, (double) points[closest].y);

    return 0;
}