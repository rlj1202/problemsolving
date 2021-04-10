#include <cstdio>
#include <algorithm>

using namespace std;

const long long INF = 0x7fffffffffffffff;

struct node {
    long long min_value;
    int index;
};

node tree[400005];

node min(const node &a, const node &b) {
    if (a.min_value == b.min_value) return a.index < b.index ? a : b;
    return a.min_value < b.min_value ? a : b;
}

node update(int index, int tl, int tr, int i, int value) {
    if (i < tl || tr < i) return tree[index];
    if (tl == tr) return tree[index] = { value, i };

    int mid = (tl + tr) / 2;

    return tree[index] = min(
        update(index * 2, tl, mid, i, value),
        update(index * 2 + 1, mid + 1, tr, i, value)
        );
}

node query(int index, int tl, int tr, int l, int r) {
    if (tr < l || r < tl) return { INF, 0 };
    if (l <= tl && tr <= r) return tree[index];

    int mid = (tl + tr) / 2;

    return min(
        query(index * 2, tl, mid, l, r),
        query(index * 2 + 1, mid + 1, tr, l, r)
        );
}

long long solve(int N, int l, int r) {
    if (l > r) return 0;

    node min_node = query(1, 1, N, l, r);
    long long area = (r - l + 1) * min_node.min_value;

    return max(area, max(solve(N, l, min_node.index - 1), solve(N, min_node.index + 1, r)));
}

int main() {
    while (true) {
        int N;
        scanf("%d", &N);
        if (N == 0) break;

        for (int n = 1; n <= N; n++) {
            int height;
            scanf("%d", &height);
            update(1, 1, N, n, height);
        }

        printf("%lld\n", solve(N, 1, N));
    }

    return 0;
}