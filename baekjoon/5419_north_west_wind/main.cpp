#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

struct Point {
	int x, y;

	bool operator< (const Point &o) const {
		if (y == o.y) return x > o.x;
		return y < o.y;
	}
};

int T, N;
int xcoords[75004];
int xcoordslen;
Point islands[75004];

int tree[300005];

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

int compress(int xcoord) {
	return lower_bound(xcoords + 1, xcoords + 1 + xcoordslen, xcoord) - xcoords;
}

int main() {
	scanf("%d", &T);

	while (T--) {
		// read input
		scanf("%d", &N);
		for (int n = 1; n <= N; n++) {
			int x, y;
			scanf("%d %d", &x, &y);
			xcoords[n] = x;
			islands[n] = {x, y};
		}
		
		// compress x coordinates
		sort(xcoords + 1, xcoords + 1 + N);
		xcoordslen = unique(xcoords + 1, xcoords + 1 + N) - xcoords - 1;

		// sort islands
		sort(islands + 1, islands + 1 + N);

		// calculate
		memset(tree, 0, sizeof(tree));

		long long result = 0;

		for (int n = 1; n <= N; n++) {
			Point cur = islands[n];
			int xidx = compress(cur.x);

			result += query(1, xcoordslen, 1, xidx, xcoordslen);
			update(1, xcoordslen, 1, xidx, 1);
		}

		// print result
		printf("%lld\n", result);
	}

	return 0;
}
