#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

struct point {
    int x, y;

    const int distance_square(point &o) {
        int dx = x - o.x;
        int dy = y - o.y;
        return dx * dx + dy * dy;
    }
};

point points[100005];

int get_closest_distance(point *arr, int len) {
    if (len < 10) {
        int result = 0x3f3f3f3f;
        for (int i = 0; i < len; i++)
            for (int j = i + 1; j < len; j++)
                result = min(result, arr[i].distance_square(arr[j]));
        return result;
    }

    int mid = len / 2;
    int result = min(get_closest_distance(arr, mid),
        get_closest_distance(arr + mid, len - mid));

    vector<point *> candidates;
    for (int i = 0; i < len; i++) {
        int delta = arr[i].x - arr[mid].x;
        if (delta * delta <= result)
            candidates.push_back(arr + i);
    }

    sort(candidates.begin(), candidates.end(), [](point *a, point *b) -> bool {
        if (a->y == b->y) return a->x < b->x;
        return a->y < b->y;
    });

    for (int i = 0; i < candidates.size(); i++) {
        for (int j = i + 1; j < candidates.size(); j++) {
            int delta = candidates[j]->y - candidates[i]->y;
            if (delta * delta >= result)
                break;

            result = min(result, candidates[i]->distance_square(*candidates[j]));
        }
    }

    return result;
}

int main() {
    int N;
    scanf("%d", &N);
    for (int n = 0; n < N; n++) {
        int x, y;
        scanf("%d %d", &x, &y);
        points[n] = {x, y};
    }

    sort(points, points + N, [](point &a, point &b) -> bool {
        if (a.x == b.x)
            return a.y < b.y;
        return a.x < b.x;
    });

    int result = get_closest_distance(points, N);
    printf("%d\n", result);

    return 0;
}