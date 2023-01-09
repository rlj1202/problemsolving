#include <cstdio>
#include <algorithm>

using namespace std;

int arr[100005];
bool visited[1000006 * 4];
int counts[1000006 * 4];
int result[100005];

int update(int node, int l, int r, int i, int delta) {
    if (l == r) {
        if (l == i) counts[node] += delta;
        // printf("\t\t\tsingle [%d] %d\n", l, counts[node] > 0 ? -1 : l);
        return counts[node] > 0 ? -1 : l;
    }
    if (i < l || r < i) {
        if (visited[node])
            return counts[node];
    }

    visited[node] = true;

    int mid = (l + r) / 2;
    int left = update(node * 2 + 1, l, mid, i, delta);
    int right = update(node * 2 + 2, mid + 1, r, i, delta);

    if (left == -1) counts[node] = right;
    else if (right == -1) counts[node] = left;
    else counts[node] = min(left, right);

    // printf("\t(%d %d) = %d, %d %d, %d\n", l, r, counts[node], left, right, mid);

    return counts[node];
}

int query(int node, int l, int r, int i, int j) {
    if (j < l || r < i) return -1;
    if (i <= l && r <= j) {
        if (l == r) {
            return counts[node] > 0 ? -1 : l;
        } else {
            return counts[node];
        }
    }

    int mid = (l + r) / 2;
    int left = query(node * 2 + 1, l, mid, i, j);
    int right = query(node * 2 + 2, mid + 1, r, i, j);

    if (left == -1) return right;
    else if (right == -1) return left;
    else return min(left, right);
}

int main() {
    int N; // 1e5
    scanf("%d", &N);
    for (int n = 0; n < N; n++) {
        scanf("%d", arr + n);
    }

    for (int n = 0; n < N; n++) {
        // printf("\t\tupdate %d\n", arr[n]);
        update(0, 0, N, arr[n], 1);
    }

    bool valid = true;

    for (int n = 0; n < N; n++) {
        result[n] = counts[0];

        // printf("\t\tupdate %d\n", arr[n]);
        update(0, 0, N, result[n], 1);
        update(0, 0, N, arr[n], -1);

        if (arr[n] > n + 1) {
            valid = false;
            break;
        }
    }

    if (valid) {
        for (int n = 0; n < N; n++) printf("%d ", result[n]);
        printf("\n");
    } else {
        printf("-1\n");
    }

    return 0;
}
