#include <cstdio>
#include <algorithm>

using namespace std;

int coords[200005];

int main() {
	int N, C; // 2 <= N <= 200000, 2 <= C <= N
	scanf("%d %d", &N, &C);
	for (int n = 0; n < N; n++) scanf("%d", coords + n);
	sort(coords, coords + N);

	int l = 1;
	int r = 1e9;
	int mid;

	while (l < r) {
		mid = (l + r + 1) / 2;

		int installed = 0;
		int delta = 1e9 + 7;
		int prevcoord = coords[0];

		for (int n = 0; n < N; n++) {
			delta += coords[n] - prevcoord;
			prevcoord = coords[n];
			if (delta >= mid) {
				installed++;
				delta = 0;
			}
		}

		if (installed >= C) l = mid;
		else r = mid - 1;
	}

	printf("%d\n", (l + r) / 2);

	return 0;
}
