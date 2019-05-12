// 미완성 코드
#include <cstdio>
#include <algorithm>

using namespace std;

struct Poster { int l, r; };

Poster posters[100005];

int coords[200005];
int coordslen;

int tree[800005];

void update(int p, int q, int node, int l, int r, int value) {
	if (r < p || q < l) return;
	if (l <= p && q <= r) {
		tree[node] = value;
	}

	int mid = (p + q) >> 1;
	update(p, mid, node * 2 + 1, l, r, value);
	update(mid + 1, q, node * 2 + 2, l, r, value);
}

int query(int p, int q, int node, int i) {
	if (i < p || q < i) return 0;
	int mid = (p + q) >> 1;
	return max(query(p, mid, node * 2 + 1, i), query(mid + 1, q, node * 2 + 2, i));
}

int main() {
	int N;
	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		int l, r;
		scanf("%d %d", &l, &r);
		posters[n] = {l, r};
		coords[n * 2] = l;
		coords[n * 2 + 1] = r;
	}
	sort(coords, coords + N * 2);
	coordslen = unique(coords, coords + N * 2) - coords;

	for (int n = 0; n < N; n++) {
		Poster cur = posters[n];

		update(0, 200000, 0, cur.l, cur.r, n);
	}

	return 0;
}
