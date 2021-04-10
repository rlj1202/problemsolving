#include <cstdio>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;

struct node {
    int value;
    int index;

    bool operator< (const node &o) const {
        if (value == o.value) return index < o.index;
        return value < o.value;
    }
};

node tree[400005];

node update(int node, int p, int q, int i, int v) {
    if (i < p || q < i) return tree[node];
    if (p == q) return tree[node] = {v, i};

    int mid = (p + q) / 2;

    return tree[node] = min(update(node * 2, p, mid, i, v),
                            update(node * 2 + 1, mid + 1, q, i , v));
}

node query(int node, int p, int q, int i, int j) {
    if (j < p || q < i) return {INF, 0};
    if (i <= p && q <= j) return tree[node];

    int mid = (p + q) / 2;

    return min(query(node * 2, p, mid, i, j),
               query(node * 2 + 1, mid + 1, q, i, j));
}

int main() {
    int N;
    scanf("%d", &N);
    for (int n = 1; n <= N; n++) {
        int value;
        scanf("%d", &value);

        update(1, 1, N, n, value);
    }

    int M;
    scanf("%d", &M);
    while (M--) {
        int cmd;
        scanf("%d", &cmd);

        if (cmd == 1) {
            int i, v;
            scanf("%d %d", &i, &v);

            update(1, 1, N, i, v);
        } else if (cmd == 2) {
            int i, j;
            scanf("%d %d", &i, &j);

            printf("%d\n", query(1, 1, N, i, j).index);
        }
    }

    return 0;
}