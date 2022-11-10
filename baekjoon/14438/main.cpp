#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

struct seg {
    int tree[100005 * 4];
    int limit;

    void init(int n) {
        for (limit = 1; limit < n; limit <<= 1);
        memset(tree, INF, sizeof(tree));
    }

    void update(int i, int value) {
        i += limit;

        tree[i] = value;

        while (i > 1) {
            i >>= 1;

            tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
        }
    }

    int query(int i, int j) {
        i += limit;
        j += limit;

        int result = INF;

        while (i < j) {
            if (i % 2 == 1) result = min(result, tree[i++]);
            if (j % 2 == 0) result = min(result, tree[j--]);

            i >>= 1;
            j >>= 1;
        }
        if (i == j) {
            result = min(result, tree[i]);
        }

        return result;
    }
} seg;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;

    seg.init(N);

    for (int n = 0; n < N; n++) {
        int value;
        cin >> value;

        seg.update(n, value);
    }

    int M;
    cin >> M;

    while (M--) {
        int cmd, a, b;
        cin >> cmd >> a >> b;

        if (cmd == 1) {
            seg.update(a - 1, b);
        } else if (cmd == 2) {
            int result = seg.query(a - 1, b - 1);

            cout << result << '\n';
        }
    }

    cout << '\n';

    return 0;
}
