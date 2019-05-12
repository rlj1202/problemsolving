#include <cstdio>
#include <cstring>

using namespace std;

int dvdpos[100005]; // dvdpos[dvdid] = position

int tree[800005]; // sum tree

void update(int p, int q, int node, int i, int value) {
	if (i < p || q < i) return;
	if (p == q) {
		tree[node] = value;
		return;
	}

	int mid = (p + q) >> 1;
	update(p, mid, node * 2, i, value);
	update(mid + 1, q, node * 2 + 1, i, value);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int p, int q, int node, int l, int r) {
	if (r < p || q < l) return 0;
	if (l <= p && q <= r) return tree[node];

	int mid = (p + q) >> 1;
	return query(p, mid, node * 2, l, r) + query(mid + 1, q, node * 2 + 1, l, r);
}

int main() {
	int T;
	scanf("%d", &T);

	while (T--) {
		// read input
		int N, M;
		scanf("%d %d", &N, &M);

		// initiate dvd positions
		memset(tree, 0, sizeof(tree));
		for (int n = 1; n <= N; n++) {
			dvdpos[n] = N - n + 1;
			update(1, 200000, 1, dvdpos[n], 1);
		}

		int lastpos = N;

		for (int m = 0; m < M; m++) {
			int dvdid;
			scanf("%d", &dvdid);

			int result = query(1, 200000, 1, dvdpos[dvdid], lastpos) - 1;
			// print result
			printf("%d ", result);

			update(1, 200000, 1, dvdpos[dvdid], 0);
			if (result) lastpos++;
			update(1, 200000, 1, lastpos, 1);
			dvdpos[dvdid] = lastpos;
		}
		printf("\n");
	}
	
	return 0;
}
