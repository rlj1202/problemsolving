#include <cstdio>
#include <algorithm>

using namespace std;

struct Poster { int l, r; };

// inputs
int N;
Poster posters[10004];

// for compressing coordinates
int coords[20004];
int coordslen;

// for store poster ids
int tree[80004];
int lazy[80004];

// final poster ids
int result[20004];

int compress(int coord) {
	return lower_bound(coords + 1, coords + 1 + coordslen, coord) - coords;
}

void update_lazy(int p, int q, int node) {
	if (lazy[node]) {
		tree[node] = lazy[node];
		if (p != q) {
			lazy[node * 2] = lazy[node];
			lazy[node * 2 + 1] = lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(int p, int q, int node, int l, int r, int id) {
	update_lazy(p, q, node);

	if (r < p || q < l) return;
	if (l <= p && q <= r) {
		lazy[node] = id;
		update_lazy(p, q, node);
		return;
	}

	int mid = (p + q) >> 1;
	update(p, mid, node * 2, l, r, id);
	update(mid + 1, q, node * 2 + 1, l, r, id);
	tree[node] = tree[node * 2] == tree[node * 2 + 1] ? id : 0;
}

int query(int p, int q, int node, int i) {
	update_lazy(p, q, node);

	if (p == q) return tree[node];

	int mid = (p + q) >> 1;
	if (i <= mid) {
		return query(p, mid, node * 2, i);
	} else {
		return query(mid + 1, q, node * 2 + 1, i);
	}
}

int main() {
	scanf("%d", &N);
	for (int n = 1; n <= N; n++) {
		int l, r;
		scanf("%d %d", &l, &r);
		posters[n] = {l, r};
		coords[n * 2 - 1] = l;
		coords[n * 2] = r;
	}
	sort(coords + 1, coords + 1 + N*2);
	coordslen = unique(coords + 1, coords + 1 + N*2) - coords - 1;

	for (int n = 1; n <= N; n++) {
		Poster cur = posters[n];

		update(1, coordslen, 1, compress(cur.l), compress(cur.r), n);
	}

	for (int n = 1; n <= coordslen; n++) {
		result[n] = query(1, coordslen, 1, n);
	}
	sort(result + 1, result + 1 + coordslen);

	printf("%lld\n", unique(result + 1, result + 1 + coordslen) - result - 1);

	return 0;
}
