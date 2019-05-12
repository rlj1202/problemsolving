#include <cstdio>
#include <algorithm>

using namespace std;

struct Node {
	int x;
	int low, high;
	bool opening;

	bool operator< (const Node &o) const {
		if (x == o.x) return opening < o.opening;
		return x < o.x;
	}
};

int N;

int tree[120005];
int sum[120005];

Node nodes[20004];

void update(int p, int q, int node, int l, int r, int delta) {
	if (r < p || q < l) return;
	if (l <= p && q <= r) {
		tree[node] += delta;

		sum[node] = 0;
		if (tree[node]) sum[node] = q - p;
		else if (q - p > 1) sum[node] = sum[node * 2 + 1] + sum[node * 2 + 2];
		
		return;
	}

	if (q - p > 1) {
		int mid = (p + q) >> 1;

		update(p, mid, node * 2 + 1, l, r, delta);
		update(mid, q, node * 2 + 2, l, r, delta);

		sum[node] = 0;
		if (tree[node]) sum[node] = q - p;
		else sum[node] = sum[node * 2 + 1] + sum[node * 2 + 2];
	}
}

int main() {
	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		int x1, y1, x2, y2; // bottom-left and top-right coordinates
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		nodes[n * 2] = {x1, y1, y2, true};
		nodes[n * 2 + 1] = {x2, y1, y2, false};
	}
	sort(nodes, nodes + N*2);

	int result = 0;
	int prev = nodes[0].x;

	for (int n = 0; n < N*2; n++) {
		Node cur = nodes[n];

		result += sum[0] * (cur.x - prev);

		if (cur.opening) update(0, 30000, 0, cur.low, cur.high, 1);
		else update(0, 30000, 0, cur.low, cur.high, -1);

		prev = cur.x;
	}

	printf("%d\n", result);

	return 0;
}
