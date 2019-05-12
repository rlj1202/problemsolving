#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int T;

int N, S;
int time[102][102];

long long dp[102][102];

long long f(int head, int tail) {
	if (dp[head][tail] != 0) return dp[head][tail];

	int dir = head > tail ? 1 : -1;
	long long unvisits = N - ((head - tail) * dir + 1);

	if (unvisits == 0) return 0;

	long long a = -1;
	if (1 <= tail - dir && tail - dir <= N) {
		a = f(tail - dir, head);
		a += time[head][tail - dir] * unvisits;
	}

	long long b = -1;
	if (1 <= head + dir && head + dir <= N) {
		b = f(head + dir, tail);
		b += time[head][head + dir] * unvisits;
	}

	long long result;
	if (a == -1) result = b;
	else if (b == -1) result = a;
	else result = min(a, b);

	return dp[head][tail] = result;
}

int main() {
	scanf("%d", &T);

	while (T--) {
		scanf("%d %d", &N, &S);
		for (int i = 1; i <= N - 1; i++) scanf("%d", &time[i][i + 1]);
		for (int i = 1; i <= N - 1; i++)
			for (int j = i + 1; j <= N; j++)
				time[j][i] = time[i][j] = time[i][j - 1] + time[j - 1][j];

		memset(dp, 0, sizeof(dp));
		long long result = f(S, S);
		
		printf("%lld\n", result);
	}

	return 0;
}
