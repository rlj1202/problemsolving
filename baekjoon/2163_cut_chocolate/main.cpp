#include <cstdio>
#include <algorithm>

using namespace std;

int cut[302][302];

int get_mincut(int r, int c) {
	if (cut[r][c]) return cut[r][c];
	if (r == 1 && c == 1) return 0;

	int mincut = 0x3f3f3f3f;
	for (int h = 1; h < r; h++) {
		mincut = min(mincut, get_mincut(h, c) + get_mincut(r - h, c) + 1);
	}
	for (int v = 1; v < c; v++) {
		mincut = min(mincut, get_mincut(r, v) + get_mincut(r, c - v) + 1);
	}

	return cut[r][c] = mincut;
}

int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	printf("%d\n", get_mincut(N, M));

	return 0;
}
