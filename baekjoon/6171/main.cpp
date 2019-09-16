#include <cstdio>
#include <algorithm>

using namespace std;

struct Area { int w, h; };

Area areas[50004];

int dp[50004];

int main() {
	int N;
	scanf("%d", &N);
	for (int n = 1; n <= N; n++) {
		int w, h;
		scanf("%d %d", &w, &h);
		areas[n] = {w, h};
	}

	sort(areas + 1, areas + N + 1, [](Area &a, Area &b) { return a.w < b.w; });

	for (int n = 1; n <= N; n++) {
		dp[n] = areas[n].w * areas[n].h + dp[n - 1];

		int maxheight = areas[n].h;

		for (int m = n; m >= 1; m--) {
			maxheight = max(maxheight, areas[m].h);

			int newcost = dp[m - 1] + areas[n].w * maxheight;

			dp[n] = min(dp[n], newcost);
		}
	}

	printf("%d\n", dp[N]);

	return 0;
}
