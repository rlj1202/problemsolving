#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

struct circle {
    int x, y, r;

    double distance(circle &o) {
        long long dx = x - o.x;
        long long dy = y - o.y;
        return max(0.0, sqrt(dx * dx + dy * dy) - r - o.r);
    }
};

struct edge {
    int p, q;
    double weight;

    bool operator>(const edge &o) const { return weight > o.weight; }
};

circle circles[1003];

priority_queue<edge, vector<edge>, greater<edge>> pq;
int parents[1003];

int find(int a) {
    if (parents[a] == -1)
        return a;
    return parents[a] = find(parents[a]);
}

bool merge(int a, int b) {
    int A = find(a);
    int B = find(b);

    if (A == B)
        return false;

    parents[A] = B;

    return true;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int W, N;
        scanf("%d %d", &W, &N);
        for (int n = 1; n <= N; n++) {
            int x, y, r;
            scanf("%d %d %d", &x, &y, &r);
            circles[n] = {x, y, r};
        }

        for (int i = 1; i <= N; i++) {
            for (int j = i + 1; j <= N; j++) {
                pq.push({i, j, circles[i].distance(circles[j])});
            }
            pq.push({0, i, max(0.0, (double)(circles[i].x - circles[i].r))});
            pq.push({N + 1, i,
                max(0.0, (double)(W - circles[i].x - circles[i].r))});
        }
        pq.push({0, N + 1, (double)W});

        memset(parents, -1, sizeof(parents));
        while (!pq.empty()) {
            edge cur = pq.top();
            pq.pop();

            if (merge(cur.p, cur.q)) {
                if (find(0) == find(N + 1)) {
                    if (cur.weight == 0.0) {
                        printf("0\n");
                    } else {
                        printf("%.6lf\n", cur.weight / 2.0f);
                    }
                    break;
                }
            }
        }
        while (!pq.empty())
            pq.pop();
    }

    return 0;
}