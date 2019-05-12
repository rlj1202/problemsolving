#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int positions[1003];
int powers_sum[1003];

int dp[1003][1003];

int f(int head, int tail) {
	if (dp[head][tail] != 0) return dp[head][tail];

	int dir = head > tail ? 1 : -1;
	int unvisits = N - ((head - tail) * dir + 1);

	if (unvisits == 0) return 0;

	int l = min(head, tail);
	int r = max(head, tail);
	int actives = powers_sum[N] - (powers_sum[r] - powers_sum[l - 1]);

	int a = -1;
	if (1 <= tail - dir && tail - dir <= N) {
		a = f(tail - dir, head);
		int l = min(tail - dir, head);
		int r = max(tail - dir, head);
		int elapsed = positions[r] - positions[l];

		a += elapsed * actives;
	}

	int b = -1;
	if (1 <= head + dir && head + dir <= N) {
		b = f(head + dir, tail);
		int l = min(head, head + dir);
		int r = max(head, head + dir);
		int elapsed = positions[r] - positions[l];

		b += elapsed * actives;
	}

	int result;
	if (a == -1) result = b;
	else if (b == -1) result = a;
	else result = min(a, b);

	return dp[head][tail] = result;
}

int main() {
	scanf("%d %d", &N, &M);
	for (int n = 1; n <= N; n++) {
		scanf("%d %d", positions + n, powers_sum + n);
		powers_sum[n] += powers_sum[n - 1];
	}

	int result = f(M, M);
	printf("%d\n", result);

	return 0;
}
