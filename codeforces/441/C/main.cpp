#include <cstdio>

struct Point { int r, c; };

int N, M, K;
Point cur;

void next() {
	if (cur.r % 2 == 1) {
		if (cur.c == M) {
			cur.r++;
		} else {
			cur.c++;
		}
	} else {
		if (cur.c == 1) {
			cur.r++;
		} else {
			cur.c--;
		}
	}
}

int main() {
	scanf("%d %d %d", &N, &M, &K);

	cur = {1, 1};

	int remains = N * M;

	for (int k = 0; k < K; k++) {
		int r = k != K - 1 ? 2 : remains;
		remains -= r;
		printf("%d ", r);

		for (int i = 0; i < r; i++) {
			printf("%d %d ", cur.r, cur.c);
			next();
		}
		printf("\n");
	}

	return 0;
}
