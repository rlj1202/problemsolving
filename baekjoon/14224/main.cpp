#include <cstdio>
#include <algorithm>

using namespace std;

struct point { long long x, y; };

point points[102];

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    for (int n = 0; n < N; n++) {
        long long x, y;
        scanf("%lld %lld", &x, &y);

        points[n] = { x, y };
    }

    long long l = 2;
    long long r = 2e9 + 2;

    while (r - l) {
        long long mid = (l + r) / 2;

        bool possible = false;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                long long minX = min(points[i].x, points[j].x);
                long long minY = min(points[i].y, points[j].y);

                int count = 0;

                for (int k = 0; k < N; k++) {
                    if (points[k].x < minX || minX + mid - 2 < points[k].x) continue;
                    if (points[k].y < minY || minY + mid - 2 < points[k].y) continue;
                    count++;
                }

                if (count >= K) {
                    possible = true;
                    break;
                }
            }

            if (possible) {
                break;
            }
        }

        if (possible) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    printf("%lld\n", l * l);

    return 0;
}
