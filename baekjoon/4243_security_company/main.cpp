#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

struct Node { long long cost, elapsed; };

int T;

int N;
int S;
int time[102][102];

Node dp[102][102];

Node min(const Node &a, const Node &b) {
	if (a.cost == b.cost) return a.elapsed < b.elapsed ? a : b;
	return a.cost < b.cost ? a : b;
}

Node f(int head, int last) {
	if (dp[head][last].cost != -1) return dp[head][last];
	if (head == last) return {-2, 0};

	int prevhead = head + (head > last ? -1 : 1);

	Node a = f(prevhead, last);
	Node b = {-2, 0};
	if (a.cost != -2) b = {a.cost + a.elapsed + time[prevhead][head],
		a.elapsed + time[prevhead][head]};

	Node c = f(last, prevhead);
	Node d = {-2, 0};
	if (c.cost != -2) d = {c.cost + c.elapsed + time[last][head],
		c.elapsed + time[last][head]};

	Node result = min(b, d);
	if (b.cost == -2) result = d;
	if (d.cost == -2) result = b;

	return dp[head][last] = result;
}

int main() {
	scanf("%d", &T);

	while (T--) {
		scanf("%d", &N);
		scanf("%d", &S);
		for (int i = 1; i <= N - 1; i++) {
			int value;
			scanf("%d", &value);
			time[i][i + 1] = value;
			time[i + 1][i] = value;
		}

		for (int i = 1; i <= N - 1; i++) {
			for (int j = i + 1; j <= N; j++) {
				time[i][j] = time[i][j - 1] + time[j - 1][j];
				time[j][i] = time[i][j];
			}
		}

		memset(dp, -1, sizeof(dp));
		dp[S][S] = {0, 0};

		Node a = f(1, N);
		Node b = f(N, 1);

		long long result = min(a.cost, b.cost);
		if (b.cost == -2) result = a.cost;
		if (a.cost == -2) result = b.cost;

		printf("%lld\n", result);
	}

	return 0;
}
