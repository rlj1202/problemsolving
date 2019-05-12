#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

struct Point { int r, c; };

int N;
int W;
Point cases[1003];

int dp[1003][1003];
int back[1003][1003];

int dist(Point a, Point b) {
	return abs(a.r - b.r) + abs(a.c - b.c);
}

int f(int a, int b) {
	if (dp[a][b] != -1) return dp[a][b];

	if (max(a, b) == W + 2 - 1) return 0;

	int result = 0x3f3f3f3f;

	int offset = max(a, b);
	if (result > f(a, offset + 1) + dist(cases[b], cases[offset + 1])) {
		result = f(a, offset + 1) + dist(cases[b], cases[offset + 1]);
		back[a][b] = 2;
	}
	if (result > f(offset + 1, b) + dist(cases[a], cases[offset + 1])) {
		result = f(offset + 1, b) + dist(cases[a], cases[offset + 1]);
		back[a][b] = 1;
	}

	return dp[a][b] = result;
}

int main() {
	scanf("%d", &N);
	scanf("%d", &W);
	for (int w = 0; w < W; w++) {
		int r, c;
		scanf("%d %d", &r, &c);

		cases[w + 2] = {r, c};
	}
	cases[0] = {1, 1};
	cases[1] = {N, N};

	memset(dp, -1, sizeof(dp));
	printf("%d\n", f(0, 1));
	int a = 0;
	int b = 1;
	for (int i = 0; i < W; i++) {
		int cur = back[a][b];
		printf("%d\n", cur);

		int offset = max(a, b);
		if (cur == 1) {
			a = offset + 1;
		} else {
			b = offset + 1;
		}
	}

	return 0;
}
