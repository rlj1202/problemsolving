#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

struct Node { int m, M; };

Node compute(Node a, Node b) {
	return Node{min(a.m, b.m), max(a.M, b.M)};
}

int N;
Node arr[15][1003];

int dp[1003][1003];

Node query(int l, int r) {
	int tmp = r - l + 1;
	int log = 0;
	while ((tmp >>= 1) != 0) log++;
	int len = 1 << log;

	return compute(arr[log][l], arr[log][r - len + 1]);
}

int f(int l, int r) {
	if (dp[l][r] != -1) return dp[l][r];

	Node node = query(l, r);
	int result = node.M - node.m;
	for (int m = l + 1; m <= r - 2; m++) {
		result = max(result, f(l, m) + f(m + 1, r));
	}

	return dp[l][r] = result;
}

int main() {
	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		int value;
		scanf("%d", &value);
		arr[0][n] = {value, value};
	}

	int tmp = N;
	int log = 0;
	while ((tmp >>= 1) != 0) log++;

	for (int l = 1; l <= log; l++) {
		int prev = 1 << (l - 1);
		int len = 1 << l;

		for (int n = 0; n < N - len + 1; n++)
			arr[l][n] = compute(arr[l - 1][n], arr[l - 1][n + prev]);
	}

	memset(dp, -1, sizeof(dp));
	printf("%d\n", f(0, N - 1));

	return 0;
}
