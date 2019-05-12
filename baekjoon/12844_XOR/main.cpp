#include <cstdio>

int N, M;

int tree[2000006];
int lazy[2000006];

void update_lazy(int p, int q, int node) {
	if (lazy[node]) {
		if ((q - p + 1) % 2 == 1) tree[node] ^= lazy[node];

		if (p != q) {
			lazy[node * 2] ^= lazy[node];
			lazy[node * 2 + 1] ^= lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(int p, int q, int node, int l, int r, int value) {
	update_lazy(p, q, node);

	if (r < p || q < l) return;
	if (l <= p && q <= r) {
		lazy[node] ^= value;
		update_lazy(p, q, node);
		return;
	}

	int mid = (p + q) >> 1;
	update(p, mid, node * 2, l, r, value);
	update(mid + 1, q, node * 2 + 1, l, r, value);
	tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
}

int query(int p, int q, int node, int l, int r) {
	update_lazy(p, q, node);

	if (r < p || q < l) return 0;
	if (l <= p && q <= r) return tree[node];

	int mid = (p + q) >> 1;
	return query(p, mid, node * 2, l, r) ^ query(mid + 1, q, node * 2 + 1, l, r);
}

int main() {
	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		int value;
		scanf("%d", &value);

		update(0, N - 1, 1, n, n, value);
	}

	scanf("%d", &M);

	while (M--) {
		int cmd;
		scanf("%d", &cmd);

		if (cmd == 1) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);

			if (a > b) {
				int tmp = a;
				a = b;
				b = tmp;
			}

			update(0, N - 1, 1, a, b, c);
		} else if (cmd == 2) {
			int a, b;
			scanf("%d %d", &a, &b);

			if (a > b) {
				int tmp = a;
				a = b;
				b = tmp;
			}

			int result = query(0, N - 1, 1, a, b);
			printf("%d\n", result);
		}
	}

	return 0;
}
