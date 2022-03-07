#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int arr[100005];
int remains[100005];

// min segment tree
int firstAppear[40004];

int update(int node, int l, int r, int i, int value) {
    if (i < l || r < i) return firstAppear[node];

    if (l == r) {
        if (firstAppear[node] == -1) firstAppear[node] = value;
        else firstAppear[node] = min(firstAppear[node], value);

        return firstAppear[node];
    }

    int mid = (l + r) / 2;
    int left = update(node * 2 + 1, l, mid, i, value);
    int right = update(node * 2 + 2, mid + 1, r, i, value);

    if (left == -1) firstAppear[node] = right;
    else if (right == -1) firstAppear[node] = left;
    else firstAppear[node] = min(left, right);

    return firstAppear[node];
}

int query(int node, int l, int r, int i, int j) {
    if (i > j) return -1;
    if (j < l || r < i) return -1;

    if (i <= l && r <= j) {
        return firstAppear[node];
    }

    int mid = (l + r) / 2;
    int left = query(node * 2 + 1, l, mid, i, j);
    int right = query(node * 2 + 2, mid + 1, r, i, j);

    if (left == -1) return right;
    else if (right == -1) return left;
    else return min(left, right);
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, X; // 1e5, 1e4
        scanf("%d %d", &N, &X);

        for (int n = 1; n <= N; n++) {
            scanf("%d", arr + n);
        }

        for (int n = 1; n <= N; n++) {
            remains[n] = remains[n - 1] + arr[n] % X;
            remains[n] %= X;
        }

        int result = -1;

        memset(firstAppear, -1, sizeof(firstAppear));

        for (int n = 0; n <= N; n++) {
            int value = (X - remains[n]) % X;
            int l = query(0, 0, X - 1, 0, value - 1);
            int r = query(0, 0, X - 1, value + 1, X - 1);

            int m;
            if (l == -1) m = r;
            else if (r == -1) m = l;
            else m = min(l, r);

            result = max(result, m != -1 ? n - m : -1);

            update(0, 0, X - 1, remains[n], n);
        }

        printf("%d\n", result);
    }

    return 0;
}
