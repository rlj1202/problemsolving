#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, I, H, R;
vector<int> adj[10004];

int heights[40004];
int lazies[40004];

void update_lazy(
		int p, int q, int node,
		int l, int r) {
	if (lazies[node]) {
		heights[node] += (q - p + 1) * lazies[node];

		if (p != q) {
			lazies[node * 2] += lazies[node];
			lazies[node * 2 + 1] += lazies[node];
		}
		lazies[node] = 0;
	}
}

void update(
		int p, int q, int node,
		int l, int r, int delta) {
	update_lazy(p, q, node, l, r);

	if (l > r) return;
	if (l > q || r < p) return;

	if (l <= p && q <= r) {
		heights[node] += (q - p + 1) * delta;

		if (p != q) {
			lazies[node * 2] += delta;
			lazies[node * 2 + 1] += delta;
		}

		return;
	}

	int mid = (p + q) / 2;
	update(p, mid, node * 2, l, r, delta);
	update(mid + 1, q, node * 2 + 1, l, r, delta);
	heights[node] = heights[node * 2] + heights[node * 2 + 1];
}

int query(int p, int q, int node, int n) {
	update_lazy(p, q, node, n, n);

	if (n < p || n > q) return 0;

	if (n <= p && q <= n) {
		return heights[node];
	}

	int mid = (p + q) / 2;
	int sum = 0;
	sum += query(p, mid, node * 2, n);
	sum += query(mid + 1, q, node * 2 + 1, n);

	return sum;
}

int main() {
	scanf("%d %d %d %d", &N, &I, &H, &R);
	for (int r = 0; r < R; r++) {
		int a, b;
		scanf("%d %d", &a, &b);

		if (a > b) {
			int tmp = a;
			a = b;
			b = tmp;
		}

		adj[a].push_back(b);
	}

	for (int n = 1; n <= N; n++) {
		sort(adj[n].begin(), adj[n].end());

		int prev = 0;
		for (int next : adj[n]) {
			if (prev == next) continue;

			update(1, N, 1, n + 1, next - 1, -1);
			prev = next;
		}
	}

	for (int n = 1; n <= N; n++)
		printf("%d\n", H + query(1, N, 1, n));

	return 0;
}
