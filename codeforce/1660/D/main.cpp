#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int arr[200005];

struct elem {
    int max[2];
    int lmax[2];
    int rmax[2];
    int mul[2];
};

elem tree[200005 * 4];
const elem def = { {1, 1}, {1, 1}, {1, 1}, {1, 1} };

bool update(int node, int l, int r, int i, int value) {
    if (i < l || r < i) return false;

    elem& cur = tree[node];

    if (l == r) {
        for (int j = 0; j < 2; j++) {
            cur.max[j] = 1;
            cur.lmax[j] = 1;
            cur.rmax[j] = 1;
            cur.mul[j] = 0;
        }

        bool sign = value < 0;
        value = abs(value);

        cur.max[sign] = max(cur.max[sign], value);
        cur.lmax[sign] = max(cur.lmax[sign], value);
        cur.rmax[sign] = max(cur.rmax[sign], value);
        cur.mul[sign] = value;

        return true;
    }

    int mid = (l + r) / 2;
    int leftNode = node * 2 + 1;
    int rightNode = node * 2 + 2;
    bool isLeft = update(leftNode, l, mid, i, value);
    bool isRight = update(rightNode, mid + 1, r, i, value);

    const elem& left = isLeft ? tree[leftNode] : def;
    const elem& right = isRight ? tree[rightNode] : def;

    for (int j = 0; j < 2; j++) {
        cur.mul[j] = 0;
        cur.mul[j] += left.mul[0] * right.mul[j];
        cur.mul[j] += left.mul[1] * right.mul[!j];

        cur.lmax[j] = max(left.lmax[j], cur.mul[j]);
        cur.lmax[j] = max(cur.lmax[j], left.mul[0] * right.lmax[j]);
        cur.lmax[j] = max(cur.lmax[j], left.mul[1] * right.lmax[!j]);

        cur.rmax[j] = max(right.rmax[j], cur.mul[j]);
        cur.rmax[j] = max(cur.rmax[j], right.mul[0] * left.rmax[j]);
        cur.rmax[j] = max(cur.rmax[j], right.mul[1] * left.rmax[!j]);

        cur.max[j] = max(left.max[j], right.max[j]);
        cur.max[j] = max(cur.max[j], left.rmax[0] * right.lmax[j]);
        cur.max[j] = max(cur.max[j], left.rmax[1] * right.lmax[!j]);
    }

    return true;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);

        memset(tree, 0, sizeof(tree));

        for (int n = 0; n < N; n++) {
            scanf("%d", arr + n);

            update(0, 0, N - 1, n, arr[n]);
        }

        const elem& test = tree[0];
        printf("\t%d %d\n", test.max[0], test.max[1]);
        printf("\t%d %d\n", test.lmax[0], test.lmax[1]);
        printf("\t%d %d\n", test.rmax[0], test.rmax[1]);
        printf("\t%d %d\n", test.mul[0], test.mul[1]);

        printf("%d %d\n", 0, 0);
    }

    return 0;
}
