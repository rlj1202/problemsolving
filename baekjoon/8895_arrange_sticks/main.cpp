#include <iostream>
#include <cstring>

using namespace std;

int T;

long long factorial[22];
long long comb[22][22];

int N, L, R;
long long dp[22][22];

long long f(int sticks, int visibles) {
	if (dp[sticks][visibles] != -1) return dp[sticks][visibles];

	if (visibles == 0) return sticks == 0;

	long long result = 0;

	for (int choose = 0; choose <= sticks - 1; choose++) {
		result +=
			comb[sticks - 1][choose]
			* factorial[choose]
			* f(sticks - choose - 1, visibles - 1);
	}

	return dp[sticks][visibles] = result;
}

int main() {
	scanf("%d", &T);

	factorial[0] = 1;
	for (int f = 1; f <= 20; f++)
		factorial[f] = factorial[f - 1] * f;

	comb[0][0] = 1;
	for (int a = 1; a <= 20; a++) {
		comb[a][0] = 1;
		for (int b = 1; b <= a; b++)
			comb[a][b] = comb[a - 1][b - 1] + comb[a - 1][b];
	}

	memset(dp, -1, sizeof(dp));

	while (T--) {
		scanf("%d %d %d", &N, &L, &R);

		long long result = 0;

		for (int sticks = 0; sticks <= N - 1; sticks++)
			result += f(sticks, L - 1) * f(N - 1 - sticks, R - 1) * comb[N - 1][sticks];

		printf("%lld\n", result);
	}

	return 0;
}
