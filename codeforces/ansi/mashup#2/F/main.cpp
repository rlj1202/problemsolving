#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int delta[200005];

vector<int> tree[200005 * 4];

void add(int node, int i, int j, int index, int value) {
    if (index < i || j < index) return;

    if (i == j) {
        tree[node].push_back(value);
        return;
    }

    int mid = (i + j) / 2;
    add(node * 2 + 1, i, mid, index, value);
    add(node * 2 + 2, mid + 1, j, index, value);
}

void build(int node, int i, int j) {
    if (i == j) return;

    int mid = (i + j) / 2;

    build(node * 2 + 1, i, mid);
    build(node * 2 + 2, mid + 1, j);

    tree[node].resize(tree[node * 2 + 1].size() + tree[node * 2 + 2].size());

    merge(
        tree[node * 2 + 1].begin(), tree[node * 2 + 1].end(),
        tree[node * 2 + 2].begin(), tree[node * 2 + 2].end(),
        tree[node].begin());
}

int query(int node, int i, int j, int l, int r, int value) {
    if (r < i || j < l) return 0;

    if (l <= i && j <= r) {
        int result = tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), value);
        return result;
    }

    int mid = (i + j) / 2;
    int left = query(node * 2 + 1, i, mid, l, r, value);
    int right = query(node * 2 + 2, mid + 1, j, l, r, value);

    return left + right;
}

int main() {
    int N; // 2e5
    scanf("%d", &N);
    for (int n = 0; n < N; n++) {
        scanf("%d", delta + n);
    }
    for (int n = 0; n < N; n++) {
        int value;
        scanf("%d", &value);
        delta[n] -= value;
    }

    for (int n = 0; n < N; n++) {
        add(0, 0, N - 1, n, delta[n]);
    }

    build(0, 0, N - 1);

    long long result = 0;

    for (int i = 0; i < N; i++) {
        result += query(0, 0, N - 1, i + 1, N - 1, -delta[i]);
    }

    printf("%lld\n", result);

    return 0;
}
