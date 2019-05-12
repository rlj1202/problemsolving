#include <iostream>

struct Node { long long value, lazy; };

int N, M, K;
Node tree[4000006];

long long update(int p, int q, int node, int l, int r, long long delta) {
	if (tree[node].lazy) {
		tree[node].value += (q - p + 1) * tree[node].lazy;

		if (p != q) {
			tree[node * 2].lazy += tree[node].lazy;
			tree[node * 2 + 1].lazy += tree[node].lazy;
		}

		tree[node].lazy = 0;
	}

	if (q < l || r < p) return tree[node].value;

	if (p == q) return tree[node].value += delta;

	if (l <= p && q <= r) {
		tree[node * 2].lazy += delta;
		tree[node * 2 + 1].lazy += delta;

		return tree[node].value += (q - p + 1) * delta;
	}

	long long sum = 0;
	
	int m = (p + q) / 2;
	sum += update(p, m, node * 2, l, r, delta);
	sum += update(m + 1, q, node * 2 + 1, l, r, delta);

	return tree[node].value = sum;
}

long long query(int p, int q, int node, int l, int r) {
	if (tree[node].lazy) {
		tree[node].value += (q - p + 1) * tree[node].lazy;

		if (p != q) {
			tree[node * 2].lazy += tree[node].lazy;
			tree[node * 2 + 1].lazy += tree[node].lazy;
		}

		tree[node].lazy = 0;
	}

	if (q < l || r < p) return 0;

	if (l <= p && q <= r) {
		return tree[node].value;
	}

	long long sum = 0;

	int m = (p + q) / 2;
	sum += query(p, m, node * 2, l, r);
	sum += query(m + 1, q, node * 2 + 1, l, r);
	
	return sum;
}

int main() {
	scanf("%d %d %d", &N, &M, &K);

	for (int n = 1; n <= N; n++) {
		long long value;
		scanf("%lld", &value);

		update(1, N, 1, n, n, value);
	}

	for (int i = 0; i < M + K; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		if (a == 1) { // add
			long long d;
			scanf("%lld", &d);

			update(1, N, 1, b, c, d);
		} else { // print
			long long result = query(1, N, 1, b, c);
			printf("%lld\n", result);
		}
	}

	return 0;
}
