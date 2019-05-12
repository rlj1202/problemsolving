#include <iostream>
#include <algorithm>

using namespace std;

int N;
int coords[500005];

int compcoords[500005];
int compcoordslen;

int tree[2000006];

int compress(int coord) {
	return lower_bound(compcoords + 1, compcoords + 1 + compcoordslen, coord) - compcoords;
}

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
	return query(p, mid, node * 2, l, r) + query(mid + 1, q, node * 2 + 1, l, r);
}

int main() {
	scanf("%d", &N);
	for (int n = 1; n <= N; n++) {
		int value;
		scanf("%d", &value);
		coords[n] = value;
		compcoords[n] = value;
	}
	sort(compcoords + 1, compcoords + 1 + N);
	compcoordslen = unique(compcoords + 1, compcoords + 1 + N) - compcoords - 1;

	long long swaps = 0;

	for (int n = 1; n <= N; n++) {
		int coord = coords[n];
		int coordidx = compress(coord);

		swaps += query(1, compcoordslen, 1, coordidx + 1, compcoordslen + 1);
		update(1, compcoordslen, 1, coordidx, 1);
	}

	printf("%lld\n", swaps);

	return 0;
}
