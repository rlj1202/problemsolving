#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;

int N;
int students[3][500005];
int grades[500005][3];

int tree[2000006];

// point update
void update(int i, int value, int p = 0, int q = N - 1, int node = 0) {
	if (i < p || q < i) return;
	if (p == q) {
		tree[node] = value;
		return;
	}

	int mid = (p + q) >> 1;
	update(i, value, p, mid, node * 2 + 1);
	update(i, value, mid + 1, q, node * 2 + 2);
	tree[node] = min(tree[node * 2 + 1], tree[node * 2 + 2]);
}

// range query
int query(int l, int r, int p = 0, int q = N - 1, int node = 0) {
	if (r < p || q < l) return INF;
	if (l <= p && q <= r) return tree[node];
	
	int mid = (p + q) >> 1;
	return min(query(l, r, p, mid, node * 2 + 1), query(l, r, mid + 1, q, node * 2 + 2));
}

int main() {
	// init
	memset(tree, INF, sizeof(tree));

	// read input
	scanf("%d", &N);
	for (int i = 0; i < 3; i++) {
		for (int n = 0; n < N; n++) {
			int student;
			scanf("%d", &student);

			students[i][n] = student;
			grades[student][i] = n;
		}
	}

	//
	int result = 0;

	for (int n = 0; n < N; n++) {
		int student = students[0][n];

		int minThird = query(0, grades[student][1]);

		if (minThird > grades[student][2])
			result++;

		update(grades[student][1], grades[student][2]);
	}

	// print result
	printf("%d\n", result);

	return 0;
}
