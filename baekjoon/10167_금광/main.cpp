#include <cstdio>
#include <algorithm>
#include <list>

using namespace std;

struct point {
    int x, y;
    long long w;
};

bool xComp(const point& a, const point& b) {
    if (a.x == b.x) return false;
    return a.x < b.x;
}

bool yComp(const point& a, const point& b) {
    if (a.y == b.y) return false;
    return a.y < b.y;
}

point points[3003];
list<point> buffer;

void insert(point& p) {
    buffer.insert(lower_bound(buffer.begin(), buffer.end(), p, yComp), p);
}

int main() {
    int N; // 3000
    scanf("%d", &N);
    for (int n = 0; n < N; n++) {
        int x, y, w; // 1e9, 1e9, -1e9 ~ 1e9
        scanf("%d %d %d", &x, &y, &w);
        points[n] = {x, y, w};
    }

    sort(points, points + N, xComp);

    long long answer = 0;

    for (int n = 0; n < N; n = upper_bound(points, points + N, points[n], xComp) - points) {
        buffer.clear();

        for (int m = n; m < N;) {
            int next = upper_bound(points, points + N, points[m], xComp) - points;

            while (m < next) insert(points[m++]);

            long long sum = 0;
            long long minSum = 0;

            for (auto it = buffer.begin(); it != buffer.end(); it++) {
                sum += it->w;

                auto next = it;
                next++;

                while (next != buffer.end() && next->y == it->y) {
                    it++;
                    next++;

                    sum += it->w;
                }

                minSum = min(minSum, sum);

                answer = max(answer, sum - minSum);
            }
        }
    }

    printf("%lld\n", answer);

    return 0;
}
