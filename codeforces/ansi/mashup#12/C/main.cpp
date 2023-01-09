#include <cstdio>
#include <algorithm>

using namespace std;

int arr[200005];
long long accum[200005];

int tree[200005 * 4];

void update(int node, int p, int q, int i, int delta) {
    if (i < p || q < i) return;
    if (p == q) {
        tree[node] += delta;
        return;
    }

    int left = node * 2;
    int right = left + 1;
    int mid = (p + q) / 2;
    update(left, p, mid, i, delta);
    update(right, mid + 1, q, i, delta);
    tree[node] = tree[left] + tree[right];
}

int get(int node, int p, int q, int l, int r) {
    if (r < p || q < l) {
        return 0;
    }
    if (l <= p && q <= r) {
        return tree[node];
    }

    int left = node * 2;
    int right = left + 1;
    int mid = (p + q) / 2;

    return get(left, p, mid, l, r) + get(right, mid + 1, q, l, r);
}

int main() {
    int N;
    long long T;
    scanf("%d %lld", &N, &T);
    for (int n = 1; n <= N; n++) {
        scanf("%d", arr + n);
    }

    for (int n = 1; n <= N; n++) {
        accum[n] = accum[n - 1] + (long long) arr[n];
    }
    sort(accum, accum + N + 1);

    int accumLen = unique(accum, accum + N + 1) - accum;

    int zero_pos = lower_bound(accum, accum + accumLen, 0LL) - accum;
    update(1, 0, N + 1, zero_pos, 1);

    long long answer = 0;

    long long cur = 0;
    for (int n = 1; n <= N; n++) {
        cur += (long long) arr[n];

        int pos = upper_bound(accum, accum + accumLen, cur - T) - accum;
        answer += get(1, 0, N + 1, pos, N);

        int k = lower_bound(accum, accum + accumLen, cur) - accum;
        update(1, 0, N + 1, k, 1);
    }

    printf("%lld\n", answer);

    return 0;
}
