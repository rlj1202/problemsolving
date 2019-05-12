#include <iostream>

int N;
int tree[4000006];

void update(int p, int q, int node, int taste, int amount) {
	if (taste < p || q < taste) return;
	if (p == q) {
		tree[node] += amount;
		return;
	}

	int mid = (p + q) >> 1;
	update(p, mid, node * 2, taste, amount);
	update(mid + 1, q, node * 2 + 1, taste, amount);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int p, int q, int node, int prior) {
	if (p == q) {
		tree[node]--;
		return p;
	}

	int result;

	int mid = (p + q) >> 1;
	if (prior <= tree[node * 2]) {
		result = query(p, mid, node * 2, prior);
	} else {
		result = query(mid + 1, q, node * 2 + 1, prior - tree[node * 2]);
	}
	tree[node] = tree[node * 2] + tree[node * 2 + 1];

	return result;
}

int main() {
	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		int cmd;
		scanf("%d", &cmd);

		if (cmd == 1) { // pop
			int prior;
			scanf("%d", &prior);

			int taste = query(1, 1000000, 1, prior);
			printf("%d\n", taste);
		} else if (cmd == 2) { // update
			int taste, amount;
			scanf("%d %d", &taste, &amount);

			update(1, 1000000, 1, taste, amount);
		}
	}

	return 0;
}
