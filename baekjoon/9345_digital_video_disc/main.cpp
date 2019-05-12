#include <cstdio>
#include <algorithm>

using namespace std;

struct Node { int min, max; };

Node minmax(const Node &a, const Node &b) {
	return {min(a.min, b.min), max(a.max, b.max)};
}

int shelf[100005];
Node tree[400005];

void update(int p, int q, int node, int pos, int value) {
	if (pos < p || q < pos) return;
	if (p == q) {
		tree[node] = {value, value};
		return;
	}

	int mid = (p + q) >> 1;
	update(p, mid, node * 2 + 1, pos, value);
	update(mid + 1, q, node * 2 + 2, pos, value);
	tree[node] = minmax(tree[node * 2 + 1], tree[node * 2 + 2]);
}

Node query(int p, int q, int node, int l, int r) {
	if (r < p || q < l) return {0x3f3f3f3f, -1};
	if (l <= p && q <= r) return tree[node];

	int mid = (p + q) >> 1;
	return minmax(
			query(p, mid, node * 2 + 1, l, r),
			query(mid + 1, q, node * 2 + 2, l, r));
}

int main() {
	int T;
	scanf("%d", &T);

	while (T--) {
		int N, K;
		scanf("%d %d", &N, &K);

		for (int n = 0; n < N; n++) {
			shelf[n] = n;
			update(0, N - 1, 0, n, n);
		}

		for (int k = 0; k < K; k++) {
			int q, a, b;
			scanf("%d %d %d", &q, &a, &b);

			if (q == 0) { // swap
				update(0, N - 1, 0, a, shelf[b]);
				update(0, N - 1, 0, b, shelf[a]);

				int tmp = shelf[a];
				shelf[a] = shelf[b];
				shelf[b] = tmp;
			} else if (q == 1) { // query
				Node result = query(0, N - 1, 0, a, b);
				if (result.min == a && result.max == b) {
					printf("YES\n");
				} else {
					printf("NO\n");
				}
			}
		}
	}

	return 0;
}
