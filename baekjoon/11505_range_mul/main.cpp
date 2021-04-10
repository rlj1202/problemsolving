#include <cstdio>

using namespace std;

const long long MOD = 1e9 + 7;

long long tree[4000006];

long long update(int node, int p, int q, int i, long long value) {
    if (i < p || q < i) return tree[node];
    if (p == q) return tree[node] = value;

    int mid = (p + q) / 2;

    return tree[node] = (update(node * 2, p, mid, i, value) *
                        update(node * 2 + 1, mid + 1, q, i, value)) % MOD;
}

long long query(int node, int p, int q, int l, int r) {
    if (r < p || q < l) return 1;
    if (l <= p && q <= r) return tree[node];

    int mid = (p + q) / 2;

    return (query(node * 2, p, mid, l, r) *
           query(node * 2 + 1, mid + 1, q, l, r)) % MOD;
}

int main() {
    // 1e6, 1e4, 1e4
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    for (int n = 1; n <= N; n++) {
        // 1e6
        int value;
        scanf("%d", &value);

        update(1, 1, N, n, value);
    }

    // 1e8
    for (int i = 0; i < M + K; i++) {
        // 1 | 2, N, 1e6
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        if (a == 1) { // update
            update(1, 1, N, b, c);
        } else if (a == 2) { // query
            printf("%lld\n", query(1, 1, N, b, c));
        }
    }

    return 0;
}