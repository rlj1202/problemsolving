#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct Node { int min, max; };

Node minmax(const Node &a, const Node &b) {
	return {min(a.min, b.min), max(a.max, b.max)};
}

Node tree[400005];
int lazy[400005];

void init_tree(int p, int q, int node) {
	if (p == q) {
		tree[node] = {p, q};
		return;
	}

	int mid = (p + q) >> 1;
	init_tree(p, mid, node * 2);
	init_tree(mid + 1, q, node * 2 + 1);
	tree[node] = {p, q};
}

void update_lazy(int p, int q, int node) {
	if (lazy[node]) {
		tree[node].max += lazy[node];
		tree[node].min += lazy[node];
		if (p != q) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

// Increase pos of dvd which is smaller than given base_dvdpos.
// For example, if given base_dvdpos is 3 then pos 1, 2 will be 2, 3.
// And set pos to 1 which has same pos as base_dvdpos.
void update(int p, int q, int node, int base_dvdpos) {
	update_lazy(p, q, node);

	if (tree[node].min > base_dvdpos) return;
	if (tree[node].max < base_dvdpos) {
		lazy[node] += 1;
		update_lazy(p, q, node);
		return;
	}
	if (p == q) {
		if (tree[node].min == base_dvdpos) {
			tree[node] = {1, 1};
		}
		return;
	}

	int mid = (p + q) >> 1;
	update(p, mid, node * 2, base_dvdpos);
	update(mid + 1, q, node * 2 + 1, base_dvdpos);
	tree[node] = minmax(tree[node * 2], tree[node * 2 + 1]);
}

Node query(int p, int q, int node, int dvd) {
	update_lazy(p, q, node);

	if (p == q) return tree[node];

	int mid = (p + q) >> 1;
	if (dvd <= mid) return query(p, mid, node * 2, dvd);
	else return query(mid + 1, q, node * 2 + 1, dvd);
}

int main() {
	int T;
	scanf("%d", &T);

	while (T--) {
		int N, M;
		scanf("%d %d", &N, &M);

		init_tree(1, N, 1);
		memset(lazy, 0, sizeof(lazy));

		for (int m = 0; m < M; m++) {
			int dvd;
			scanf("%d", &dvd);

			int dvdpos = query(1, N, 1, dvd).min;
			printf("%d ", dvdpos - 1);

			update(1, N, 1, dvdpos);
		}
		printf("\n");
	}

	return 0;
}
