#include <cstdio>

int N, K;
int tree[400005];

void update(int p, int q, int node, int i, int value) {
	if (i < p || q < i) return;

	if (p == q) {
		if (value > 0) value = 1;
		else if (value < 0) value = -1;
		tree[node] = value;
		return;
	}

	int mid = (p + q) >> 1;
	update(p, mid, node * 2, i, value);
	update(mid + 1, q, node * 2 + 1, i, value);
	tree[node] = tree[node * 2] * tree[node * 2 + 1];
}

int query(int p, int q, int node, int l, int r) {
	if (r < p || q < l) return 1;
	if (l <= p && q <= r) return tree[node];

	int mid = (p + q) >> 1;
	return query(p, mid, node * 2, l, r) * query(mid + 1, q, node * 2 + 1, l, r);
}

int main() {
	while (scanf("%d %d", &N, &K) != EOF) {
		for (int n = 1; n <= N; n++) {
			int value;
			scanf("%d", &value);

			update(1, N, 1, n, value);
		}
		for (int k = 0; k < K; k++) {
			char cmd;
			scanf(" %c", &cmd);

			if (cmd == 'C') {
				int i, v;
				scanf("%d %d", &i, &v);

				update(1, N, 1, i, v);
			} else if (cmd == 'P') {
				int i, j;
				scanf("%d %d", &i, &j);

				int result = query(1, N, 1, i, j);
				char output = '0';
				if (result > 0) output = '+';
				else if (result < 0) output = '-';

				printf("%c", output);
			}
		}
		printf("\n");
	}

	return 0;
}
