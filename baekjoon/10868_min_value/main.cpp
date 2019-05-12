#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int tree[400005];

void update(int l, int r, int node, int index, int data) {
	if (index < l || r < index) return;

	if (l == r) {
		tree[node] = data;
	} else {
		int mid = (l + r) / 2;

		update(l, mid, node * 2, index, data);
		update(mid+1, r, node * 2 + 1, index, data);

		tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
	}

	return;
}

int find(int l, int r, int node, int q, int p) {
	if (p < l || r < q) return 2000000009;
	if (q <= l && r <= p) return tree[node];

	int mid = (l + r) / 2;

	return min(find(l, mid, node * 2, q, p), find(mid+1, r, node * 2 + 1, q, p));
}

int main() {
	scanf("%d %d", &N, &M);
	
	for (int n = 1; n <= N; n++) {
		int value;
		scanf("%d", &value);
		update(1, N, 1, n, value);
	}

	while (M--) {
		int a, b;
		scanf("%d %d", &a, &b);

		int result = find(1, N, 1, a, b);
		printf("%d\n", result);
	}

	return 0;
}
