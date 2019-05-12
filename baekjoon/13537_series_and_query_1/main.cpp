#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> tree[400005];

void set_value(int p, int q, int node, int i, int value) {
	if (i < p || q < i) return;
	if (p == q) {
		tree[node].push_back(value);
		return;
	}

	int mid = (p + q) >> 1;
	set_value(p, mid, node * 2, i, value);
	set_value(mid + 1, q, node * 2 + 1, i, value);
}

void construct(int p, int q, int node) {
	if (p == q) return;

	int mid = (p + q) >> 1;
	construct(p, mid, node * 2);
	construct(mid + 1, q, node * 2 + 1);
	tree[node].resize(tree[node * 2].size() + tree[node * 2 + 1].size());
	merge(
			tree[node * 2].begin(), tree[node * 2].end(),
			tree[node * 2 + 1].begin(), tree[node * 2 + 1].end(),
			tree[node].begin()
		 );
}

int query(int p, int q, int node, int l, int r, int k) {
	if (r < p || q < l) return 0; 
	if (l <= p && q <= r) {
		int index = upper_bound(tree[node].begin(), tree[node].end(), k) - tree[node].begin();
		return tree[node].size() - index;
	}

	int mid = (p + q) >> 1;
	return query(p, mid, node * 2, l, r, k) + query(mid + 1, q, node * 2 + 1, l, r, k);
}

int main() {
	scanf("%d", &N);
	for (int n = 1; n <= N; n++) {
		int value;
		scanf("%d", &value);

		set_value(1, N, 1, n, value);
	}

	construct(1, N, 1);

	scanf("%d", &M);
	while (M--) {
		int l, r, k;
		scanf("%d %d %d", &l, &r, &k);

		int result = query(1, N, 1, l, r, k);
		printf("%d\n", result);
	}

	return 0;
}
