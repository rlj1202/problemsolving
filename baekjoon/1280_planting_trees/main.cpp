#include <cstdio>

const int MOD = 1e9+7;

struct Node { long long sum; int count; };

Node operator+ (const Node &a, const Node &b) {
	return {a.sum + b.sum, a.count + b.count};
}

Node tree[800005];

void update(int p, int q, int node, int i, long long value) {
	if (i < p || q < i) return;
	if (p == q) {
		tree[node] = tree[node] + Node{value, 1};
		return;
	}

	int mid = (p + q) >> 1;
	update(p, mid, node * 2 + 1, i, value);
	update(mid + 1, q, node * 2 + 2, i, value);
	tree[node] = tree[node * 2 + 1] + tree[node * 2 + 2];
}

Node query(int p, int q, int node, int l, int r) {
	if (l > r) return {0, 0};
	if (r < p || q < l) return {0, 0};
	if (l <= p && q <= r) return tree[node];

	int mid = (p + q) >> 1;
	return query(p, mid, node * 2 + 1, l, r) + query(mid + 1, q, node * 2 + 2, l, r);
}

int main() {
	int N;
	scanf("%d", &N);

	long long result = 1;

	int pos;
	scanf("%d", &pos);
	update(0, 200000, 0, pos, pos);

	for (int n = 1; n < N; n++) {
		int pos;
		scanf("%d", &pos);

		Node left = query(0, 200000, 0, 0, pos - 1);
		Node right = query(0, 200000, 0, pos + 1, 200000);

		long long cost = 0;

		cost += (long long) pos * left.count - left.sum;
		cost %= MOD;

		cost += right.sum - (long long) pos * right.count;
		cost %= MOD;

		update(0, 200000, 0, pos, pos);

		result *= cost;
		result %= MOD;
	}

	printf("%lld\n", result);

	return 0;
}
