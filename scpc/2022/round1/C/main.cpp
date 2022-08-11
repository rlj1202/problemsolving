#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

struct point {
    int x, y;

    point *left;
    point *right;
    point *top;
    point *bottom;

    bool visited;

    point() : point(0, 0) {
    }

    point(int x, int y) :
        x(x), y(y),
        left(nullptr), right(nullptr),
        top(nullptr), bottom(nullptr),
        visited(false) {
    }

    bool operator<(const point &o) const {
        if (x == o.x) return y < o.y;
        return x < o.x;
    }

    int count() {
        int result = 0;
        if (left) result++;
        if (right) result++;
        if (top) result++;
        if (bottom) result++;
        return result;
    }

    int dist(const point &o) {
        return abs(x - o.x) + abs(y - o.y);
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T;
    cin >> T;
    
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;

        vector<point> points(N);

        for (int n = 0; n < N; n++) {
            cin >> points[n].x >> points[n].y;
        }
        sort(points.begin(), points.end());

        map<int, point*> leftPoints;
        leftPoints[points[0].y] = &points[0];

        for (int n = 1; n < N; n++) {
            point &cur = points[n];
            point &prev = points[n - 1];

            if (cur.x == prev.x) {
                cur.bottom = &prev;
                prev.top = &cur;
            }
            if (leftPoints.count(cur.y)) {
                point *l = leftPoints[cur.y];

                cur.left = l;
                l->right = &cur;
            }

            leftPoints[cur.y] = &cur;
        }

        queue<point*> q;

        for (int n = 0; n < N; n++) {
            point &cur = points[n];

            if (cur.count() == 2 && !(cur.left && cur.right) && !(cur.top && cur.bottom)) {
                q.push(&cur);
            }
        }

        ll answer = 0;

        while (!q.empty()) {
            point *cur = q.front();
            q.pop();

            if (cur->visited) continue;
            cur->visited = true;

            if (cur->left) {
                answer += cur->dist(*cur->left);
                cur->left->right = nullptr;

                cout << "(" << cur->x << "," << cur->y << "), left, " << cur->dist(*cur->left) << '\n';

                if (cur->left->count() == 1) {
                    q.push(cur->left);
                }
            }
            if (cur->right) {
                answer += cur->dist(*cur->right);
                cur->right->left = nullptr;

                cout << "(" << cur->x << "," << cur->y << "), right, " << cur->dist(*cur->right) << '\n';

                if (cur->right->count() == 1) {
                    q.push(cur->right);
                }
            }
            if (cur->top) {
                answer += cur->dist(*cur->top);
                cur->top->bottom = nullptr;

                cout << "(" << cur->x << "," << cur->y << "), top, " << cur->dist(*cur->top) << '\n';

                if (cur->top->count() == 1) {
                    q.push(cur->top);
                }
            }
            if (cur->bottom) {
                answer += cur->dist(*cur->bottom);
                cur->bottom->top = nullptr;

                cout << "(" << cur->x << "," << cur->y << "), bottom, " << cur->dist(*cur->bottom) << '\n';

                if (cur->bottom->count() == 1) {
                    q.push(cur->bottom);
                }
            }
        }

        cout << "Case #" << t << '\n';
        cout << answer << '\n';
    }

    cout << '\n';

    return 0;
}
