#include <algorithm>
#include <cstdio>

using namespace std;

struct point {
    long long x, y;

    long long distance_square(point &o) {
        long long deltaX = x - o.x;
        long long deltaY = y - o.y;
        return deltaX * deltaX + deltaY * deltaY;
    }
};

point points[500005];
point *tmp[500005];
int tmplen;

long long closest_distance_square(point *arr, int len) {
    if (len < 10) {
        long long result = std::numeric_limits<long long>::max();
        for (int i = 0; i < len - 1; i++) {
            for (int j = i + 1; j < len; j++) {
                result = min(result, arr[i].distance_square(arr[j]));
            }
        }
        return result;
    }

    int mid = len / 2;
    long long result = min(closest_distance_square(arr, mid),
        closest_distance_square(arr + mid, len - mid));

    tmplen = 0;
    for (int i = 0; i < len; i++) {
        long long delta = arr[i].x - arr[mid].x;
        if (delta * delta < result) {
            tmp[tmplen++] = arr + i;
        }
    }

    sort(tmp, tmp + tmplen, [](point *a, point *b) -> bool {
        if (a->y == b->y) return a->x < b->x;
        return a->y < b->y;
    });
    
    for (int i = 0; i < tmplen - 1; i++) {
        for (int j = i + 1; j < tmplen; j++) {
            int delta = tmp[i]->y - tmp[j]->y;
            if (delta >= result) break;

            result = min(result, tmp[i]->distance_square(*tmp[j]));
        }
    }

    return result;
}

int main() {
    int N;
    scanf("%d", &N);
    for (int n = 0; n < N; n++) {
        long long x, y;
        scanf("%lld %lld", &x, &y);
        points[n] = {x, y};
    }

    sort(points, points + N, [](point &a, point &b) -> bool {
        if (a.x == b.x) return a.y < b.y;
        return a.x < b.x;
    });

    long long result = closest_distance_square(points, N);
    printf("%lld\n", result);

    return 0;
}