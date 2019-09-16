#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Warship {
	int x1, y1, x2, y2;
	int weight;
};

struct Query {
	int a, b;
};

Warship warships[100005];
Query queries[100005];

// for compress coordinates
int coordinates[500005];
int coordinateslen;

map<int, int> coordids;

bool destroyed[100005]; // destroyed[warship id]

vector<int> h_tree[2000006];
vector<int> v_tree[2000006];

void clear_tree(vector<int> *tree) {
	for (int i = 0; i < 2000006; i++) {
		tree[i].clear();
	}
}

// range update
void update(
		vector<int> *tree, int p, int q, int node,
		int warshipid, int l, int r) {
	if (r < p || q < l) return;
	if (l <= p && q <= r) {
		tree[node].push_back(warshipid);
		return;
	}

	if (p == q) return;

	int mid = (p + q) / 2;
	update(tree, p, mid, node * 2 + 1, warshipid, l, r);
	update(tree, mid + 1, q, node * 2 + 2, warshipid, l, r);
}

// point query
void query(
		vector<int> *tree, int p, int q, int node,
		int coordid,
		int &maxweight) {
	if (coordid < p || q < coordid) return;

	// destroy warships
	for (int warshipid : tree[node]) {
		if (destroyed[warshipid]) continue;
		destroyed[warshipid] = true;
		maxweight = max(maxweight, warships[warshipid].weight);
	}
	tree[node].clear();

	if (p == q) return;

	int mid = (p + q) / 2;
	if (coordid <= mid)
		query(tree, p, mid, node * 2 + 1, coordid, maxweight);
	if (mid < coordid)
		query(tree, mid + 1, q, node * 2 + 2, coordid, maxweight);
}

int main() {
	int T;
	scanf("%d", &T);

	while (T--) {
		// init
		coordinateslen = 0;

		clear_tree(h_tree);
		clear_tree(v_tree);

		// read input
		int N, K, I;
		scanf("%d %d %d", &N, &K, &I);
		for (int k = 0; k < K; k++) {
			int x1, y1, x2, y2, weight;
			scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &weight);
			if (x1 > x2) swap(x1, x2);
			if (y1 > y2) swap(y1, y2);
			warships[k] = {x1, y1, x2, y2, weight};

			destroyed[k] = false; // init

			coordinates[coordinateslen++] = x1;
			coordinates[coordinateslen++] = y1;
			coordinates[coordinateslen++] = x2;
			coordinates[coordinateslen++] = y2;
		}
		for (int i = 0; i < I; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			queries[i] = {a, b};

			coordinates[coordinateslen++] = a;
		}

		// compress coordinates
		sort(coordinates, coordinates + coordinateslen);
		coordinateslen = unique(coordinates, coordinates + coordinateslen) - coordinates;
		for (int i = 0; i < coordinateslen; i++) {
			int coord = coordinates[i];
			coordids[coord] = i + 1;
		}
		for (int k = 0; k < K; k++) {
			Warship &cur = warships[k];
			cur.x1 = coordids[cur.x1];
			cur.y1 = coordids[cur.y1];
			cur.x2 = coordids[cur.x2];
			cur.y2 = coordids[cur.y2];

			update(h_tree, 1, coordinateslen, 0, k, cur.x1, cur.x2);
			update(v_tree, 1, coordinateslen, 0, k, cur.y1, cur.y2);
		}

		//
		for (int i = 0; i < I; i++) {
			Query cur = queries[i];
			int maxweight = 0;

			if (cur.b == 0) { // horizontal
				query(v_tree, 1, coordinateslen, 0, coordids[cur.a], maxweight);
			} else { // vertical
				query(h_tree, 1, coordinateslen, 0, coordids[cur.a], maxweight);
			}

			// print result
			printf("%d\n", maxweight);
		}
	}

	return 0;
}
