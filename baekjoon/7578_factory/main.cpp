#include <cstdio>

int N;
int indices[1000006];
int tree[2000006];

long long result;

void update(int p, int q, int node, int i, int delta) {
	if (i < p || q < i) return;
	if (p == q) {
		tree[node] += delta;
		return;
	}

	int mid = (p + q) >> 1;
	update(p, mid, node * 2, i, delta);
	update(mid + 1, q, node * 2 + 1, i, delta);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int p, int q, int node, int l, int r) {
	if (r < p || q < l) return 0;
	if (l <= p && q <= r) return tree[node];

	int mid = (p + q) >> 1;
	return query(p, mid, node * 2, l, r) + query(mid + 1, q, node * 2 + 1, l , r);
}

int main() {
	scanf("%d", &N);
	for (int n = 1; n <= N; n++) {
		int machine;
		scanf("%d", &machine);
		indices[machine] = n;
	}
	for (int n = 1; n <= N; n++) {
		int machine;
		scanf("%d", &machine);

		int index = indices[machine];
		result += query(1, N, 1, index, N);

		update(1, N, 1, index, 1);
	}

	printf("%lld\n", result);

	return 0;
}
