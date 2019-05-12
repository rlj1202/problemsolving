#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct Component { int x, w, f, c; };

bool operator< (const Component &a, const Component &b) {
	return a.x < b.x;
}

int L, N, B;
Component components[10004];

int dp[1003][1003]; // dp[end][cost] = fun rating

int main() {
	scanf("%d %d %d", &L, &N, &B);
	for (int n = 0; n < N; n++) {
		int x, w, f, c;
		scanf("%d %d %d %d", &x, &w, &f, &c);
		components[n] = {x, w, f, c};
	}
	sort(components, components + N);

	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;

	for (int n = 0; n < N; n++) {
		Component cur = components[n];

		int start = cur.x;
		int end = cur.x + cur.w;

		for (int cost = cur.c; cost <= B; cost++) {
			if (dp[start][cost - cur.c] == -1) continue;

			dp[end][cost] = max(dp[end][cost], dp[start][cost - cur.c] + cur.f);
		}
	}

	int result = -1;
	for (int c = 0; c <= B; c++) result = max(result, dp[L][c]);
	printf("%d\n", result);

	return 0;
}
