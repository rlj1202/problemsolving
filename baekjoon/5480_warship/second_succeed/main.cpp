#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct Warship { int x1, y1, x2, y2, weight; bool destroyed; };
struct Query { int a, b; };

Warship warships[100005];
Query queries[100005];

int coordinates[100005];
int coordinateslen;

vector<int> h_tree[400005];
vector<int> v_tree[400005];

// range update
void update(vector<int> *tree, int p, int q, int node, int l, int r, int warshipid) {
	if (l > r) return;
	if (q < l || r < p) return;

	if (l <= p && q <= r) {
		tree[node].push_back(warshipid);
		return;
	}

	if (p == q) return;

	int mid = (p + q) / 2;
	update(tree, p, mid, node * 2 + 1, l, r, warshipid);
	update(tree, mid + 1, q, node * 2 + 2, l, r, warshipid);
}

void query(vector<int> *tree, int p, int q, int node, int i, int *maxweight) {
	if (q < i || i < p) return;

	for (int warshipid : tree[node]) {
		Warship &cur = warships[warshipid];
		if (cur.destroyed) continue;

		cur.destroyed = true;
		*maxweight = max(*maxweight, cur.weight);
	}
	tree[node].clear();

	if (p == q) return;
	
	int mid = (p + q) / 2;
	if (i <= mid) query(tree, p, mid, node * 2 + 1, i, maxweight);
	else query(tree, mid + 1, q, node * 2 + 2, i, maxweight);
}

int main() {
	int T;
	scanf("%d", &T);

	while (T--) {
		// read input
		int N, K, I;
		scanf("%d %d %d", &N, &K, &I);
		for (int k = 0; k < K; k++) {
			int x1, y1, x2, y2, weight;
			scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &weight);
			warships[k] = {x1, y1, x2, y2, weight, false};
		}
		for (int i = 0; i < I; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			queries[i] = {a, b};
		}

		// compress coordinates in aspect of queries
		// O(I log I)
		for (int i = 0; i < I; i++) coordinates[i] = queries[i].a;
		sort(coordinates, coordinates + I);
		coordinateslen = unique(coordinates, coordinates + I) - coordinates;

		// register warships to tree
		// O(K log I)
		for (int i = 0; i < 400005; i++) {
			h_tree[i].clear();
			v_tree[i].clear();
		}
		for (int k = 0; k < K; k++) {
			Warship &cur = warships[k];
			if (cur.x1 > cur.x2) swap(cur.x1, cur.x2);
			if (cur.y1 > cur.y2) swap(cur.y1, cur.y2);

			int hl = lower_bound(coordinates, coordinates + coordinateslen, cur.x1) - coordinates;
			int hr = upper_bound(coordinates, coordinates + coordinateslen, cur.x2) - coordinates;
			update(h_tree, 0, coordinateslen - 1, 0, hl, hr - 1, k);

			int vl = lower_bound(coordinates, coordinates + coordinateslen, cur.y1) - coordinates;
			int vr = upper_bound(coordinates, coordinates + coordinateslen, cur.y2) - coordinates;
			update(v_tree, 0, coordinateslen - 1, 0, vl, vr - 1, k);
		}

		// digest queries
		// O(I log I K log K) (?)
		for (int i = 0; i < I; i++) {
			Query &cur = queries[i];

			int maxweight = 0;
			int index =
				lower_bound(coordinates, coordinates + coordinateslen, cur.a) - coordinates;

			if (cur.b == 0) { // horizontal
				query(v_tree, 0, coordinateslen - 1, 0, index, &maxweight);
			} else { // vertical
				query(h_tree, 0, coordinateslen - 1, 0, index, &maxweight);
			}

			printf("%d\n", maxweight);
		}
	}

	return 0;
}
