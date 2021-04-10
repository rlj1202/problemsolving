#include <cstdio>
#include <algorithm>

using namespace std;

struct point {
    int x, y;

    bool operator < (const point &o) const {
        if (x == o.x) return y < o.y;
        return x < o.x;
    }
};

point ores[102];

int count_point(point *begin, point *end, point origin, int range) {
    int count = 0;

    for (; begin < end; begin++) {
        int dx = origin.x - begin->x;
        int dy = origin.y - begin->y;

        if (-range <= dx && dx <= range &&
            -range <= dy && dy <= range) {
            count++;
        }
    }

    return count;
}

int main() {
    // width, height, number of ores, size of rectangle
    // 1e6, 1e6, 100, 1e7
    int N, M, T, K;
    scanf("%d %d %d %d", &N, &M, &T, &K);
    for (int t = 0; t < T; t++) {
        int a, b;
        scanf("%d %d", &a, &b);
        ores[t] = {a - b, a + b}; // Turn point 45 degree to left
                                  // and scale coordinate system by root 2.
                                  // Then, a side of rectangle size will be
                                  // (K / 2 * root 2) * root 2 = K.
    }
    sort(ores, ores + T);

    int l = 0;
    int r = 0;

    point result;
    int max_count = 0;

    while (r < T) {
        r++;
        while (r < T && ores[r - 1].x == ores[r].x) r++;
        while (l < r && (ores[r - 1].x - ores[l].x) > K) l++;

        for (int i = l; i < r; i++) {
            point a = ores[i];

            point origin = {
                ores[r - 1].x - K / 2,
                a.y - K / 2
            };

            if ((origin.x + origin.y) % 2 == 0) {
                int count = count_point(ores + l, ores + r, origin, K / 2);

                if (max_count < count) {
                    max_count = count;
                    result = origin;
                }
            } else {
                point tmp;
                int count;

                tmp = { origin.x + 1, origin.y };
                count = count_point(ores + l, ores + r, tmp, K / 2);

                if (max_count < count) {
                    max_count = count;
                    result = tmp;
                }

                tmp = { origin.x, origin.y + 1 };
                count = count_point(ores + l, ores + r, tmp, K / 2);

                if (max_count < count) {
                    max_count = count;
                    result = tmp;
                }
            }
        }
    }

    printf(
        "%d %d\n",
        max(result.x + result.y, 0) / 2,
        max(result.y - result.x, 0) / 2
    );
    printf("%d\n", max_count);

    return 0;
}