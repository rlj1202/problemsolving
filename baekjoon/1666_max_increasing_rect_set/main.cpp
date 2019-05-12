#include <cstdio>
#include <algorithm>

using namespace std;

const int COORD_MAX = 1e5;

struct Line {
	int x, low, high;
	bool open;
	int rectid;

	bool operator< (const Line &o) const {
		if (x == o.x) return !open < !o.open; // open first, close last
		return x < o.x;
	}
};

Line lines[200005];
int lineslen;

int maxrects[100005];

int tree[400005];

// point update
void update(int i, int value, int p = 0, int q = COORD_MAX, int node = 0) {
	if (i < p || q < i) return;
	if (p == q) {
		tree[node] = max(tree[node], value);
		return;
	}

	int mid = (p + q) >> 1;
	update(i, value, p, mid, node * 2 + 1);
	update(i, value, mid + 1, q, node * 2 + 2);
	tree[node] = max(tree[node * 2 + 1], tree[node * 2 + 2]);
}

// range query
int query(int l, int r, int p = 0, int q = COORD_MAX, int node = 0) {
	if (r < l) return 0;
	if (r < p || q < l) return 0;
	if (l <= p && q <= r) return tree[node];

	int mid = (p + q) >> 1;
	return max(query(l, r, p, mid, node * 2 + 1), query(l, r, mid + 1, q, node * 2 + 2));
}

int main() {
	int N;
	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		lines[lineslen++] = {x1, y1, y2, true, n};
		lines[lineslen++] = {x2, y1, y2, false, n};
	}
	sort(lines, lines + lineslen);

	for (int i = 0; i < lineslen; i++) {
		Line line = lines[i];

		if (line.open) {
			maxrects[line.rectid] = query(0, line.low - 1) + 1;
		} else {
			update(line.high, maxrects[line.rectid]);
		}
	}

	int result = 0;
	for (int n = 0; n < N; n++) result = max(result, maxrects[n]);

	printf("%d\n", result);

	return 0;
}
