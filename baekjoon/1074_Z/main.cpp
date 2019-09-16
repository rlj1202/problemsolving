#include <cstdio>

int N, R, C;

int recur(int r, int c, int n, int visit) {
	if (n == 0) return visit;

	int half_width = 1 << (n - 1);

	int i = (R - r) / half_width;
	int j = (C - c) / half_width;
	int offset = i * 2 + j;

	return recur(r + i * half_width, c + j * half_width, n - 1, visit * 4 + offset);
}

int main() {
	scanf("%d %d %d", &N, &R, &C);

	printf("%d\n", recur(0, 0, N, 0));

	return 0;
}
