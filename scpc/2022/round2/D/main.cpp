#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;

int grid[302][302];

struct node {
    int min_r, min_c;
    int max_r, max_c;

    int width() { return max_c - min_c + 1; }
    int height() { return max_r - min_r + 1; }
    int area() { return width() * height(); }
};

node segtree[302 * 302 * 4];

void update(int nodeidx, int l, int r, int i, int row, int col) {
    if (i < l || r < i) return;

    node &cur = segtree[nodeidx];

    if (l == r) {
        cur.min_r = min(cur.min_r, row);
        cur.max_r = max(cur.max_r, row);
        cur.min_c = min(cur.min_c, col);
        cur.max_c = max(cur.max_c, col);
        return;
    }

    int mid = (l + r) / 2;
    update(nodeidx * 2, l, mid, i, row, col);
    update(nodeidx * 2 + 1, mid + 1, r, i, row, col);

    node &left = segtree[nodeidx * 2];
    node &right = segtree[nodeidx * 2 + 1];

    cur.min_r = min(left.min_r, right.min_r);
    cur.max_r = max(left.max_r, right.max_r);
    cur.min_c = min(left.min_c, right.min_c);
    cur.max_c = max(left.max_c, right.max_c);
}

node query(int nodeidx, int l, int r, int i, int j) {
    if (r < i || j < l) {
        return { INF, INF, -INF, -INF };
    }
    if (i <= l && r <= j) {
        return segtree[nodeidx];
    }

    int mid = (l + r) / 2;
    node left = query(nodeidx * 2, l, mid, i, j);
    node right = query(nodeidx * 2 + 1, mid + 1, r, i, j);

    node result;
    result.min_r = min(left.min_r, right.min_r);
    result.max_r = max(left.max_r, right.max_r);
    result.min_c = min(left.min_c, right.min_c);
    result.max_c = max(left.max_c, right.max_c);

    return result;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;

        fill<node*, node>(segtree + 1, segtree + N*N*4+1, { INF, INF, -INF, -INF });

        for (int r = 1; r <= N; r++) {
            for (int c = 1 ; c <= N; c++) {
                cin >> grid[r][c];
                update(1, 1, N*N, grid[r][c], r, c);
            }
        }

        int answer = N*N;

        for (int a = 1; a <= N*N; a++) {
            for (int b = a + 1; b <= N*N;) {
                node box = query(1, 1, N*N, a, b);

                int cnt = b - a + 1;

                if (cnt == box.area()) {
                    answer++;
                    b += min(box.width(), box.height());
                } else {
                    b = a + box.area() - 1;
                }
            }
        }

        cout << "Case #" << t << '\n';
        cout << answer << '\n';
        cout << flush;
    }

    return 0;
}
