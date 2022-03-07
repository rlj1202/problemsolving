#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

struct point {
    int x, y, w;
};

bool xComp(const point& a, const point& b) {
    return b.x - a.x > 0;
}

point points[3003];

long long sum[3003 * 4];
long long lsum[3003 * 4];
long long rsum[3003 * 4];
long long maxsum[3003 * 4];

void update(int node, int l, int r, int i, int delta) {
    if (i < l || r < i) return;

    if (l == r) {
        sum[node] += delta;
        lsum[node] += delta;
        rsum[node] += delta;
        maxsum[node] += delta;
        return;
    }

    int lnode = node*2 + 1;
    int rnode = node*2 + 2; 

    int mid = (l + r) / 2;
    update(lnode, l, mid, i, delta);
    update(rnode, mid + 1, r, i, delta);

    sum[node] = sum[lnode] + sum[rnode];
    lsum[node] = max(lsum[lnode], sum[lnode] + lsum[rnode]);
    rsum[node] = max(rsum[rnode], sum[rnode] + rsum[lnode]);
    maxsum[node] = max(max(maxsum[node*2 + 1], maxsum[node*2 + 2]), max(sum[node], lsum[rnode] + rsum[lnode]));
}

int main() {
    int N;
    scanf("%d", &N);
    for (int n = 0; n < N; n++) {
        int x, y, w;
        scanf("%d %d %d", &x, &y, &w);
        points[n] = {x, y, w};
    }

    sort(points, points + N, xComp);

    // compress x coordinates
    int prevXCoord = points[0].x;
    points[0].x = 0;
    for (int n = 1; n < N; n++) {
        if (points[n].x == prevXCoord) {
            points[n].x = points[n - 1].x;
        } else {
            prevXCoord = points[n].x;
            points[n].x = points[n - 1].x + 1;
        }
    }

    // flip x and y coordinates
    for (int n = 0; n < N; n++) {
        swap(points[n].x, points[n].y);
    }
    sort(points, points + N, xComp);

    long long result = 0;

    for (int n = 0; n < N; n = upper_bound(points, points + N, points[n], xComp) - points) {
        memset(sum, 0, sizeof(sum));
        memset(lsum, 0, sizeof(lsum));
        memset(rsum, 0, sizeof(rsum));
        memset(maxsum, 0, sizeof(maxsum));

        for (int m = n; m < N;) {
            int next = upper_bound(points, points + N, points[m], xComp) - points;

            while (m < next) {
                update(0, 0, N - 1, points[m].y, points[m].w);
                m++;
            }

            result = max(result, maxsum[0]);
        }
    }

    printf("%lld\n", result);

    return 0;
}
