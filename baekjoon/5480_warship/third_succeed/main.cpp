#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>

using namespace std;

struct Warship {
	int x1, y1, x2, y2, weight;
	bool operator> (const Warship &o) const {
		return weight > o.weight;
	}
};
struct Query { int coord, dir; };

const int INF = 0x3f3f3f3f;

Warship warships[100005];
Query queries[100005];

int coordinates[100005];
int coordinateslen;

int h_tree[400005];
int v_tree[400005];

int result[100005];

// point update
void update(int *tree, int p, int q, int node, int i, int value) {
	if (i < p || q < i) return;
	if (p == q) {
		tree[node] = min(tree[node], value);
		return;
	}

	int mid = (p + q) / 2;
	update(tree, p, mid, node * 2 + 1, i, value);
	update(tree, mid + 1, q, node * 2 + 2, i, value);
	tree[node] = min(
			tree[node * 2 + 1],
			tree[node * 2 + 2]);
}

// range query
int query(int *tree, int p, int q, int node, int l, int r) {
	if (l > r) return INF;
	if (r < p || q < l) return INF;
	if (l <= p && q <= r) return tree[node];

	int mid = (p + q) / 2;
	return min(
			query(tree, p, mid, node * 2 + 1, l, r),
			query(tree, mid + 1, q, node * 2 + 2, l, r));
}

int main() {
	int T;
	scanf("%d", &T);

	while (T--) {
		// read input
		// O(K + I)
		int N, K, I;
		scanf("%d %d %d", &N, &K, &I);
		for (int k = 0; k < K; k++) {
			int x1, y1, x2, y2, weight;
			scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &weight);
			warships[k] = {x1, y1, x2, y2, weight};
		}
		for (int i = 0; i < I; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			queries[i] = {a, b};
		}

		// sort warships by weight in decreasing order
		// O(K log K)
		sort(warships, warships + K, greater<Warship>());

		// compress coordinates
		// O(I log I)
		for (int i = 0; i < I; i++) coordinates[i] = queries[i].coord;
		sort(coordinates, coordinates + I);
		coordinateslen = unique(coordinates, coordinates + I) - coordinates;

		// register query id to tree
		// O(I log I)
		memset(h_tree, INF, sizeof(h_tree));
		memset(v_tree, INF, sizeof(v_tree));
		for (int i = 0; i < I; i++) {
			Query cur = queries[i];
			int index =
				lower_bound(coordinates, coordinates + coordinateslen, cur.coord) - coordinates;

			if (cur.dir == 0) // horizontal
				update(h_tree, 0, coordinateslen - 1, 0, index, i);
			else // vertical
				update(v_tree, 0, coordinateslen - 1, 0, index, i);
		}

		// find first shot and update max weight of that laser shot
		// O(K log I)
		memset(result, 0, sizeof(result));
		for (int k = 0; k < K; k++) {
			Warship cur = warships[k];
			if (cur.x1 > cur.x2) swap(cur.x1, cur.x2);
			if (cur.y1 > cur.y2) swap(cur.y1, cur.y2);

			int queryid = INF;
			int tmp;

			int hl = lower_bound(coordinates, coordinates + coordinateslen, cur.x1) - coordinates;
			int hr = upper_bound(coordinates, coordinates + coordinateslen, cur.x2) - coordinates;
			tmp = query(v_tree, 0, coordinateslen - 1, 0, hl, hr - 1);
			queryid = min(queryid, tmp);

			int vl = lower_bound(coordinates, coordinates + coordinateslen, cur.y1) - coordinates;
			int vr = upper_bound(coordinates, coordinates + coordinateslen, cur.y2) - coordinates;
			tmp = query(h_tree, 0, coordinateslen - 1, 0, vl, vr - 1);
			queryid = min(queryid, tmp);

			if (queryid != INF)
				result[queryid] = max(result[queryid], cur.weight);
		}

		// print result
		// O(I)
		for (int i = 0; i < I; i++)
			printf("%d\n", result[i]);

		// total time complexity
		// O((I + K) log I)
	}

	return 0;
}
