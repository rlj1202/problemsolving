// point update, range query

#include <iostream>
#include <algorithm>

using namespace std;

int N, Q;

long long tree[400005];

void update(int p, int q, int node, int i, long long value) {
	if (i < p || q < i) return;

	if (p == q) {
		tree[node] = value;
	} else {
		int mid = (p + q) >> 1;
		update(p, mid, node * 2, i, value);
		update(mid + 1, q, node * 2 + 1, i, value);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
}

long long query(int p, int q, int node, int l, int r) {
	if (r < p || q < l) return 0;
	if (l <= p && q <= r) return tree[node];

	int mid = (p + q) >> 1;
	return query(p, mid, node * 2, l, r) + query(mid + 1, q, node * 2 + 1, l, r);
}

int main() {
	scanf("%d %d", &N, &Q);
	for (int n = 1; n <= N; n++) {
		int value;
		scanf("%d", &value);

		update(1, N, 1, n, value);
	}

	while (Q--) {
		int x, y, a, b;
		scanf("%d %d %d %d", &x, &y, &a, &b);

		if (x > y) {
			int tmp = x;
			x = y;
			y = tmp;
		}

		long long result = query(1, N, 1, x, y);
		printf("%lld\n", result);

		update(1, N, 1, a, b);
	}

	return 0;
}
